#ifndef ENEMY_H
#define ENEMY_H

#include "EnemyStates.h"
#include "MoveableGameSprite.h"
#include "ProjectilePool.h"

//#######################################################
//	class		:	Enemy
//	Purpose		:	Parent class for Enemies
//	Usage		:	Inherited by child classes and used in Enemy Manager as base for polymorphism
//	Functions	:	Enemy();
// 					Enemy( sf::Texture& texture, sf::Vector2f& scale, sf::Vector2f& pos, sf::Vector2f& defaultPos,
//						   float speed, const std::vector<std::vector<sf::Vector2f>>& path );
//					virtual ~Enemy();
//					void setDefultPos( const sf::Vector2f& pos );
//					const sf::Vector2f& getDefultPos();
//					void setState( const EnemyStates& state );
//					const EnemyStates& getState();
//					void setPath( const std::vector<std::vector<sf::Vector2f>>& path );
//					const std::vector<std::vector<sf::Vector2f>>& getPath();
//					void setDived( const bool& dived );
//					const bool& getDived();
//					void bezierCurveMove( const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3, const float& deltaTime );
//					void bezierCurveMove( const sf::Vector2f* points, const float& deltaTime );
//					void pathMove( const float& deltaTime );
//					virtual void update( const float& deltaTime ) override;
//					virtual void move( const sf::Vector2f& direction, const float& deltaTime ) override;
//					void lerpMove( const sf::Vector2f& destination, const float& deltaTime );
//					virtual void dive( const float& deltaTime );
// 
//	See also	:	EnemyManager
//#######################################################
class Enemy : public MoveableGameSprite
{
private:
	float									m_curveMove;			// Position across curve
	float									m_lerpMove;				// Position across lerp
	sf::Vector2f							m_defaultPos;			// Default position on screen
	EnemyStates								m_state;				// State the enemy is currently in
	std::vector<std::vector<sf::Vector2f>>	m_path;					// Path for the enemy to follow
	int										m_pathNode;				// What node on the path the enemy is currently on
	float									m_shotDelay;			// Time between each shot
	float									m_shotTimer;			// Timer to count time between shots
	bool									m_dived;				// Bool for if the enemy has dived
	bool									m_setPlayerDirection;	// Bool for if the player direction was set

public:
	//#######################################################
	//	Function	:	Enemy 
	//	Purpose		:	Enemy constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	Enemy();

	//#######################################################
	//	Function	:	Enemy 
	//	Purpose		:	Enemy constructor overload
	//	Parameters	:	sf::Texture& texture
	//					sf::Vector2f& scale
	//					sf::Vector2f& pos
	//					sf::Vector2f& defaultPos
	//					float speed
	//					const std::vector<std::vector<sf::Vector2f>>& path
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	Enemy( sf::Texture& texture, sf::Vector2f& scale, sf::Vector2f& pos, sf::Vector2f& defaultPos,
		   float speed, const std::vector<std::vector<sf::Vector2f>>& path );
	
	//#######################################################
	//	Function	:	~Enemy 
	//	Purpose		:	Enemy destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	virtual
	//	See also	:	
	//#######################################################
	virtual ~Enemy();

	//#######################################################
	//	Function	:	setDefultPos
	//	Purpose		:	Sets m_defultPos
	//	Parameters	:	const sf::Vector2f& pos
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void setDefultPos( const sf::Vector2f& pos );

	//#######################################################
	//	Function	:	getDefultPos
	//	Purpose		:	Gets m_defultPos
	//	Parameters	:	None
	//	Returns		:	const sf::Vector2f& pos
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const sf::Vector2f& getDefultPos();

	//#######################################################
	//	Function	:	setState
	//	Purpose		:	Sets m_state
	//	Parameters	:	const EnemyStates& state
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void setState( const EnemyStates& state );

	//#######################################################
	//	Function	:	getState
	//	Purpose		:	Gets m_state
	//	Parameters	:	None
	//	Returns		:	const EnemyStates& state
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const EnemyStates& getState();

	//#######################################################
	//	Function	:	setPath
	//	Purpose		:	Sets m_path
	//	Parameters	:	const std::vector<std::vector<sf::Vector2f>>& path
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void setPath( const std::vector<std::vector<sf::Vector2f>>& path );

	//#######################################################
	//	Function	:	getPath
	//	Purpose		:	Gets m_path
	//	Parameters	:	None
	//	Returns		:	const std::vector<std::vector<sf::Vector2f>>& path
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const std::vector<std::vector<sf::Vector2f>>& getPath();


	//#######################################################
	//	Function	:	setDived
	//	Purpose		:	Sets m_dived
	//	Parameters	:	const bool& dived
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void setDived( const bool& dived );

	//#######################################################
	//	Function	:	getDived
	//	Purpose		:	Gets m_dived
	//	Parameters	:	None
	//	Returns		:	const bool& dived
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const bool& getDived();

	//#######################################################
	//	Function	:	bezierCurveMove
	//	Purpose		:	Moves enemy across bezier curve
	//	Parameters	:	const sf::Vector2f& p0
	//					const sf::Vector2f& p1
	//					const sf::Vector2f& p2
	//					const sf::Vector2f& p3
	//					const float& deltaTime
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void bezierCurveMove( const sf::Vector2f& p0, const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Vector2f& p3, const float& deltaTime );
	
	//#######################################################
	//	Function	:	bezierCurveMove
	//	Purpose		:	Moves enemy across bezier curve
	//	Parameters	:	const sf::Vector2f* points
	//					const float& deltaTime
	//	Returns		:	void
	//	Notes		:	Overload using vector2 array
	//	See also	:	
	//#######################################################
	void bezierCurveMove( const sf::Vector2f* points, const float& deltaTime );

	//#######################################################
	//	Function	:	pathMove
	//	Purpose		:	Moves enemy across path
	//	Parameters	:	const float& deltaTime
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void pathMove( const float& deltaTime );

	//#######################################################
	//	Function	:	update
	//	Purpose		:	Updates enemy
	//	Parameters	:	const float& deltaTime	
	//					const sf::Vector2f& playerPos
	//					ProjectilePool& missilePool
	//	Returns		:	void
	//	Notes		:	virtual
	//	See also	:	
	//#######################################################
	virtual void update( const float& deltaTime, const sf::Vector2f& playerPos, ProjectilePool& missilePool );

	//#######################################################
	//	Function	:	move 
	//	Purpose		:	Moves enemy
	//	Parameters	:	const sf::Vector2f& direction
	//					const float& deltaTime
	//	Returns		:	void
	//	Notes		:	virtual override
	//	See also	:	
	//#######################################################
	virtual void move( const sf::Vector2f& direction, const float& deltaTime ) override;

	//#######################################################
	//	Function	:	lerpMove 
	//	Purpose		:	Lerps enemy
	//	Parameters	:	const sf::Vector2f& start
	//					const sf::Vector2f& destination
	//					const float& deltaTime
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void lerpMove( const sf::Vector2f& start, const sf::Vector2f& destination, const float& deltaTime );

	//#######################################################
	//	Function	:	dive 
	//	Purpose		:	Makes enemy dive
	//	Parameters	:	const float& deltaTime
	//	Returns		:	void
	//	Notes		:	virtual
	//	See also	:	
	//#######################################################
	virtual void dive( const float& deltaTime );
};


#endif // !ENEMY_H
