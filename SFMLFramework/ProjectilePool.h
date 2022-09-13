#ifndef PROJECTILEPOOL_H
#define PROJECTILEPOOL_H

#include "Projectile.h"
#include "Settings.h"

//#######################################################
//	class		:	ProjectilePool
//	Purpose		:	Manager for projectiles
//	Usage		:	Toggles projectiles for memory efficent use 
//	Functions	:	ProjectilePool();
// 					ProjectilePool( int maxPoolSize, const sf::Texture& playerProjectileTexture, const sf::Texture& enemyProjectileTexture );
//					virtual ~ProjectilePool();
// 					void setPool( Projectile* pool );
// 					Projectile* getPool();
// 					const int getMaxPoolSize() const;
// 					virtual void fireProjectile( const sf::Vector2f& position, const sf::Vector2f& direction, const bool playerShot );
// 					virtual void update( float deltaTime );
// 					virtual void render( sf::RenderWindow& window );
// 					void reset();
//					
//	See also	:	MoveableGameSprite, Projectile
//#######################################################
class ProjectilePool
{
private:
	Projectile*		m_pProjectilePool;			// Pointer array of projectiles
	int				m_poolIndex;				// Index for which porjectile in the array to next use
	int				m_maxPoolSize;				// Max number of projectiles in the pool
	sf::Texture		m_playerProjectileTexture;  // Texture for player's projectile
	sf::Texture		m_enemyProjectileTexture;	// Texture for enemy's projectile

public:
	//#######################################################
	//	Function	:	Projectile 
	//	Purpose		:	Projectile constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	ProjectilePool();

	//#######################################################
	//	Function	:	ProjectilePool 
	//	Purpose		:	Projectile constructor overload
	//	Parameters	:	int maxPoolSize
	//					const sf::Texture& playerProjectileTexture
	//					const sf::Texture& enemyProjectileTexture
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	ProjectilePool( int maxPoolSize, const sf::Texture& playerProjectileTexture, const sf::Texture& enemyProjectileTexture );

	//#######################################################
	//	Function	:	~ProjectilePool 
	//	Purpose		:	ProjectilePool destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	virtual
	//	See also	:	
	//#######################################################
	~ProjectilePool();

	//#######################################################
	//	Function	:	setPool
	//	Purpose		:	Sets m_pProjectilePool
	//	Parameters	:	Projectile* pool
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void setPool( Projectile* pool );


	//#######################################################
	//	Function	:	getPool
	//	Purpose		:	Gets m_pProjectilePool
	//	Parameters	:	None
	//	Returns		:	Projectile* pool
	//	Notes		:	
	//	See also	:	
	//#######################################################
	Projectile* getPool();

	//#######################################################
	//	Function	:	getMaxPoolSize
	//	Purpose		:	Gets m_maxPoolSize
	//	Parameters	:	None
	//	Returns		:	const int maxPoolSize
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const int getMaxPoolSize() const;

	//#######################################################
	//	Function	:	fireProjectile
	//	Purpose		:	Fires the next projectile in the pool
	//	Parameters	:	const sf::Vector2f& position
	//					const sf::Vector2f& direction
	//					const bool playerShot
	//	Returns		:	void
	//	Notes		:	virtual
	//	See also	:	
	//#######################################################
	virtual void fireProjectile( const sf::Vector2f& position, const sf::Vector2f& direction, const bool playerShot );

	//#######################################################
	//	Function	:	update
	//	Purpose		:	Calls update for each projectile in pool
	//	Parameters	:	const float& deltaTime
	//	Returns		:	void
	//	Notes		:	virtual
	//	See also	:	
	//#######################################################
	virtual void update( float deltaTime );

	//#######################################################
	//	Function	:	render
	//	Purpose		:	Calls render for each projectile in pool
	//	Parameters	:	sf::RenderWindow& window
	//	Returns		:	void
	//	Notes		:	virtual
	//	See also	:	
	//#######################################################
	virtual void render( sf::RenderWindow& window );

	//#######################################################
	//	Function	:	reset
	//	Purpose		:	Sets all projectiles inactive
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void reset();
};

#endif // !MISSILEMANAGER_H
