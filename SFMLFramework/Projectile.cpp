#include "Projectile.h"
#include "Settings.h"

Projectile::Projectile()
	: MoveableGameSprite	( )
	, m_playerProjectile	( false )
{
	setPosition( 0, 0 );
	setActive( false );
}

Projectile::Projectile( float speed, sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& direction, const sf::Vector2f& scale )
	: MoveableGameSprite	( speed, direction, texture, scale )
	, m_playerProjectile	( false )
{
	setPosition( position );
	setActive( false );
}

Projectile::~Projectile()
{
}

void Projectile::setPlayerProjectile( const bool& playerProjectile )
{
	m_playerProjectile = playerProjectile;
}

const bool& Projectile::getPlayerProjectile() const
{
	return m_playerProjectile;
}

void Projectile::update( const float& deltaTime )
{
	// Move projectile
	move( getDirection(), deltaTime );
}

void Projectile::move( const sf::Vector2f& direction, const float& deltaTime )
{
	sf::Vector2f pos = getPosition();

	// Add the "step" distance ( speed in a direction ) to the position * deltaTime
	pos += direction * getSpeed() * deltaTime;

	// Check if pos is within bounds and set inactive if outside

	// If edge of projectile is out of screen bounds on the left
	if( pos.x < 0 - getGlobalBounds().width * 0.5f )
	{
		// Set to inactive so projectile will no longer update within pool
		setActive( false );
	}

	// If edge of projectile is out of screen bounds on the top
	if( pos.y < 0 - getGlobalBounds().height * 0.5f )
	{
		// Set to inactive so projectile will no longer update within pool
		setActive( false );
	}

	// If edge of projectile is out of screen bounds on the right
	if( pos.x > Settings::k_playAreaSize.x + getGlobalBounds().width * 0.5f )
	{
		// Set to inactive so projectile will no longer update within pool
		setActive( false );
	}

	// If edge of projectile is out of screen bounds on the bottom
	if( pos.y > Settings::k_playAreaSize.y + getGlobalBounds().height * 0.5f )
	{
		// Set to inactive so projectile will no longer update within pool
		setActive( false );
	}

	// Set position to the new pos
	setPosition( pos );
}