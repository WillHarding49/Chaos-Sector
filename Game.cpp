#include <SFML/Graphics.hpp>

#include"CurvesAndPaths.h"
#include "Game.h"
#include "Settings.h"
#include "Helpers.h"
#include "Missile.h"

#if _DEBUG
#include <vld.h>
#endif

Game::Game()
	: m_context				( )
	, m_pWindow				( nullptr )
	, m_clock				( )
	, m_level				( 0 )
	, m_textureManager		( ) 
	, m_player				( m_textureManager.getTexture( "Player" ), Settings::k_playerScale, Settings::k_playerStartPos, Settings::k_playerSpeed, Settings::k_playerLives )
	, m_inputManager		( )
	, m_missileManager		( Settings::k_maxMissiles, m_textureManager.getTexture( "PlayerMissile" ), m_textureManager.getTexture( "EnemyMissile" ) )
	, m_fileManager			( )
	, m_enemyManager		( Settings::k_enemyGrid, Settings::k_enemyFromations[ m_level ], m_fileManager.getEnemyArrays()[ m_level ] )
	, m_bgMusic				( )
	, m_shootSFX			( )
	, m_diveSFX				( )
	, m_deathSFX			( )
	, m_menuText			( )
	, m_menuText2			( )
	, m_menuText3			( )
	, m_scoreText			( )
	, m_collisionManager	( )
	, m_background			( m_textureManager.getTexture( "Background" ), 4, 2.5f, 50.0f, sf::Vector2f( 0, -1 ) )
	, m_state				( GameStates::MainMenu )
	, m_score				( 0 )
	, m_leaderboard			( m_fileManager.getLeaderboard() )
	, m_sidebarBG			( )
{
	// Set seed for random so new random numbers are generated
	srand( static_cast< int >( time( 0 ) ) );

	// Make window
	m_pWindow = new sf::RenderWindow( sf::VideoMode( Settings::k_windowSize.x, Settings::k_windowSize.y ), "Chaos Sector" );

	// Set the framerate to 60 and turn on vsync
	m_pWindow->setFramerateLimit( Settings::k_framerate );
	m_pWindow->setVerticalSyncEnabled( true );

	// Set and play BGmusic
	m_bgMusic.load( Settings::k_bgMusic );
	m_bgMusic.setLoop( true );
	m_bgMusic.setVolume( 50 );
	m_bgMusic.play();

	// Set sounds for SFX
	m_shootSFX.load( Settings::k_shootSound );
	m_diveSFX.load( Settings::k_diveSound );
	m_deathSFX.load( Settings::k_deathSound );
	
	// Call this to set up menu text
	enterState();

	// Set sidebar to give backdrop for score etc. during gameplay
	m_sidebarBG.setPosition( static_cast< float >( Settings::k_playAreaSize.x ), 0 );
	m_sidebarBG.setSize( sf::Vector2f( static_cast< float >( Settings::k_windowSize.x - Settings::k_playAreaSize.x ), static_cast< float >( Settings::k_windowSize.y ) ) );
	m_sidebarBG.setFillColor( sf::Color::Black );

	// Set score text 
	m_scoreText.setFont( m_textureManager.getFont() );
	m_scoreText.setString( "Score:\n" + std::to_string( m_score ) );
	m_scoreText.setCharacterSize( 20 );
	m_scoreText.setPosition( static_cast<float>( Settings::k_playAreaSize.x + m_sidebarBG.getGlobalBounds().width * 0.25f ), m_scoreText.getGlobalBounds().height * 2 );

}

Game::~Game()
{
	safeDeletePointer( m_pWindow );
}

void Game::handleWindowsEvents()
{
	sf::Event event;

	// While there's an event happening
	while( m_pWindow->pollEvent( event ) )
	{
		// If the event is to close the window
		if( event.type == sf::Event::Closed )
		{
			// Close the window
			m_pWindow->close();
		}

		// Static string to catch the typed text
		static std::string text;

		// If the game is in the gameOver state
		if( m_state == GameStates::GameOver )
		{
			// If text is being entered
			if( event.type == sf::Event::TextEntered )
			{
				// If the key is backspace and the text size isn't 0
				if( event.text.unicode == 0x08 and text.size() != 0 )
				{
					// Remove the last character
					text.pop_back();
				}

				// If the key isn't backspace or spacebar
				else if( event.text.unicode != 0x08 && event.text.unicode != 0x20 )
				{
					// Add the typed text to the text string
					text += event.text.unicode;
				}

				// Set the GameText to the typed string
				m_menuText3.setString( text );
			}
		}
		else
		{
			// Reset text outside of game win screen
			text = "";
		}
	}
}


