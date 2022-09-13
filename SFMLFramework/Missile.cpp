#include "Missile.h"

#include "Settings.h"

Missile::Missile()
	: Projectile	( )
{
	scale( Settings::k_missileScale );
}

Missile::Missile( const float& speed, sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& direction, const sf::Vector2f& scale )
	: Projectile	( speed, texture, position, direction, scale )
{

}

Missile::~Missile()
{

}

void Missile::update( const float& deltaTime )
{
	Projectile::update( deltaTime );

	// Add any polymorphic changes here
}

void Missile::move( const sf::Vector2f& direction, const float& deltaTime )
{
	Projectile::move( direction, deltaTime );

	// Add any polymorphic changes here
}
