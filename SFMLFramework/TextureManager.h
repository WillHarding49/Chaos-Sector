#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <map>

//#######################################################
//	class		:	TextureManager
//	Purpose		:	Class for loading and managing textures
//	Usage		:	Make in game and pass textures to objects
//	Functions	:	TextureManager();
//					~TextureManager();
//					bool load( const std::string key, const std::string filePath,
//							   const sf::IntRect& sectionOfTexture = sf::IntRect( 0, 0, 0, 0 ) );
//					void loadAllTextures();
//					const sf::Texture& getTexture( const std::string& key );
//					bool loadFont( const char* fontFileName );
//					const sf::Font& getFont();
// 
//	See also	:	
//#######################################################
class TextureManager
{
private:
	std::map<std::string, sf::Texture>  m_textures; // Map containing the textures for each object
	sf::Font							m_font;		// Font for text


public:
	//#######################################################
	//	Function	:	TextureManager 
	//	Purpose		:	TextureManager constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	TextureManager();

	//#######################################################
	//	Function	:	~TextureManager 
	//	Purpose		:	TextureManager destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	~TextureManager();

	//#######################################################
	//	Function	:	load 
	//	Purpose		:	Loads a texture and adds it to the map
	//	Parameters	:	const std::string key
	//					const std::string filePath
	//					const sf::IntRect& sectionOfTexture = sf::IntRect( 0, 0, 0, 0 )
	//	Returns		:	bool loaded
	//	Notes		:	sectionOfTexture is default as most textures will
	//					load with the whole image, but you are able to define
	//					a section of an image to load here
	//	See also	:	
	//#######################################################
	bool load( const std::string key, const std::string filePath, const sf::IntRect& sectionOfTexture = sf::IntRect( 0, 0, 0, 0 ) );

	//#######################################################
	//	Function	:	loadAllTextures
	//	Purpose		:	Calls load() for all the textures
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	load
	//#######################################################
	void loadAllTextures();

	//#######################################################
	//	Function	:	getTexture
	//	Purpose		:	Returns a texture from the map with the
	//					given key
	//	Parameters	:	const std::string& key
	//	Returns		:	const sf::Texture& texture
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const sf::Texture& getTexture( const std::string& key );

	//#######################################################
	//	Function	:	loadFont
	//	Purpose		:	Loads a font for text, since a font is just
	//					a texture for text
	//	Parameters	:	const char* fontFileName
	//	Returns		:	bool loaded
	//	Notes		:	
	//	See also	:	
	//#######################################################
	bool loadFont( const char* fontFileName );

	//#######################################################
	//	Function	:	getFont
	//	Purpose		:	Returns the loaded font
	//	Parameters	:	None
	//	Returns		:	const sf::Font& font
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const sf::Font& getFont();

};

#endif // !TEXTUREMANAGER_H