void Game::run()
{
	float deltaTime = 0.0f;
	
	// Reset clock so deltaTime can be as accurate as possible
	m_clock.restart();

	while( m_pWindow->isOpen() )
	{	
		// Get elasped time since restart in seconds
		deltaTime = m_clock.restart().asSeconds();
		
		// Handle all Windows events
		handleWindowsEvents();

		// Clear the Screen
		m_pWindow->clear();

		// Update all objects
		update( deltaTime );

		// Render all objects
		render();

		// Display all rendered objects
		m_pWindow->display();
	}
}

void Game::changeState( GameStates state )
{
	// Call leaving state function
	leaveState();

	// Change the state
	m_state = state;

	// Call the entering state function with new state
	enterState();

}

void Game::enterState()
{
	switch( m_state )
	{
		case GameStates::MainMenu: 
		{
			// Set menu text
			m_menuText.setFont( m_textureManager.getFont() );
			m_menuText.setString( "Chaos Sector" );
			m_menuText.setCharacterSize( 40 );
			m_menuText.setPosition( Settings::k_windowSize.x * 0.5f - m_menuText.getGlobalBounds().width * 0.5f, Settings::k_windowSize.y * 0.1666f + m_menuText.getGlobalBounds().height * 0.5f );

			m_menuText2.setFont( m_textureManager.getFont() );
			m_menuText2.setString( "Press Space To Play" );
			m_menuText2.setCharacterSize( 20 );
			m_menuText2.setPosition( Settings::k_windowSize.x * 0.5f - m_menuText2.getGlobalBounds().width * 0.5f, Settings::k_windowSize.y * 0.8333f + m_menuText2.getGlobalBounds().height * 0.5f );


			// Start of highscore text
			std::string highscoreText = "Highscores:\n\n";

			// Dashes to put between score and name
			std::string dash = "---";

			// Loop through all the leaderboard entries
			for( int i = 0; i < static_cast< int >( m_leaderboard.size() ); i++ )
			{
				// For the number of digits that the score is short by compared to the max
				for( int j = 0; j < Settings::k_leaderboardDigits - std::to_string( m_leaderboard[ i ].first ).length(); j++ )
				{
					// Add a - before the name so it lines up right when displayed
					dash += "-";
				}

				highscoreText += std::to_string( m_leaderboard[ i ].first ) + dash + m_leaderboard[ i ].second + "\n";
				dash = "---";
			}

			// Set high score leaderboard text
			m_menuText3.setFont( m_textureManager.getFont() );
			m_menuText3.setString( highscoreText );
			m_menuText3.setCharacterSize( 20 );
			m_menuText3.setPosition( 0, 0 );
			m_menuText3.setPosition( Settings::k_windowSize.x * 0.5f - m_menuText3.getGlobalBounds().width * 0.5f, Settings::k_windowSize.y * 0.333f );// +m_menuText3.getGlobalBounds().height * 0.5f );

		}
		break;
		
		case GameStates::Gameplay:
		{

		}
		break;
		
		case GameStates::GameOver:
		{
			// Set Game Over text
			m_menuText.setString( "Game Over" );
			m_menuText.setCharacterSize( 20 );
			m_menuText.setPosition( Settings::k_windowSize.x * 0.5f - m_menuText.getGlobalBounds().width * 0.5f, Settings::k_windowSize.y * 0.333f + m_menuText.getGlobalBounds().height * 0.5f );
			
			m_menuText2.setString( "Type your name for the leaderboard, press Enter to proceed:" );
			m_menuText2.setCharacterSize( 20 );
			m_menuText2.setPosition( Settings::k_windowSize.x * 0.5f - m_menuText2.getGlobalBounds().width * 0.5f, Settings::k_windowSize.y * 0.5f + m_menuText2.getGlobalBounds().height * 0.5f );

			// Set blank string for this text as this will display the text entry
			m_menuText3.setString( " " );
			m_menuText3.setCharacterSize( 20 );
			m_menuText3.setPosition( Settings::k_windowSize.x * 0.5f - m_menuText2.getGlobalBounds().width * 0.5f, Settings::k_windowSize.y * 0.666f + m_menuText2.getGlobalBounds().height * 0.5f );
		}
		break;

		case GameStates::GameWin:
		{
			// Set Game Win text
			m_menuText.setString( "You Win!" );
			m_menuText.setCharacterSize( 40 );
			m_menuText.setPosition( Settings::k_windowSize.x * 0.5f - m_menuText.getGlobalBounds().width * 0.5f, Settings::k_windowSize.y * 0.333f + m_menuText.getGlobalBounds().height * 0.5f );


			m_menuText2.setString( "Press enter to Proceed" );
			m_menuText2.setCharacterSize( 20 );
			m_menuText2.setPosition( Settings::k_windowSize.x * 0.5f - m_menuText2.getGlobalBounds().width * 0.5f, Settings::k_windowSize.y * 0.5f + m_menuText2.getGlobalBounds().height * 0.5f );

		}
		break;
		
		default:
		{
			
		}
		break;
	}
}

