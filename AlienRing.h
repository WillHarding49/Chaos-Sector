#ifndef ALIENRING_H
#define ALIENRING_H

#include "Enemy.h"

//#######################################################
//	class		:	AlienRing
//	Purpose		:	Enemy child
//	Usage		:	Make in EnemyManager
//	Functions	:	AlienRing();
//					AlienRing( sf::Texture& texture, sf::Vector2f& scale, sf::Vector2f& pos,
//							   sf::Vector2f& defaultPos, float speed, const std::vector<std::vector<sf::Vector2f>>& path );
//					virtual ~AlienRing();
//					virtual void update( const float& deltaTime, const sf::Vector2f& playerPos, ProjectilePool& missilePool ) override;
//					virtual void dive( const float& deltaTime ) override;
// 
//	See also	:	Enemy
//#######################################################
class AlienRing : public Enemy
{
private:

public:
	//#######################################################
	//	Function	:	AlienRing 
	//	Purpose		:	AlienRing constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	AlienRing();

	//#######################################################
	//	Function	:	AlienRing 
	//	Purpose		:	AlienRing constructor overload
	//	Parameters	:	sf::Texture& texture, sf::Vector2f& scale
	//					sf::Vector2f& pos
	//					sf::Vector2f& defaultPos
	//					float speed
	//					const std::vector<std::vector<sf::Vector2f>>& path
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	AlienRing( sf::Texture& texture, sf::Vector2f& scale, sf::Vector2f& pos, sf::Vector2f& defaultPos, float speed, const std::vector<std::vector<sf::Vector2f>>& path );
	
	//#######################################################
	//	Function	:	~AlienRing 
	//	Purpose		:	AlienRing destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	virtual
	//	See also	:	
	//#######################################################
	virtual ~AlienRing();

	//#######################################################
	//	Function	:	update
	//	Purpose		:	Updates alien
	//	Parameters	:	const float& deltaTime	
	//					const sf::Vector2f& playerPos
	//					ProjectilePool& missilePool
	//	Returns		:	void
	//	Notes		:	virtual override
	//	See also	:	
	//#######################################################
	virtual void update( const float& deltaTime, const sf::Vector2f& playerPos, ProjectilePool& missilePool ) override;

	//#######################################################
	//	Function	:	dive 
	//	Purpose		:	Makes alien dive
	//	Parameters	:	const float& deltaTime
	//	Returns		:	void
	//	Notes		:	virtual override
	//	See also	:	
	//#######################################################
	virtual void dive( const float& deltaTime ) override;

};

#endif // !ALIENRING_H