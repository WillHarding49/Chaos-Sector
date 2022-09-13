#include "GameSprite.h"
#include "Helpers.h"

GameSprite::GameSprite()
	// Default vaules making the gamesprite active with only 1 "frame"
	: m_active			( true ) 
	, m_numberOfFrames	( 1 )
	, m_frameTimer		( 0 )
	, m_animationFPS	( 0 )
{
	
}

GameSprite::~GameSprite()
{
}

void GameSprite::setActive( const bool& active )
{
	m_active = active;
}

const bool& GameSprite::getActive() const
{
	return m_active;
}

void GameSprite::setTexture( const sf::Texture& texture )
{
	// set texture 
	m_texture = texture;
	sf::Sprite::setTexture( m_texture );

	// Get the size of the texture
	sf::Vector2u textureDimensions = m_texture.getSize();

	// Move the origin of the texture to be in the centre
	setOrigin( textureDimensions.x * 0.5f, textureDimensions.y * 0.5f );

}

void GameSprite::setNumFrames( const int& numberOfFrames )
{
	m_numberOfFrames = numberOfFrames;
}

const int& GameSprite::getNumFrames() const
{
	return m_numberOfFrames;
}

void GameSprite::setAnimationFPS( const float& fps )
{
	m_animationFPS = fps;
}

const float& GameSprite::getAnimationFPS() const
{
	return m_animationFPS;
}

void GameSprite::setFrame( const int& frame )
{
	const sf::Texture& texture = m_texture;
	sf::Vector2u dimensions = texture.getSize();

	// The frame width is the spitesheet length / the number of frames to get the width of 1 frame
	int frameWidth = dimensions.x / m_numberOfFrames;

	sf::IntRect rect;

	// Left is corner of the current frame
	rect.left = frame * frameWidth;
	rect.top = 0;
	rect.width = frameWidth;

	// The height of the textre Rect, used here so repeating textures aren't messed up
	rect.height = getTextureRect().height;

	setTextureRect( rect );
}

bool GameSprite::load( const char* fileName, const sf::IntRect& sectionOfTexture )
{
	bool loaded;

	// If a section of the texture to load was not specified
	if( sectionOfTexture == sf::IntRect( 0, 0, 0, 0 ) )
	{
		// Load texture
		loaded = m_texture.loadFromFile( fileName );
	}
	else
	{
		// Load texture with section
		loaded = m_texture.loadFromFile( fileName, sectionOfTexture );
	}

	ASSERT( loaded == true );

	// Makes textures less crusty
	m_texture.setSmooth( true );

	// Sets sprite's texture
	setTexture( m_texture );

	// Get the size of the texture
	sf::Vector2u textureDimensions = m_texture.getSize();

	// Move the origin of the texture to be in the centre
	setOrigin( textureDimensions.x * 0.5f, textureDimensions.y * 0.5f );

	return loaded;
}

void GameSprite::scale( float x, float y )
{
	setScale( x, y );
}

void GameSprite::scale( const sf::Vector2f& scale )
{
	setScale( scale );
}

void GameSprite::animate( const float& deltaTime )
{
	m_frameTimer += deltaTime * m_animationFPS;

	int frame = static_cast< int >( m_frameTimer );
	frame %= m_numberOfFrames;
	setFrame( frame );
}