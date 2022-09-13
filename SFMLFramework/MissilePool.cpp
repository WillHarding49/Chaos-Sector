#include "MissilePool.h"
#include "Missile.h"

MissilePool::MissilePool()
	: ProjectilePool	()
{
	setPool( new Missile[ Settings::k_maxMissiles ] );
}

MissilePool::MissilePool( int maxPoolSize, const sf::Texture& playerProjectileTexture, const sf::Texture& enemyProjectileTexture )
	: ProjectilePool	( maxPoolSize, playerProjectileTexture, enemyProjectileTexture )
{
	setPool( new Missile[ maxPoolSize ] );
}

MissilePool::~MissilePool()
{
}

void MissilePool::fireProjectile( const sf::Vector2f& position, const sf::Vector2f& direction, const bool playerShot )
{
	ProjectilePool::fireProjectile( position, direction, playerShot );

	// Add any polymorphic changes here
}

void MissilePool::update( float deltaTime )
{
	ProjectilePool::update( deltaTime );

	// Add any polymorphic changes here
}

void MissilePool::render( sf::RenderWindow& window )
{
	ProjectilePool::render( window );

	// Add any polymorphic changes here
}
