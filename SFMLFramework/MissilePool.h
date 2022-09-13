#ifndef MISSILEPOOL_H
#define MISSILEPOOL_H

#include "ProjectilePool.h"

//#######################################################
//	class		:	MissilePool
//	Purpose		:	Manager for missiles, just a polymorphic template at this stage
//	Usage		:	Toggles projectiles for memory efficent use 
//	Functions	:	MissilePool();
//					MissilePool( int maxPoolSize, const sf::Texture& playerProjectileTexture, const sf::Texture& enemyProjectileTexture );
//					virtual ~MissilePool();
// 					void fireProjectile( const sf::Vector2f& position, const sf::Vector2f& direction, const bool playerShot );
//					void update( float deltaTime );
// 					void render( sf::RenderWindow& window );
//					
//	See also	:	ProjectilePool, Missile
//#######################################################
class MissilePool : public ProjectilePool
{
private:

public:
	//#######################################################
	//	Function	:	MissilePool 
	//	Purpose		:	MissilePool constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	MissilePool();

	//#######################################################
	//	Function	:	MissilePool 
	//	Purpose		:	MissilePool constructor overloaded
	//	Parameters	:	int maxPoolSize
	//					const sf::Texture& playerProjectileTexture
	//					const sf::Texture& enemyProjectileTexture
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	MissilePool( int maxPoolSize, const sf::Texture& playerProjectileTexture, const sf::Texture& enemyProjectileTexture );

	//#######################################################
	//	Function	:	~MissilePool 
	//	Purpose		:	MissilePool destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	~MissilePool();

	//#######################################################
	//	Function	:	fireProjectile
	//	Purpose		:	Fires the next missile in the pool
	//	Parameters	:	const sf::Vector2f& position
	//					const sf::Vector2f& direction
	//					const bool playerShot
	//	Returns		:	void
	//	Notes		:	virtual override
	//	See also	:	
	//#######################################################
	virtual void fireProjectile( const sf::Vector2f& position, const sf::Vector2f& direction, const bool playerShot ) override;

	//#######################################################
	//	Function	:	update
	//	Purpose		:	Calls update for each missile in pool
	//	Parameters	:	const float& deltaTime
	//	Returns		:	void
	//	Notes		:	virtual override
	//	See also	:	
	//#######################################################
	virtual void update( float deltaTime ) override;

	//#######################################################
	//	Function	:	render
	//	Purpose		:	Calls render for each missile in pool
	//	Parameters	:	sf::RenderWindow& window
	//	Returns		:	void
	//	Notes		:	virtual override
	//	See also	:	
	//#######################################################
	virtual void render( sf::RenderWindow& window ) override;
};

#endif // !MISSILEPOOL_H

