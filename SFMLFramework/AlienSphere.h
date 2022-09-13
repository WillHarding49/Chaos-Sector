#ifndef ALIENSPHERE_H
#define ALIENSPHERE_H

#include "Enemy.h"

//#######################################################
//	class		:	AlienSphere
//	Purpose		:	Enemy child
//	Usage		:	Make in EnemyManager
//	Functions	:	AlienSphere();
//					AlienSphere( sf::Texture& texture, sf::Vector2f& scale, sf::Vector2f& pos,
//							   sf::Vector2f& defaultPos, float speed, const std::vector<std::vector<sf::Vector2f>>& path );
//					virtual ~AlienSphere();
//					virtual void update( const float& deltaTime, const sf::Vector2f& playerPos, ProjectilePool& missilePool ) override;
//					virtual void dive( const float& deltaTime ) override;
// 
//	See also	:	Enemy
//#######################################################
class AlienSphere : public Enemy
{
private:

public:
	//#######################################################
	//	Function	:	AlienSphere 
	//	Purpose		:	AlienSphere constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	AlienSphere();

	//#######################################################
	//	Function	:	AlienSphere 
	//	Purpose		:	AlienSphere constructor overload
	//	Parameters	:	sf::Texture& texture, sf::Vector2f& scale
	//					sf::Vector2f& pos
	//					sf::Vector2f& defaultPos
	//					float speed
	//					const std::vector<std::vector<sf::Vector2f>>& path
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	AlienSphere( sf::Texture& texture, sf::Vector2f& scale, sf::Vector2f& pos, sf::Vector2f& defaultPos, float speed, const std::vector<std::vector<sf::Vector2f>>& path );

	//#######################################################
	//	Function	:	~AlienSphere 
	//	Purpose		:	AlienSphere destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	virtual
	//	See also	:	
	//#######################################################
	virtual ~AlienSphere();


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

#endif // !ALIENSPHERE_H