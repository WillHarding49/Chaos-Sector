#include "MoveableGameSprite.h"
#include "Settings.h"

MoveableGameSprite::MoveableGameSprite()
	: m_speed	( Settings::k_playerSpeed )
{

}

MoveableGameSprite::MoveableGameSprite( const float& speed, const sf::Vector2f& direction, const sf::Texture& texture, const sf::Vector2f& initialScale )
	: m_speed( speed )
	, m_direction( direction )
{
	// Loads in texture
	setTexture( texture );

	// Scales and positions ship
	scale( initialScale );
}

MoveableGameSprite::~MoveableGameSprite()
{

}

void MoveableGameSprite::setSpeed( const float& speed )
{
	m_speed = speed;
}

const float& MoveableGameSprite::getSpeed() const
{
	return m_speed;
}

void MoveableGameSprite::setDirection( const sf::Vector2f& direction )
{
	m_direction = direction;
}

const sf::Vector2f& MoveableGameSprite::getDirection() const
{
	return m_direction;
}

void MoveableGameSprite::move( const sf::Vector2f& direction, const float& deltaTime )
{

}
