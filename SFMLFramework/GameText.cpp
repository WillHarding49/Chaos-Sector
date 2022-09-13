#include "GameText.h"
#include "Helpers.h"

GameText::GameText()
	:m_lerpValue	( 0.0f )
{
}

GameText::~GameText()
{
}

bool GameText::loadFont( const char* fontFileName )
{
	// Load font
	bool loaded = m_font.loadFromFile( fontFileName );
	ASSERT( loaded == true );

	// Set font
	setFont( m_font );

	return loaded;
}

void GameText::setFont( const sf::Font& font )
{
	// Set font
	m_font = font;
	sf::Text::setFont( m_font );
}

void GameText::rainbowLerp( const float& deltaTime )
{
	// Lerp between Red, Blue, and Green, and back to Red
	sf::Vector3f colour = Math::lerp3ReturnBack( sf::Vector3f( 255, 0, 0 ), sf::Vector3f( 0, 255, 0 ), sf::Vector3f( 0, 0, 255 ), m_lerpValue );
	
	// Set the colour to the lerped colour
	setFillColor( sf::Color( static_cast< sf::Uint8 >( colour.x ), static_cast< sf::Uint8 >( colour.y ), static_cast< sf::Uint8 >( colour.z ) ) );

	// Increase lerp
	m_lerpValue += deltaTime * 0.1f;

	// Reset lerpValue to 0 so it lerps forever
	if( m_lerpValue > 1.0f )
	{
		m_lerpValue = 0;
	}
}
