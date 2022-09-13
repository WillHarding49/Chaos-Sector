#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "EnemyManager.h"
#include "Player.h"
#include "ProjectilePool.h"

//#######################################################
//	class		:	CollisionManager
//	Purpose		:	Class for checking collisions between objects
//	Usage		:	Make in game, call functions in update
//	Functions	:	CollisionManager();
//					~CollisionManager();
//					bool collisionCheckCircles( const GameSprite& object1, const GameSprite& object2 );
//					bool collisionCheckRect( const GameSprite& object1, const GameSprite& object2 );
//					bool checkPlayerProjectileCollisions( Projectile& projectilePool, Player& player );
//					bool checkEnemyProjectileCollisions( Projectile& projectilePool, EnemyManager& enemyManager );
//					bool checkEnemyPlayerCollisions( EnemyManager& enemyManager, Player& player );
// 
//	See also	:	
//#######################################################
class CollisionManager
{
private:

public:
	//#######################################################
	//	Function	:	CollisionManager 
	//	Purpose		:	CollisionManager constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	CollisionManager();

	//#######################################################
	//	Function	:	~CollisionManager 
	//	Purpose		:	CollisionManager destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	~CollisionManager();

	//#######################################################
	//	Function	:	collisionCheckCircles
	//	Purpose		:	Checks if 2 objects are colliding using circles
	//	Parameters	:	const GameSprite& object1
	//					const GameSprite& object2
	//	Returns		:	bool collided
	//	Notes		:	
	//	See also	:	
	//#######################################################
	bool collisionCheckCircles( const GameSprite& object1, const GameSprite& object2 );

	//#######################################################
	//	Function	:	collisionCheckRect
	//	Purpose		:	Checks if 2 objects are colliding using rects
	//	Parameters	:	const GameSprite& object1
	//					const GameSprite& object2
	//	Returns		:	bool collided
	//	Notes		:	
	//	See also	:	
	//#######################################################
	bool collisionCheckRect( const GameSprite& object1, const GameSprite& object2 );

	//#######################################################
	//	Function	:	checkPlayerProjectileCollisions
	//	Purpose		:	Checks if the player collides with a projectile
	//	Parameters	:	Projectile& projectilePool
	//					Player& player
	//	Returns		:	bool collided
	//	Notes		:	
	//	See also	:	
	//#######################################################
	bool checkPlayerProjectileCollisions( Projectile& projectilePool, Player& player );

	//#######################################################
	//	Function	:	checkEnemyProjectileCollisions
	//	Purpose		:	Checks if any enemies collide with a projectile
	//	Parameters	:	Projectile& projectilePool
	//					EnemyManager& enemyManager
	//	Returns		:	bool collided
	//	Notes		:	
	//	See also	:	
	//#######################################################
	bool checkEnemyProjectileCollisions( Projectile& projectilePool, EnemyManager& enemyManager );

	//#######################################################
	//	Function	:	checkEnemyPlayerCollisions
	//	Purpose		:	Checks if any enemies collide with the player
	//	Parameters	:	EnemyManager& enemyManager
	//					Player& player
	//	Returns		:	bool collided
	//	Notes		:	
	//	See also	:	
	//#######################################################
	bool checkEnemyPlayerCollisions( EnemyManager& enemyManager, Player& player );

};

#endif // !COLLISIONMANAGER_H
