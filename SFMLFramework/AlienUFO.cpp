#include "AlienUFO.h"
AlienUFO::AlienUFO()
	:Enemy()
{
}

AlienUFO::AlienUFO( sf::Texture& texture, sf::Vector2f& scale, sf::Vector2f& pos, sf::Vector2f& defaultPos, float speed, const std::vector<std::vector<sf::Vector2f>>& path )
	:Enemy( texture, scale, pos, defaultPos, speed, path )
{
}

AlienUFO::~AlienUFO()
{
}

void AlienUFO::update( const float& deltaTime, const sf::Vector2f& playerPos, ProjectilePool& missilePool )
{
	Enemy::update( deltaTime, playerPos, missilePool );

}

void AlienUFO::dive( const float& deltaTime )
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
		// Move to out of bounds
		setPosition( Settings::k_outOfBoundsPos );

		// Set path to that out of bounds pos
		std::vector<std::vector<sf::Vector2f>> path = { { Settings::k_outOfBoundsPos } };
		setPath( path );

		// Change state
		setState( EnemyStates::Formation );

		setDived( false );
	}
}
