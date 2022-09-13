#include <iostream>

#include "Helpers.h"
#include "Player.h"

Player::Player()
	: MoveableGameSprite	( )
	, m_missileFired		( false )
	, m_missileCooldown		( 0.0f )
	, m_lives				( )
{
	// Loads in texture manually
	load( Settings::k_playerTexture );

	// Scales and positions ship
	scale( Settings::k_playerScale );
	setPosition( Settings::k_playerStartPos );
}

Player::Player( const sf::Texture& texture, const sf::Vector2f& scale, const sf::Vector2f& pos, float speed, int lives)
	: MoveableGameSprite	( speed, sf::Vector2f( 0, 0 ),  texture, scale )
	, m_missileFired		( false )
	, m_missileCooldown		( 0.0f )
	, m_lives				( lives )
{
	setPosition( pos );
}

Player::~Player()
{
}

void Player::setLives( const int& lives )
{
	m_lives = lives;
}

const int& Player::getLives() const
{
	return m_lives;
}

void Player::reduceLives()
{
	m_lives--;
}

void Player::reset( const sf::Vector2f& pos, int lives )
{
	// Reset position and lives
	setPosition( pos );
	m_lives = lives;
}

void Player::update( const float& deltaTime )
{
	if( m_missileFired )
	{
		// Add to missile cooldown timer
		m_missileCooldown += deltaTime;

		// If timer is >= the missile cooldown length
		if( m_missileCooldown >= Settings::k_missileCooldownLength )
		{
			// Reset values so missile can be fired
			m_missileCooldown = 0;
			m_missileFired = false;
		}
	}

	// Move player
	move( getDirection(), deltaTime );

	sf::Vector2f newDir = getDirection();

	// Direction is damped
	setDirection( newDir *= Settings::k_dampingMultiplier );
}

void Player::move( const sf::Vector2f& direction, const float& deltaTime )
{
	// Get position of player
	sf::Vector2f pos = getPosition();

	// Add the "step" distance ( speed in a direction ) to the position * deltaTime
	pos += direction * getSpeed() * deltaTime;

	// Check if pos is within bounds and clamp if outside

	// If edge of player is out of bounds on the left
	if( pos.x < Settings::k_playerBoundsMin.x + getGlobalBounds().width * 0.5f )
	{
		pos.x = Settings::k_playerBoundsMin.x + getGlobalBounds().width * 0.5f;
	}

	// If edge of player is out of bounds on the top
	if( pos.y < Settings::k_playerBoundsMin.y + getGlobalBounds().height * 0.5f )
	{
		pos.y = Settings::k_playerBoundsMin.y + getGlobalBounds().height * 0.5f;
	}

	// If edge of player is out of bounds on the right
	if( pos.x > Settings::k_playerBoundsMax.x - getGlobalBounds().width * 0.5f )
	{
		pos.x = Settings::k_playerBoundsMax.x - getGlobalBounds().width * 0.5f;
	}

	// If edge of player is out of bounds on the bottom
	if( pos.y > Settings::k_playerBoundsMax.y - getGlobalBounds().height * 0.5f )
	{
		pos.y = Settings::k_playerBoundsMax.y - getGlobalBounds().height * 0.5f;
	}

	// Set position to the new pos
	setPosition( pos );
}

void Player::shoot( ProjectilePool& missileManager, GameSound& shootSFX )
{
	if( !m_missileFired )
	{
		// Fire missile from the player's position, upwards, and set playerFired to true
		missileManager.fireProjectile( getPosition(), sf::Vector2f( 0, -1 ), true );

		// Play shoot sound
		shootSFX.play();

		// Set bool to true for timer in update
		m_missileFired = true;
	}
}
