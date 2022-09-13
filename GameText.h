#ifndef GAMETEXT_H
#define GAMETEXT_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

//#######################################################
//	class		:	GameText
//	Purpose		:	Class for text objects
//	Usage		:	Make new objects in game to display text
//	Functions	:	GameText();
//					virtual ~GameText();
//					bool loadFont( const char* fontFileName );
//					void rainbowLerp( const float& deltaTime );
// 
//	See also	:	Text
//#######################################################
class GameText : public sf::Text
{
private:
	sf::Font	m_font;			// Font the text uses
	float		m_lerpValue;	// Float for lerping

public:
	//#######################################################
	//	Function	:	GameText 
	//	Purpose		:	GameText constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	GameText();

	//#######################################################
	//	Function	:	~GameText 
	//	Purpose		:	GameText destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	~GameText();

	//#######################################################
	//	Function	:	loadFont 
	//	Purpose		:	Loads a font file
	//	Parameters	:	const char* fontFileName
	//	Returns		:	bool loaded
	//	Notes		:	
	//	See also	:	
	//#######################################################
	bool loadFont( const char* fontFileName );

	//#######################################################
	//	Function	:	setFont 
	//	Purpose		:	Sets m_font
	//	Parameters	:	const sf::Font& font
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void setFont( const sf::Font& font );

	//#######################################################
	//	Function	:	rainbowLerp 
	//	Purpose		:	Makes the text cycle through RGB
	//	Parameters	:	const float& deltaTime
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void rainbowLerp( const float& deltaTime );
};

#endif