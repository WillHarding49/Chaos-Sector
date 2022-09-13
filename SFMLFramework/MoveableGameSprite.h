#ifndef MOVEABLEGAMESPRITE_H
#define MOVEABLEGAMESPRITE_H

#include "GameSprite.h"

//#######################################################
//	class		:	MoveableGameSprite
//	Purpose		:	GameSprite child that can move
//	Usage		:	Inherited by specialised children
//	Functions	:	MoveableGameSprite();
//					MoveableGameSprite( const float& speed, const sf::Vector2f& direction,
//										const sf::Texture& texture, const sf::Vector2f& initialScale );
//					virtual ~MoveableGameSprite();
// 					void setSpeed( const float& speed );
// 					const float& getSpeed() const;
// 					void setDirection( const sf::Vector2f& direction );
// 					const sf::Vector2f& getDirection() const;
// 					virtual void move( const sf::Vector2f& direction, const float& deltaTime );
//					
//	See also	:	
//#######################################################
class MoveableGameSprite : public GameSprite
{
private:
	float			m_speed;		// Movement speed of sprites
	sf::Vector2f	m_direction;	// Direction to move

public:
	//#######################################################
	//	Function	:	MoveableGameSprite 
	//	Purpose		:	MoveableGameSprite constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	MoveableGameSprite();

	//#######################################################
	//	Function	:	MoveableGameSprite 
	//	Purpose		:	MoveableGameSprite constructor overload
	//	Parameters	:	const float& speed
	//					const sf::Vector2f& direction
	//					const sf::Texture& texture
	//					const sf::Vector2f& initialScale
	//	Returns		:	void
	//	Notes		:	Overload with parameters
	//	See also	:	
	//#######################################################
	MoveableGameSprite( const float& speed, const sf::Vector2f& direction, const sf::Texture& texture, const sf::Vector2f& initialScale );

	//#######################################################
	//	Function	:	~MoveableGameSprite 
	//	Purpose		:	MoveableGameSprite destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	virtual ~MoveableGameSprite();

	//#######################################################
	//	Function	:	setSpeed
	//	Purpose		:	sets m_speed
	//	Parameters	:	const float& speed
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void setSpeed( const float& speed );

	//#######################################################
	//	Function	:	getSpeed
	//	Purpose		:	gets m_speed
	//	Parameters	:	None
	//	Returns		:	const float& speed
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const float& getSpeed() const;

	//#######################################################
	//	Function	:	setDirection
	//	Purpose		:	sets m_direction
	//	Parameters	:	const sf::Vector2f& direction
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void setDirection( const sf::Vector2f& direction );

	//#######################################################
	//	Function	:	getDirection
	//	Purpose		:	Gets m_direction
	//	Parameters	:	None
	//	Returns		:	const sf::Vector2f& direction
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const sf::Vector2f& getDirection() const;

	//#######################################################
	//	Function	:	move 
	//	Purpose		:	moves sprite
	//	Parameters	:	const sf::Vector2f& direction
	//					const float deltaTime
	//	Returns		:	void
	//	Notes		:	virtual
	//	See also	:	
	//#######################################################
	virtual void move( const sf::Vector2f& direction, const float& deltaTime );

};

#endif // !MOVEABLEGAMESPRITE_H
