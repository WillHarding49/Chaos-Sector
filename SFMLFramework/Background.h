#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "MoveableGameSprite.h"

//#######################################################
//	class		:	Background
//	Purpose		:	Class for the background
//	Usage		:	Make in game, update and render
//	Functions	:	Background();
//					Background( const sf::Texture& texture, int numFrames, float fps, float speed, const sf::Vector2f& direction );
//					virtual ~Background();
//					void update( const float& deltaTime );
//					virtual void move( const sf::Vector2f& direction, const float& deltaTime ) override;
// 
//	See also	:	MoveableGameSprite
//#######################################################
class Background : public MoveableGameSprite
{
private:

public:
	//#######################################################
	//	Function	:	Background 
	//	Purpose		:	Background constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	Background();

	//#######################################################
	//	Function	:	Background 
	//	Purpose		:	Background constructor overload
	//	Parameters	:	const sf::Texture& texture
	//					const int& numFrames
	//					const float& fps
	//					const float& speed
	//					const sf::Vector2f& direction
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	Background( const sf::Texture& texture, const int& numFrames, const float& fps, const float& speed, const sf::Vector2f& direction );
	
	//#######################################################
	//	Function	:	~Background 
	//	Purpose		:	Background destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	virtual ~Background();

	//#######################################################
	//	Function	:	update
	//	Purpose		:	Updates background
	//	Parameters	:	const float& deltaTime
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void update( const float& deltaTime );

	//#######################################################
	//	Function	:	move 
	//	Purpose		:	Moves background
	//	Parameters	:	const sf::Vector2f& direction
	//					const float& deltaTime
	//	Returns		:	void
	//	Notes		:	virtual override
	//	See also	:	
	//#######################################################
	virtual void move( const sf::Vector2f& direction, const float& deltaTime ) override;


};

#endif // !BACKGROUND_H
