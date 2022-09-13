#include"CurvesAndPaths.h"
#include "Enemy.h"
#include "Helpers.h"
#include "Settings.h"

Enemy::Enemy()
	: MoveableGameSprite	(  )
	, m_curveMove			( 0 )
	, m_lerpMove			( 0 )
	, m_defaultPos			( 0, 0 )
	, m_state				( EnemyStates::Idle )
	, m_path				( EntrancePaths::k_halfHeartLeftEnter )
	, m_pathNode			( 0 )
	, m_shotDelay			( static_cast< float >( rand() % Settings::k_enemyShootDelay.x + Settings::k_enemyShootDelay.y ) )
	, m_shotTimer			( 0.0f )
	, m_dived				( false )
	, m_setPlayerDirection	( false )
{
	setSpeed( Settings::k_enemySpeed );

	// Scales and positions enemy
	scale( Settings::k_enemyScale );
	setPosition( Settings::k_outOfBoundsPos );
}

Enemy::Enemy( sf::Texture& texture, sf::Vector2f& scale, sf::Vector2f& pos, sf::Vector2f& defaultPos, float speed, const std::vector<std::vector<sf::Vector2f>>& path )
	: MoveableGameSprite	( speed, pos, texture, scale )
	, m_curveMove			( 0 )
	, m_lerpMove			( 0 )
	, m_defaultPos			( defaultPos )
	, m_state				( EnemyStates::Idle )
	, m_path				( path )
	, m_pathNode			( 0 )
	, m_shotDelay			( static_cast< float >( rand() % Settings::k_enemyShootDelay.x + Settings::k_enemyShootDelay.y ) )
	, m_shotTimer			( 0.0f )
	, m_dived				( false )
	, m_setPlayerDirection	( false )
{

}


Enemy::~Enemy()
{

}

void Enemy::setDefultPos( const sf::Vector2f& pos )
{
	m_defaultPos = pos;
}

const sf::Vector2f& Enemy::getDefultPos()
{
	return m_defaultPos;
}

void Enemy::setState( const EnemyStates& state )
{
	m_state = state;
}

const EnemyStates& Enemy::getState()
{
	return m_state;
}

void Enemy::setPath( const std::vector<std::vector<sf::Vector2f>>& path )
{
	m_path = path;
}

const std::vector<std::vector<sf::Vector2f>>& Enemy::getPath()
{
	return m_path;
}

void Enemy::setDived( const bool& dived )
{
	m_dived = dived;
}

const bool& Enemy::getDived()
{
	return m_dived;
}

void Enemy::bezierCurveMove( const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3, const float& deltaTime )
{
	// Chord is distance between first and last points
	float chord = Math::vectorDistance( p0, p3 );

	// Get distances between nodes
	float a = Math::vectorDistance( p0, p1 );
	float b = Math::vectorDistance( p1, p2 );
	float c = Math::vectorDistance( p2, p3 );

	// Control net sides is the sum length between nodes
	float controlNetSides = a + b + c;

	// Approx. curve length is the sum of the control net sides and the chord / 2
	float curvelength = ( controlNetSides + chord ) * 0.5f;

	// m_curveMove is the speed * deltaTime /curvelength
	// This gives the % acorss the curve to move each frame to keep a consistent speed across the whole path
	m_curveMove += ( getSpeed() * deltaTime ) / curvelength;

	if( m_curveMove > 1 )
	{
		m_curveMove = 1;
	}

	// Set position to be point on cuve at curvemove
	setPosition( Math::CubicBezier( p0, p1, p2, p3, m_curveMove ) );
}

void Enemy::bezierCurveMove( const sf::Vector2f* points, const float& deltaTime )
{
	// Chord is distance between first and last points
	float chord = Math::vectorDistance( points[0], points[3] );

	// Get distances between nodes
	float a = Math::vectorDistance( points[ 0 ], points[ 1 ] );
	float b = Math::vectorDistance( points[ 1 ], points[ 2 ] );
	float c = Math::vectorDistance( points[ 2 ], points[ 3 ] );

	//float controlNetSides = Math::vectorDistance( a, b ) + Math::vectorDistance( b, c ) + Math::vectorDistance( c, d );
	float controlNetSides = a + b + c;

	// Control net sides is the sum length between nodes
	float curvelength = ( controlNetSides + chord ) * 0.5f;

	// m_curveMove is the speed * deltaTime /curvelength
	// This gives the % acorss the curve to move each frame to keep a consistent speed across the whole path
	m_curveMove += ( getSpeed() * deltaTime ) / curvelength;

	if( m_curveMove > 1 )
	{
		m_curveMove = 1;
	}

	// Set position to be point on cuve at curvemove
	setPosition( Math::CubicBezier( points, m_curveMove ) );
}