void Game::leaveState()
{
	switch( m_state )
	{
		case GameStates::MainMenu:
		{
			// Reset game with default number of player lives
			reset( Settings::k_playerLives );
		}
		break;

		case GameStates::Gameplay:
		{

		}
		break;

		case GameStates::GameOver:
		{
			// Add new high score to leaderboard
			m_leaderboard.push_back( std::make_pair( m_score, m_menuText3.getString() ) );

			// Sort leaderboard by descending score
			std::sort( m_leaderboard.begin(), m_leaderboard.end(), std::greater<>() );

			// If the leaderboard is greater than the max size it can be
			if( m_leaderboard.size() > Settings::k_leaderboardMaxLength )
			{
				// Resize to the max length
				m_leaderboard.resize( Settings::k_leaderboardMaxLength );
			}

			// Update leaderboard file
			m_fileManager.setLeaderboard( m_leaderboard );

			// Reset level and score counter
			m_level = 0;
			m_score = 0;
		}
		break;

		case GameStates::GameWin:
		{
			// Increase level
			m_level++;

			// If level has overflowed
			if( m_level == Settings::k_levelAmount )
			{
				// Set level back to 0
				m_level = 0;
			}

			// Reset game with +1 lives
			reset( m_player.getLives() + 1 );
		}
		break;

		default:
		{

		}
		break;
	}
}

void Game::reset( int numLives )
{
	// Get entrance paths
	std::vector<std::vector<std::vector<sf::Vector2f>>> entrances = EntrancePaths::k_levelEntranceLists[ m_level ];

	// Make new enemy array
	m_enemyManager.makeNewLevel( Settings::k_enemyGrid, Settings::k_enemyFromations[ m_level ],  m_fileManager.getEnemyArrays()[ m_level ], m_textureManager, entrances );
	
	// Reset missiles
	m_missileManager.reset();

	// reset player
	m_player.reset( Settings::k_playerStartPos, numLives );
}

void Game::update( float deltaTime )
{
	// Always update background as it appears on all screens
	m_background.update( deltaTime );

	switch( m_state )
	{
		default:
		case GameStates::MainMenu:
		{
			// Play game on spacebar press
			if( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ) )
			{
				changeState( GameStates::Gameplay );
			}

			// Rainbow colour change for Title
			m_menuText.rainbowLerp( deltaTime );

		}
		break;

		case GameStates::Gameplay:
		{
			// Update enemies
			m_enemyManager.update( m_player.getPosition(), m_missileManager, m_diveSFX, deltaTime );

			// Check for inputs for the player
			m_inputManager.checkPlayerInputs( m_player, m_missileManager, m_shootSFX, deltaTime );

			// Update player
			m_player.update( deltaTime );

			// Update missiles
			m_missileManager.update( deltaTime );

			// Logic for gameplay
			updateGamePlay( deltaTime );
		}
		break;

		case GameStates::GameOver:
		{
			m_menuText2.setPosition( Settings::k_windowSize.x * 0.5f - m_menuText2.getGlobalBounds().width * 0.5f, Settings::k_windowSize.y * 0.5f + m_menuText2.getGlobalBounds().height * 0.5f );
			m_menuText3.setPosition( Settings::k_windowSize.x * 0.5f - m_menuText3.getGlobalBounds().width * 0.5f, Settings::k_windowSize.y * 0.666f + m_menuText3.getGlobalBounds().height * 0.5f );
			
			if( sf::Keyboard::isKeyPressed( sf::Keyboard::Return ) )
			{
				changeState( GameStates::MainMenu );
			}

			m_menuText.rainbowLerp( deltaTime );

		}
		break;

		case GameStates::GameWin:
		{
			//m_menuText.setString( "You Win! Press enter to continue!" );

			if( sf::Keyboard::isKeyPressed( sf::Keyboard::Return ) )
			{
				changeState( GameStates::Gameplay );
			}

			m_menuText.rainbowLerp( deltaTime );

		}
		break;
	}

}

