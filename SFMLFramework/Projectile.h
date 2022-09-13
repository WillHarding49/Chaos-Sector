#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "MoveableGameSprite.h"

//#######################################################
//	class		:	Projectile
//	Purpose		:	Fireable projectile instance
//	Usage		:	Pooled in ProjectilePool and fired by enemies/player
//	Functions	:	Projectile();
// 					Projectile( float speed, sf::Texture& texture, const sf::Vector2f& position,
//								const sf::Vector2f& direction, const sf::Vector2f& scale );
//					virtual ~Projectile();
// 					void setPlayerProjectile( const bool& playerProjectile );
// 					const bool& getPlayerProjectile() const;
// 					virtual void update( const float& deltaTime );
// 					virtual void move( const sf::Vector2f& direction, const float& deltaTime ) override;				
//					
//	See also	:	MoveableGameSprite, ProjectilePool
//#######################################################
class Projectile : public MoveableGameSprite
{
private:
	bool m_playerProjectile; // Bool for if the player has fired the projectile

public:
	//#######################################################
	//	Function	:	Projectile 
	//	Purpose		:	Projectile constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	Projectile();

	//#######################################################
	//	Function	:	Projectile 
	//	Purpose		:	Projectile constructor overload
	//	Parameters	:	float speed
	//					sf::Texture& texture
	//					const sf::Vector2f& position
	//					const sf::Vector2f& direction
	//					const sf::Vector2f& scale
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	Projectile( float speed, sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& direction, const sf::Vector2f& scale );

	//#######################################################
	//	Function	:	~Projectile 
	//	Purpose		:	Projectile destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	virtual
	//	See also	:	
	//#######################################################
	virtual ~Projectile();

	//#######################################################
	//	Function	:	setPlayerProjectile
	//	Purpose		:	sets m_playerProjectile
	//	Parameters	:	const bool& playerProjectile
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void setPlayerProjectile( const bool& playerProjectile );

	//#######################################################
	//	Function	:	getPlayerProjectile
	//	Purpose		:	Gets m_playerProjectile
	//	Parameters	:	None
	//	Returns		:	const bool& playerProjectile
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const bool& getPlayerProjectile() const;

	//#######################################################
	//	Function	:	update
	//	Purpose		:	Updates projectile
	//	Parameters	:	const float& deltaTime
	//	Returns		:	void
	//	Notes		:	virtual
	//	See also	:	
	//#######################################################
	virtual void update( const float& deltaTime );

	//#######################################################
	//	Function	:	move 
	//	Purpose		:	Moves projectile
	//	Parameters	:	const sf::Vector2f& direction
	//					const float& deltaTime
	//	Returns		:	void
	//	Notes		:	virtual override
	//	See also	:	
	//#######################################################
	virtual void move( const sf::Vector2f& direction, const float& deltaTime ) override;

};

#endif // !PROJECTILE_H