void Enemy::pathMove( const float& deltaTime )
{
	int x = m_pathNode;

	// At the 1st node
	if( x == 0 )
	{
		// If you're diving, this is the holder value for your default pos
		if( m_path[ x ][ 0 ] == sf::Vector2f( -1, -1 ) )
		{
			setPosition( m_defaultPos );
			m_pathNode++;
			m_lerpMove = 0;
		}
		else
		{
			// Teleport to that position as that is the starting point, otherwise enemy physically moves there across the screen
			setPosition( m_path[ x ][ 0 ] );
			m_pathNode++;
			m_lerpMove = 0;
		}
	}

	// If node only contains 1 vector, then it is a point to lerp towards
	else if( static_cast< int >( m_path[ x ].size() ) == 1 )
	{
		
		// If you have not finished lerping
		if( m_lerpMove < 1.0f )
		{
			// Dive from defualt pos
			if( m_path[ x - 1][ 0 ] == sf::Vector2f( -1, -1 ) )
			{
				lerpMove( m_defaultPos, m_path[ x ][ 0 ], deltaTime );
			}
			else
			{
				// lerp to the position from the last pos in the path
				lerpMove( m_path[ x - 1 ].back(), m_path[ x ][ 0 ], deltaTime );
			}
		}
	}

	// If node contains more than 1 vector, it is a series of points on a bezier curve
	else
	{
		// If not finished moving on curve
		if( m_curveMove < 1 )
		{
			// move across curve
			bezierCurveMove( m_path[ x ][ 0 ], m_path[ x ][ 1 ], m_path[ x ][ 2 ], m_path[ x ][ 3 ], deltaTime );
		}
	}

	if( m_curveMove >= 1.0f || m_lerpMove >= 1.0f )
	{
		if( m_pathNode < static_cast< int >( m_path.size() ) - 1 )
		{
			m_pathNode++;
		}

		// At end of path
		else
		{
			// Reset node index
			m_pathNode = 0;

			if( m_state == EnemyStates::Dive )
			{
				m_dived = true;
			}
			else
			{
				// Once entrance path is finisehed, change state to formation
				m_state = EnemyStates::Formation;
			}
		}

		// Reset lerpMove and curveMove after every finished lerp or curve
		m_lerpMove = 0;
		m_curveMove = 0;
	}
}

void Enemy::update( const float& deltaTime, const sf::Vector2f& playerPos, ProjectilePool& missilePool )
{
	switch( m_state )
	{
		case EnemyStates::Entrance: 
		{
			// Move across entrance path
			pathMove( deltaTime );
		}
		break;
		
		case EnemyStates::Formation: 
		{
			// Move to default position from last path position in lerp if not already there
			if( getPosition() != m_defaultPos )
			{
				lerpMove( m_path[ m_path.size() - 1][ 0 ], m_defaultPos, deltaTime );
			}

			// Increase shot timer
			m_shotTimer += deltaTime;

			if( m_shotTimer >= m_shotDelay )
			{
				// Get vector from enemy to player
				sf::Vector2f playerAngle = Math::normalise( sf::Vector2f( playerPos.x - getPosition().x, playerPos.y - getPosition().y ) );

				// Fire projectile from enemy pos, towards the player, and set PlayerShot to false
				missilePool.fireProjectile( getPosition(), playerAngle, false );

				// Reset shot timer
				m_shotTimer = 0;

				// Make a new random shot delay 
				m_shotDelay = static_cast< float >( rand() % Settings::k_enemyShootDelay.x + Settings::k_enemyShootDelay.y );
			}
			

		}
		break;
		
		case EnemyStates::Dive:
		{
			// If the enemy has just finished its dive
			if( !m_setPlayerDirection && m_dived )
			{
				// Set the direction to be towards the player
				setDirection( Math::normalise( sf::Vector2f( playerPos.x - getPosition().x, playerPos.y - getPosition().y ) ) );

				// set to true so the enemy doesn't actively hunt the player fully
				m_setPlayerDirection = true;
			}

			dive( deltaTime );
		}
		break;
		
		default:
		{

		}
		break;
	}

}

void Enemy::move( const sf::Vector2f& direction, const float& deltaTime )
{
	// Move sprite in direction at speed
	sf::Sprite::move( getSpeed() * direction.x * deltaTime, getSpeed() * direction.y * deltaTime );
}

void Enemy::lerpMove( const sf::Vector2f& start, const sf::Vector2f& destination, const float& deltaTime )
{
	// lerpMove is the speed * deltaTime / the distance between the start and the destination
	// This gives the % acorss the lerp to move each frame to keep a consistent speed across the whole path
	m_lerpMove += ( getSpeed() * deltaTime ) / Math::vectorDistance( start, destination);

	if( m_lerpMove > 1 )
	{
		m_lerpMove = 1;
	}

	// set position to be point on lerp at lerpMove 
	setPosition( Math::lerp( start, destination, m_lerpMove ) );
}

void Enemy::dive( const float& deltaTime )
{
	
}




