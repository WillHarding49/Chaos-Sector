#ifndef MISSILE_H
#define MISSILE_H

#include "Projectile.h"

//#######################################################
//	class		:	Missile
//	Purpose		:	Fireable missile instance, just a polymorphic template at this stage
//	Usage		:	Pooled in MissilePool and fired by enemies/player
//	Functions	:	Missile();
//					Missile( const float& speed, sf::Texture& texture,
//							 const sf::Vector2f& position, const sf::Vector2f& direction, const sf::Vector2f& scale );
//					virtual ~Missile();
// 					virtual void update( const float& deltaTime ) override;
//				 	virtual void move( const sf::Vector2f& direction, const float& deltaTime ) override;
//					
//	See also	:	MoveableGameSprite, Projectile, MissilePool
//#######################################################
class Missile : public Projectile
{
private:
	

public:
	//#######################################################
	//	Function	:	Missile 
	//	Purpose		:	Missile constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	Missile();

	//#######################################################
	//	Function	:	Missile 
	//	Purpose		:	Missile constructor overload
	//	Parameters	:	float speed
	//					sf::Texture& texture
	//					const sf::Vector2f& position
	//					const sf::Vector2f& direction
	//					const sf::Vector2f& scale
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	Missile( const float& speed, sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& direction, const sf::Vector2f& scale );
	
	//#######################################################
	//	Function	:	~Missile 
	//	Purpose		:	Missile destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	virtual
	//	See also	:	
	//#######################################################
	virtual ~Missile();

	//#######################################################
	//	Function	:	update
	//	Purpose		:	Updates missile
	//	Parameters	:	const float& deltaTime
	//	Returns		:	void
	//	Notes		:	virtual override
	//	See also	:	
	//#######################################################
	virtual void update( const float& deltaTime ) override;

	//#######################################################
	//	Function	:	move 
	//	Purpose		:	Moves missile
	//	Parameters	:	const sf::Vector2f& direction
	//					const float& deltaTime
	//	Returns		:	void
	//	Notes		:	virtual override
	//	See also	:	
	//#######################################################
	virtual void move( const sf::Vector2f& direction, const float& deltaTime ) override;

};

#endif // !MISSILE_H

