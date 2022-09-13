#include "AlienRing.h"
#include "AlienSphere.h"
#include "AlienUFO.h"
#include"CurvesAndPaths.h"
#include "EnemyManager.h"
#include "Helpers.h"
#include "Settings.h"

EnemyManager::EnemyManager()
	: m_activeFormation		( 0 )
	, m_levelArray			( Settings::k_defaultEnemyArray )
	, m_arraySize			( Settings::k_enemyGrid )
	, m_formationSize		( Settings::k_enemyFromations[ Settings::k_levelAmount - 1 ] )
	, m_enemyTimer			( 0 )
	, m_formationComplete	( true )
	, m_state				( EnemyManagerStates::Entrances )
	, m_entracePaths		( EntrancePaths::k_level0Entrances )
{
	// Make enemies array row * column big so it can hold all the enemies
	m_pEnemyArray.assign( m_arraySize.x * m_arraySize.y, new Enemy() );

	// Make the indexes vector contain the row number of vectors, with nothing in so the indexes can be pushed back
	m_formationIndexes.assign( m_formationSize.x, std::vector<int>( 0 ) );
}

EnemyManager::EnemyManager( const sf::Vector2i& arraySize, const sf::Vector2i& formationSize, const std::string& arrayTemplate )
	: m_activeFormation( 0 )
	, m_levelArray( arrayTemplate )
	, m_arraySize( arraySize )
	, m_formationSize( formationSize )
	, m_enemyTimer( 0 ) 
	, m_formationComplete( true )
	, m_state( EnemyManagerStates::Entrances )
	, m_entracePaths( EntrancePaths::k_level0Entrances )
{
	// Make enemies array row * column big so it can hold all the enemies
	m_pEnemyArray.assign( m_arraySize.x * m_arraySize.y, nullptr );

	// Make the indexes vector contain the row number of vectors, with nothing in so the indexes can be pushed back
	m_formationIndexes.assign( m_formationSize.x, std::vector<int>( 0 ) );
}

EnemyManager::~EnemyManager()
{
	for( int i = 0; i < m_arraySize.x * m_arraySize.y; i++ )
	{
		safeDeletePointer( m_pEnemyArray[ i ] );
	}
}

const int EnemyManager::getArraySize() const
{
	return m_arraySize.x * m_arraySize.y;
}

std::vector<Enemy*>& EnemyManager::getArray()
{
	return m_pEnemyArray;
}

void EnemyManager::makeNewLevel( const sf::Vector2i& arraySize, const sf::Vector2i& formationSize, std::string& levelArray, TextureManager& textureManager, std::vector<std::vector<std::vector<sf::Vector2f>>>& entrancePaths )
{
	// Delete all the enemies in the array
	for( int i = 0; i < m_arraySize.x * m_arraySize.y; i++ )
	{
		safeDeletePointer( m_pEnemyArray[ i ] );
	}

	// Set new sizes
	m_arraySize = arraySize;
	m_formationSize = formationSize;

	// Clear the enemy array to ensure it's empty
	m_pEnemyArray.clear();

	// Assign new nullptrs for the neeeded space in the vector
	m_pEnemyArray.assign( m_arraySize.x * m_arraySize.y, nullptr );

	// Resize the vector so it's only as big as it needs to be
	m_pEnemyArray.resize( m_arraySize.x * m_arraySize.y );

	// Clear formation indexes
	m_formationIndexes.clear();

	// Assign new vector<int>s to the vetctor so it can be filled later
	m_formationIndexes.assign( m_formationSize.x, std::vector<int>( 0 ) );

	// Set the level array
	m_levelArray = levelArray;

	// Make the enemy array
	makeArray( textureManager );
	
	// Set the other values to their original states
	m_state = EnemyManagerStates::Entrances;
	m_activeFormation = 0;
	m_formationComplete = true;
	m_entracePaths = entrancePaths;
}

bool EnemyManager::checkAllEnemiesDead()
{
	// All enemies are dead unless one is alive
	bool dead = true;

	for( int i = 0; i < m_arraySize.x * m_arraySize.y; i++ )
	{	
		// If an enemy is alive, then they are not all dead, so set the bool to false and break
		if( m_pEnemyArray[ i ] != nullptr && m_pEnemyArray[ i ]->getActive() )
		{
			dead = false;
			break;
		}
	}

	return dead;
}

