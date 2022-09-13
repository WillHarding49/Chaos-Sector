#include "Background.h"
#include "Settings.h"

Background::Background()
	: MoveableGameSprite	()
{
}

Background::Background( const sf::Texture& texture, const int& numFrames, const float& fps, const float& speed, const sf::Vector2f& direction )
	: MoveableGameSprite	( speed, direction, texture, sf::Vector2f( 1, 1 ) )
{
	// Make textureRect the size of the window, but twice as tall for seamless scrolling
	setTextureRect( sf::IntRect( Settings::k_windowSize.x, 0, Settings::k_windowSize.x, Settings::k_windowSize.y * 2 ) );

	// Set the origin to the centre of the screen
	setOrigin( Settings::k_windowSize.x * 0.5f, Settings::k_windowSize.y * 0.5f );

	// Set animation values
	setNumFrames( numFrames );
	setAnimationFPS( fps );
	setFrame( 0 );

	setPosition( Settings::k_windowSize.x * 0.5f, Settings::k_windowSize.y * 0.5f );
}

Background::~Background()
{
}

void Background::update( const float& deltaTime )
{
	animate( deltaTime );

	// Move down
	move( sf::Vector2f( 0, 1 ), deltaTime );
}

void Background::move( const sf::Vector2f& direction, const float& deltaTime )
{
	sf::Vector2f pos = getPosition();

	// Add the "step" distance ( speed in a direction ) to the position * deltaTime
	pos += direction * getSpeed() * deltaTime;

	// Check if pos is within bounds
	// If the center of the background has hit the middle of the screen
	if( pos.y >= Settings::k_windowSize.y / 2)
	{
		// Move to half the window size above the window bound
		setPosition( Settings::k_windowSize.x * 0.5f, 0 - Settings::k_windowSize.y * 0.5f );

		// This makes the repeated texture apply to the game window but the background object keeps
		// Moving back up, but it appears as if the background scrolls forever
	}
	else
	{
		// Set position to the new pos
		setPosition( pos );
	}


}
