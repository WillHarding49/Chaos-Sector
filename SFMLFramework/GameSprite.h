#ifndef GAMESPRITE_H
#define GAMESPRITE_H

#include <SFML/Graphics.hpp>

//#######################################################
//	class		:	GameSprite
//	Purpose		:	Parent class for sprites with textures
//	Usage		:	Inherited by child classes
//	Functions	:	GameSprite();
//					~GameSprite();
//					void setActive( const bool& active );
// 					const bool& getActive() const;
// 					void setTexture( const sf::Texture& texture );
// 					void setNumFrames( const int& numberOfFrames );
// 					const int& getNumFrames() const;
// 					const float& getAnimationFPS() const;
// 					void setAnimationFPS( const float& fps );
// 					void setFrame( const int& frame );
// 					bool load( const char* fileName, const sf::IntRect& sectionOfTexture = sf::IntRect(0, 0, 0, 0) );
// 					void scale( float x, float y );
// 					void scale( const sf::Vector2f& scale );
// 					void animate( const float& deltaTime );
//					
//	See also	:	sf::Sprite
//#######################################################
class GameSprite : public sf::Sprite
{
private:
	sf::Texture		m_texture;			// Texture of the sprite
	bool			m_active;			// Bool for if the gameObject is active, used for only rendering active objects
	int				m_numberOfFrames;	// Number of frames in sprite sheet for animation
	float			m_frameTimer;		// Timer for changing animation frames
	float			m_animationFPS;		// How many frames per second to show

public:
	//#######################################################
	//	Function	:	GameSprite 
	//	Purpose		:	GameSprite constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	GameSprite();

	//#######################################################
	//	Function	:	~GameSprite 
	//	Purpose		:	GameSprite destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	~GameSprite();

	//#######################################################
	//	Function	:	setActive 
	//	Purpose		:	Setter for m_active
	//	Parameters	:	const bool& active
	//	Returns		:	void
	//	Notes		:
	//	See also	:	
	//#######################################################
	void setActive( const bool& active );

	//#######################################################
	//	Function	:	getActive 
	//	Purpose		:	Getter for m_active
	//	Parameters	:	None
	//	Returns		:	const bool&
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const bool& getActive() const;

	//#######################################################
	//	Function	:	setTexture 
	//	Purpose		:	Uses given texture to set texture
	//	Parameters	:	const sf::Texture& texture
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	TextureManager
	//#######################################################
	void setTexture( const sf::Texture& texture );

	//#######################################################
	//	Function	:	setNumFrames
	//	Purpose		:	Sets m_numberOfFrames
	//	Parameters	:	const int& numberOfFrames
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void setNumFrames( const int& numberOfFrames );

	//#######################################################
	//	Function	:	getNumFrames
	//	Purpose		:	Gets m_numberOfFrames
	//	Parameters	:	None
	//	Returns		:	const int& numberOfFrames
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const int& getNumFrames() const;

	//#######################################################
	//	Function	:	setAnimationFPS
	//	Purpose		:	Sets m_animationFPS
	//	Parameters	:	const float& fps
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void setAnimationFPS( const float& fps );

	//#######################################################
	//	Function	:	getAnimationFPS
	//	Purpose		:	Gets m_animationFPS
	//	Parameters	:	None
	//	Returns		:	const float& animationFPS
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const float& getAnimationFPS() const;

	//#######################################################
	//	Function	:	setFrame
	//	Purpose		:	Moves active section of texture sheet for
	//					correct frame of animation
	//	Parameters	:	const int& frame
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void setFrame( const int& frame );

	//#######################################################
	//	Function	:	load 
	//	Purpose		:	loads texture manually
	//	Parameters	:	const char* fileName
	//					const sf::IntRect& sectionOfTexture = sf::IntRect(0, 0, 0, 0)
	//	Returns		:	bool succeeded
	//	Notes		:	Default sectionOfTexture as some textures can specify
	//					what part of the texture to load from
	//	See also	:	
	//#######################################################
	bool load( const char* fileName, const sf::IntRect& sectionOfTexture = sf::IntRect(0, 0, 0, 0) );

	//#######################################################
	//	Function	:	scale
	//	Purpose		:	Scales sprite and sets averageHalves
	//	Parameters	:	float x
	//					float y
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void scale( float x, float y );

	//#######################################################
	//	Function	:	scale
	//	Purpose		:	Scales sprite and sets averageHalves
	//	Parameters	:	const sf::Vector2f& scale
	//	Returns		:	void
	//	Notes		:	Vector Overload
	//	See also	:	
	//#######################################################
	void scale( const sf::Vector2f& scale );

	//#######################################################
	//	Function	:	animate
	//	Purpose		:	Changes animation frame based on m_frameTimer
	//	Parameters	:	const float& deltaTime
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void animate( const float& deltaTime );

};

#endif // !GAMESPRITE_H

