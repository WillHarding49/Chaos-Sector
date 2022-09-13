#include "Helpers.h"
#include "Settings.h"
#include "TextureManager.h"

TextureManager::TextureManager()
{
	loadAllTextures();
	loadFont( Settings::k_font );
}

TextureManager::~TextureManager()
{
}

bool TextureManager::load( const std::string key, const std::string filePath, const sf::IntRect& sectionOfTexture )
{
	bool loaded;
	sf::Texture tempTexture;

	// If a section of the texture to load was not specified
	if( sectionOfTexture == sf::IntRect( 0, 0, 0, 0 ) )
	{
		// Load texture
		loaded = tempTexture.loadFromFile( filePath );
	}
	else
	{
		// Load texture
		loaded = tempTexture.loadFromFile( filePath, sectionOfTexture );
	}

	// Makes textures less crusty
	tempTexture.setSmooth( true );

	// Sets so textures with larger TextureRects are repeated ( Mainly for animation things, like background )
	tempTexture.setRepeated( true );

	// Add texture to the map with key
	m_textures[ key ] = tempTexture;

	ASSERT( loaded == true );

	return loaded;
}

void TextureManager::loadAllTextures()
{
	// Load all the textures
	load( "Background", Settings::k_backgoundTexture );
	load( "Player", Settings::k_playerTexture );
	load( "PlayerMissile", Settings::k_missileTexture, Settings::k_playerMissileRect );
	load( "EnemyMissile", Settings::k_missileTexture, Settings::k_enemyMissileRect );
	load( "AlienUFO", Settings::k_ufoShipTexture );
	load( "AlienSphere", Settings::k_sphereShipTexture );
	load( "AlienRing", Settings::k_ringShipTexture );

}

const sf::Texture& TextureManager::getTexture( const std::string& key )
{
	return m_textures[ key ];
}

bool TextureManager::loadFont( const char* fontFileName )
{
	// Load font
	bool loaded = m_font.loadFromFile( fontFileName );
	ASSERT( loaded == true );

	return loaded;
}

const sf::Font& TextureManager::getFont()
{
	return m_font;
}
