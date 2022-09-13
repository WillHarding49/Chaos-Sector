#ifndef ALIENUFO_H
#define ALIENUFO_H

#include "Enemy.h"


//#######################################################
//	class		:	AlienUFO
//	Purpose		:	Enemy child
//	Usage		:	Make in EnemyManager
//	Functions	:	AlienUFO();
//					AlienUFO( sf::Texture& texture, sf::Vector2f& scale, sf::Vector2f& pos,
//							   sf::Vector2f& defaultPos, float speed, const std::vector<std::vector<sf::Vector2f>>& path );
//					virtual ~AlienUFO();
//					virtual void update( const float& deltaTime, const sf::Vector2f& playerPos, ProjectilePool& missilePool ) override;
//					virtual void dive( const float& deltaTime ) override;
// 
//	See also	:	Enemy
//#######################################################
class AlienUFO : public Enemy
{
private:

public:
	//#######################################################
	//	Function	:	AlienUFO 
	//	Purpose		:	AlienUFO constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	AlienUFO();

	//#######################################################
	//	Function	:	AlienUFO 
	//	Purpose		:	AlienUFO constructor overload
	//	Parameters	:	sf::Texture& texture, sf::Vector2f& scale
	//					sf::Vector2f& pos
	//					sf::Vector2f& defaultPos
	//					float speed
	//					const std::vector<std::vector<sf::Vector2f>>& path
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	AlienUFO( sf::Texture& texture, sf::Vector2f& scale, sf::Vector2f& pos, sf::Vector2f& defaultPos, float speed, const std::vector<std::vector<sf::Vector2f>>& path );

	//#######################################################
	//	Function	:	~AlienUFO 
	//	Purpose		:	AlienUFO destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	virtual
	//	See also	:	
	//#######################################################
	virtual ~AlienUFO();


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

#endif // !ALIENUFO_H