void EnemyManager::makeArray( TextureManager& textureManager )
{
	// column and row index for enemy array
	int column = 0;
	int row = 0;

	// Loop through each character in the level string
	for( int i = 0; i < static_cast< int >( m_levelArray.length() ); i++ )
	{
		// Change the current character to a char so it can be switched on
		char letter = m_levelArray[ i ];

		// index is the position in the array where the enemy is to be placed
		int index = row * m_arraySize.x + column;

		switch( letter )
		{
			case 'x':
			{
				// x represents a gap in the array formation, so set this to a nullptr
				m_pEnemyArray[ index ] = nullptr;
				column++;
			}
			break;

			// For char A, representing UFO enemies
			case 'A':
			{
				// a number char - '0' will be an integer
				// levelArray[ i + 1 ] will be the next char in the string, so the formation number after the letter representing an enemy
				int formation = m_levelArray[ i + 1 ] - '0';

				// Set enemy at the index to be an AlienUFO
				m_pEnemyArray[ index ] = new AlienUFO();

				// Set positions and textures
				m_pEnemyArray[ index ]->setPosition( Settings::k_outOfBoundsPos );
				m_pEnemyArray[ index ]->setDefultPos( sf::Vector2f( ( column * Settings::k_enemyArraySpaceMultiplier ) + Settings::k_enemyArraySpacing.x,
																	( row * Settings::k_enemyArraySpaceMultiplier ) + Settings::k_enemyArraySpacing.y ) );
				m_pEnemyArray[ index ]->setTexture( textureManager.getTexture( "AlienUFO" ) );

				// Add the array index of this enemy to the formation vector
				m_formationIndexes[ formation - 1 ].push_back( index );
				column++;

			}
			break;

			case 'B':
			{
				// a number char - '0' will be an integer
				// levelArray[ i + 1] will be the next char in the string, so the formation number after the letter representing an enemy
				int formation = m_levelArray[ i + 1 ] - '0';

				// Set enemy at the index to be an AlienSphere
				m_pEnemyArray[ index ] = new AlienSphere();

				// Set positions and textures
				m_pEnemyArray[ index ]->setPosition( Settings::k_outOfBoundsPos );
				m_pEnemyArray[ index ]->setDefultPos( sf::Vector2f( ( column * Settings::k_enemyArraySpaceMultiplier ) + Settings::k_enemyArraySpacing.x,
																	( row * Settings::k_enemyArraySpaceMultiplier ) + Settings::k_enemyArraySpacing.y ) );
				m_pEnemyArray[ index ]->setTexture( textureManager.getTexture( "AlienSphere" ) );

				// Add the array index of this enemy to the formation vector
				m_formationIndexes[ formation - 1 ].push_back( index );
				column++;
			}
			break;

			case 'C':
			{
				// a number char - '0' will be an integer
				// levelArray[ i + 1] will be the next char in the string, so the formation number after the letter representing an enemy
				int formation = m_levelArray[ i + 1 ] - '0';

				// Set enemy at the index to be an AlienRing
				m_pEnemyArray[ index ] = new AlienRing();

				// Set positions and textures
				m_pEnemyArray[ index ]->setPosition( Settings::k_outOfBoundsPos );
				m_pEnemyArray[ index ]->setDefultPos( sf::Vector2f( ( column * Settings::k_enemyArraySpaceMultiplier ) + Settings::k_enemyArraySpacing.x,
																	( row * Settings::k_enemyArraySpaceMultiplier ) + Settings::k_enemyArraySpacing.y ) );
				m_pEnemyArray[ index ]->setTexture( textureManager.getTexture( "AlienRing" ) );

				// Add the array index of this enemy to the formation vector
				m_formationIndexes[ formation - 1 ].push_back( index );
				column++;
			}
			break;

			// For new lines, this means a new row of enemies
			case '\n':
			{
				row++;
				column = 0;
			}
			break;
		}
	}
}

bool EnemyManager::checkFormationCompleteEntrance()
{
	// Loop through 1 entrance group of enemies
	for( int i = 0; i < m_formationSize.y; i++ )
	{
		// If the enemy is not a nullptr and is active and in the main formation, meaning its finished it's entrance
		if( m_pEnemyArray[ m_formationIndexes[ m_activeFormation - 1 ][ i ] ] != nullptr &&
			m_pEnemyArray[ m_formationIndexes[ m_activeFormation - 1 ][ i ] ]->getActive() &&
			m_pEnemyArray[ m_formationIndexes[ m_activeFormation - 1 ][ i ] ]->getState() == EnemyStates::Formation )
		{
			// The enemy has made it's entrance so set to true
			m_formationComplete = true;
		}

		// If the enemy is not a nullptr but has died, meaning it has "finished" its entrance
		else if( m_pEnemyArray[ m_formationIndexes[ m_activeFormation - 1 ][ i ] ] != nullptr &&
				 !( m_pEnemyArray[ m_formationIndexes[ m_activeFormation - 1 ][ i ] ]->getActive() ) )
		{
			// The enemy has made it's entrance so set to true
			m_formationComplete = true;
		}

		// If an enemy is alive and hasn't finished it's entrance dive
		else
		{
			// The entrance group has NOT made it's entrance so set to false
			m_formationComplete = false;
			
			// Break out of the loop to avoid false positives
			break;
		}
	}

	// If the last formation has finished it's entrance
	if( m_activeFormation == m_formationSize.x && m_formationComplete )
	{
		// Stop trying to send new formations in and stops the final one looping
		m_formationComplete = false;

		// Chnage state to attack
		m_state = EnemyManagerStates::Attack;
	}


	return m_formationComplete;
}

