#include "AlienSphere.h"
AlienSphere::AlienSphere()
	:Enemy()
{
}

AlienSphere::AlienSphere( sf::Texture& texture, sf::Vector2f& scale, sf::Vector2f& pos, sf::Vector2f& defaultPos, float speed, const std::vector<std::vector<sf::Vector2f>>& path )
	: Enemy( texture, scale, pos, defaultPos, speed, path )
{
}

AlienSphere::~AlienSphere()
{
}

void AlienSphere::update( const float& deltaTime, const sf::Vector2f& playerPos, ProjectilePool& missilePool )
{
	Enemy::update( deltaTime, playerPos, missilePool );

}

void AlienSphere::dive( const float& deltaTime )
{
	// If not finished dive
	if( !getDived() )
	{
		// Move across dive path
		pathMove( deltaTime );
	}
	else
	{
		// Move in direction, which will be "towards" the player
		move( getDirection(), deltaTime );
	}

	// If beyond the bottom of the window
	if( getPosition().y > Settings::k_playAreaSize.y )
	{
		// Set path to current position so the alien beelines from the end of the dive to its default position
		std::vector<std::vector<sf::Vector2f>> path = { { getPosition() } };
		setPath( path );

		// Change state
		setState( EnemyStates::Formation );

		setDived( false );
	}
}
