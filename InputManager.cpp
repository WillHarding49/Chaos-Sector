#include <SFML\Window\Keyboard.hpp>

#include "Helpers.h"
#include "InputManager.h"
#include "Player.h"
#include "Settings.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::checkPlayerInputs( Player& player, ProjectilePool& missileManager, GameSound& shootSFX, const float& deltaTime )
{
	// Direction to move the player
	sf::Vector2f direction;

	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) || sf::Keyboard::isKeyPressed( sf::Keyboard::A ) )
	{
		// Set x direction to be negative
		direction.x = -1.0f;
	}

	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) || sf::Keyboard::isKeyPressed( sf::Keyboard::D ) )
	{
		// Set x direction to be positive
		direction.x = 1.0f;
	}

	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) || sf::Keyboard::isKeyPressed( sf::Keyboard::W ) )
	{
		// Set y direction to be negative
		direction.y = -1.0f;
	}

	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) || sf::Keyboard::isKeyPressed( sf::Keyboard::S ) )
	{
		// Set y direction to be positive
		direction.y = 1.0f;
	}

	// Normalise vector so diagonal vectors aren't bigger than cardinal ones
	direction = Math::normalise( direction );

	// Only set the direction of the player if it isn't 0
	if( direction != sf::Vector2f( 0, 0 ) )
	{
		player.setDirection( direction );
	}


	if( sf::Keyboard::isKeyPressed( sf::Keyboard::Space ))
	{
		player.shoot( missileManager, shootSFX );
	}

}