void EnemyManager::sendOutFormations( const float& deltaTime )
{
	// Index for enemy in intro formation array
	static int index = 0;

	// If an enemy has just been sent out
	static bool sent = false; 

	// When an enemy needs to be sent out
	if( !sent )
	{
		// For the first formation which splits into 2
		if( m_activeFormation == 0 )
		{
			// Bitwise AND the bits to get even numbers
			if( index & 1 )
			{
				// Set path for this half of the 1st entrance formation, which is the 2nd in the list
				m_pEnemyArray[ m_formationIndexes[ m_activeFormation ][ index ] ]->setPath( m_entracePaths[ 1 ] );
			}
			else
			{	
				// Set path for this half of the 1st entrance formation, which is the 1st in the list
				m_pEnemyArray[ m_formationIndexes[ m_activeFormation ][ index ] ]->setPath( m_entracePaths[ 0 ] );
			}

		}
		else
		{
			// Set path for this entrance formation, which is the 3rd+ in the list
			m_pEnemyArray[ m_formationIndexes[ m_activeFormation ][ index ] ]->setPath( m_entracePaths[ m_activeFormation + 1 ] );
		}

		// enemy is sent so bool is true
		sent = true;

		// Set the enemy's state to be entrance so it does its entrance dive
		m_pEnemyArray[ m_formationIndexes[ m_activeFormation ][ index ] ]->setState( EnemyStates::Entrance );
	}

	// When an enemy has just been sent out
	else
	{
		// Increase timer
		m_enemyTimer += deltaTime;

		// If the timer is >= the enemy send out delay
		if( m_enemyTimer >= Settings::k_enemyFormationDelay )
		{
			// Reset values
			sent = false;
			m_enemyTimer = 0;

			// Increase index if not overflow
			if( index < m_formationSize.y - 1 )
			{
				index++;
			}
			
			// When all the enemies have been sent from that formation
			else
			{
				// Increase activeFormation if not overflow
				if( m_activeFormation < m_formationSize.x )
				{
					m_activeFormation++;
				}

				// Reset index
				index = 0;

				// Set to false so each formation goes one formation at a tme
				m_formationComplete = false;
			}
		}
	}
}

void EnemyManager::update( const sf::Vector2f& playerPos, ProjectilePool& missilePool, GameSound& diveSound, const float& deltaTime )
{
	// Loop through enemy array
	for( int i = 0; i < m_arraySize.x * m_arraySize.y; i++ )
	{
		// If enemy is not nullptr and active
		if( m_pEnemyArray[ i ] != nullptr && m_pEnemyArray[ i ]->getActive() )
		{
			// Update enemy
			m_pEnemyArray[ i ]->update( deltaTime, playerPos, missilePool );
		}
	}

	// BSool for if an enemy has dived
	static bool enemyDived = true; 

	switch( m_state )
	{
		case EnemyManagerStates::Entrances: 
		{
			// If the formation has reached it's the main array
			if( m_formationComplete )
			{
				// Send out the next entrance formation
				sendOutFormations( deltaTime );
			}
			else
			{
				// Check if the current formation has fininished their entrance
				checkFormationCompleteEntrance();
			}
		}
		break;
		
		default:
		case EnemyManagerStates::Attack:
		{
			// If an enemy needs to dive
			if( !enemyDived )
			{
				// Get a random enemy from the array
				int index = rand() % ( m_arraySize.x * m_arraySize.y );

				// If that enemy is not nullptr and active, so it can dive
				if( m_pEnemyArray[ index ] != nullptr && m_pEnemyArray[ index ]->getActive() )
				{
					// Choose a random dive path
					int randNum = rand() % DivePaths::k_diveListSize;

					// Assign that dive path to the enemy
					m_pEnemyArray[ index ]->setPath( DivePaths::k_diveList[ randNum ] );

					// Make enemy dive
					m_pEnemyArray[ index ]->setState( EnemyStates::Dive );

					// Set bool to true so there is a delay between diving enemies
					enemyDived = true;

					// Play dive SFX
					diveSound.play();
				}
			}

			// If an enemy is diving
			else
			{
				// Increase timer
				m_enemyTimer += deltaTime;


				// If timer is >= dive delay
				if( m_enemyTimer >= Settings::k_enemyDiveDelay )
				{
					// Set bool to set another enemy to dive
					enemyDived = false;

					// Reset timer
					m_enemyTimer = 0.0f;
				}

			}
		}
		break;
		
		case EnemyManagerStates::Idle:
		{

		}
		break;
	}

}

void EnemyManager::render( sf::RenderWindow& window )
{
	// Loop through enemy array
	for( int i = 0; i < m_arraySize.x * m_arraySize.y; i++ )
	{
		// If enemy is not nullptr and active
		if( m_pEnemyArray[ i ] != nullptr && m_pEnemyArray[ i ]->getActive() )
		{
			// Render enemy
			window.draw( *m_pEnemyArray[ i ] );
		}
	}
}