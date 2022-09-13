#include "ProjectilePool.h"

#include "Helpers.h"
#include <cmath>

ProjectilePool::ProjectilePool()
	: m_pProjectilePool		( nullptr )
	, m_poolIndex			( 0 )
	, m_maxPoolSize			( 100 )
{
	m_pProjectilePool = new Projectile[ m_maxPoolSize ];
	
}

ProjectilePool::ProjectilePool( int maxPoolSize, const sf::Texture& playerProjectileTexture, const sf::Texture& enemyProjectileTexture )
	: m_pProjectilePool			( nullptr )
	, m_poolIndex				( 0 )
	, m_maxPoolSize				( maxPoolSize )
	, m_playerProjectileTexture	( playerProjectileTexture )
	, m_enemyProjectileTexture	( enemyProjectileTexture )
{
	m_pProjectilePool = new Projectile[ m_maxPoolSize ];
	
}

ProjectilePool::~ProjectilePool()
{
	safeDeleteArray( m_pProjectilePool );
}

void ProjectilePool::setPool( Projectile* pool )
{
	// Delete pool and set a new one
	safeDeleteArray( m_pProjectilePool );

	m_pProjectilePool = pool;
}

 Projectile* ProjectilePool::getPool()
{
	return m_pProjectilePool;
}

const int ProjectilePool::getMaxPoolSize() const
{
	return m_maxPoolSize;
}

void ProjectilePool::fireProjectile( const sf::Vector2f& position, const sf::Vector2f& direction, const bool playerShot )
{
	// If the player shot the projectile
	if( playerShot )
	{
		// Set the player projectile texture and set the rotation to 0
		m_pProjectilePool[ m_poolIndex ].setTexture( m_playerProjectileTexture );
		m_pProjectilePool[ m_poolIndex ].setRotation( 0 );
	}
	else
	{
		// Set enemy projectile texture
		m_pProjectilePool[ m_poolIndex ].setTexture( m_enemyProjectileTexture );
		
		// arctan gives the angle between 2 vectors, and converts it from radians to degrees
		float angle = ( atan2f( ( direction.y - position.y ), ( direction.x - position.x ) ) ) * 180.0f * Math::k_1pi;
		
		// If shooting towards the left
		if( direction.x < 0 )
		{
			// Sets so angle is facing the corect way
			angle = 180.0f + angle;
		}
		// If shooting towards the right
		else
		{
			// Sets so angle is facing the corect way
			angle = 180.0f - angle;
		}

		// Rotates projectile so it is angled towards the direction ( to the player )
		m_pProjectilePool[ m_poolIndex ].setRotation( angle );
	}

	// Set values for projectile
	m_pProjectilePool[ m_poolIndex ].setPosition( position );
	m_pProjectilePool[ m_poolIndex ].setDirection( direction );
	m_pProjectilePool[ m_poolIndex ].setActive( true );
	m_pProjectilePool[ m_poolIndex ].setPlayerProjectile( playerShot );

	// increase index for which projectile to use next-
	m_poolIndex++;

	// Reset index if hit limit
	if( m_poolIndex == m_maxPoolSize )
	{
		m_poolIndex = 0;
	}
}

void ProjectilePool::update( float deltaTime )
{
	// Loop through active projectiles and update them
	for( int i = 0; i < m_maxPoolSize; i++ )
	{
		if( m_pProjectilePool[ i ].getActive() )
		{
			m_pProjectilePool[ i ].update( deltaTime );
		}
	}
}

void ProjectilePool::render( sf::RenderWindow& window )
{
	// Loop through active projectiles and render them
	for( int i = 0; i < m_maxPoolSize; i++ )
	{
		if( m_pProjectilePool[ i ].getActive() )
		{
			window.draw( m_pProjectilePool[ i ] );
		}
	}
}

void ProjectilePool::reset()
{
	// Loop through active projectiles and set them inactive for new level
	for( int i = 0; i < m_maxPoolSize; i++ )
	{
		if( m_pProjectilePool[ i ].getActive() )
		{
			m_pProjectilePool[ i ].setActive( false );
		}
	}

}