void Game::updateGamePlay( const float& deltaTime )
{
	// Bool for if the player has been hit, can reset each frame
	bool playerHit = false;

	// Bool for if the player is invincible, use for timer so must be static
	static bool invincible = false;

	// If the player is not invincible and collides with an enemy
	if( !invincible && m_collisionManager.checkEnemyPlayerCollisions( m_enemyManager, m_player ) )
	{
		// Player has been hit
		playerHit = true;

		// Increase score as an enemy dies
		m_score += 100;

		// Play death SFX
		m_deathSFX.play();
	}

	// Loop through missiles
	for( int i = 0; i < m_missileManager.getMaxPoolSize(); i++ )
	{
		// If the missile is active
		if( m_missileManager.getPool()[ i ].getActive() )
		{
			// If the player is not invincible and collides with an enemy projectile
			if( !invincible && m_collisionManager.checkPlayerProjectileCollisions( m_missileManager.getPool()[ i ], m_player ) )
			{
				// Player has been hit
				playerHit = true;

				// Play death SFX
				m_deathSFX.play();
			}

			// If an enemy collides with a player projectile
			if( m_collisionManager.checkEnemyProjectileCollisions( m_missileManager.getPool()[ i ], m_enemyManager ) )
			{
				//score increase
				m_score += 100;

				// Play death SFX
				m_deathSFX.play();
			}
		}
	}


	// If the player was hit
	if( playerHit )
	{
		// Reduce number of lives the player has
		m_player.reduceLives();

		// Set invincible to true
		invincible = true;

		// If the player has 0 lives left
		if( m_player.getLives() == 0 )
		{
			// Game Over
			changeState( GameStates::GameOver );
		}
	}

	// Timer float
	static float invincibleTimer = 0.0f;
	
	// If the player is invincible
	if( invincible )
	{
		// Change transparency every 0.01 seconds
		// The timer * 100 will give an integer, bitwise AND for even numbers
		if( ( static_cast< int >( invincibleTimer * 100 ) & 1 ) == 0 )
		{
			// Texture colour is white for normal colour
			m_player.setColor( sf::Color::White );
		}
		else
		{
			// Set texture to transparent
			m_player.setColor( sf::Color::Transparent );
		}

		// Increase timer
		invincibleTimer += deltaTime;

		// If timer is >= the amount of time for invincibility
		if( invincibleTimer >= Settings::k_invincibilityTime )
		{
			// Reset timer
			invincibleTimer = 0;

			// Make sure player is visable
			m_player.setColor( sf::Color( 255, 255, 255, 255 ) );

			// Reset invincible bool
			invincible = false;
		}
	}

	// Set score string to update with score, level, and lives
	m_scoreText.setString( "Score:\n" + std::to_string( m_score ) + "\n\n\n\n\nLives:\n" + std::to_string( m_player.getLives() ) + "\n\n\n\n\nLevel:\n" + std::to_string( m_level ) );


	// If all the enemies are dead
	if( m_enemyManager.checkAllEnemiesDead() )
	{
		// Game Win
		changeState( GameStates::GameWin );
	}
}

void Game::render()
{
	// Draw background on every state
	m_pWindow->draw( m_background );


	switch( m_state )
	{
		default:
		case GameStates::MainMenu:
		{
			// Draw menu texts
			m_pWindow->draw( m_menuText );
			m_pWindow->draw( m_menuText2 );
			m_pWindow->draw( m_menuText3 );
		}
		break;

		case GameStates::Gameplay:
		{
			// Draw sidebar first so everything is on top
			m_pWindow->draw( m_sidebarBG );

			// Draw player
			m_pWindow->draw( m_player );

			// Draw all missiles
			m_missileManager.render( *m_pWindow );

			// Draw enemeis
			m_enemyManager.render( *m_pWindow );

			// Draw score text
			m_pWindow->draw( m_scoreText );

		}
		break;

		case GameStates::GameOver:
		{
			// Draw game over texts
			m_pWindow->draw( m_menuText );
			m_pWindow->draw( m_menuText2 );
			m_pWindow->draw( m_menuText3 );
		}
		break;

		case GameStates::GameWin: 
		{
			// Draw game win texts
			m_pWindow->draw( m_menuText );
			m_pWindow->draw( m_menuText2 );
		}
		break;
	}



}