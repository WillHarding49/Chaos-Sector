#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/System/Vector2.hpp>

#include "GameSound.h"
#include "MoveableGameSprite.h"
#include "ProjectilePool.h"
#include "Settings.h"


//#######################################################
//	class		:	Player
//	Purpose		:	Player that can move and shoot
//	Usage		:	Made in Game
//	Functions	:	Player();
// 					Player( const sf::Texture& texture, const sf::Vector2f& scale, const sf::Vector2f& pos, float speed, int lives );
//					virtual ~Player();
// 					void setLives( const int& lives );
// 					const int& getLives() const;
// 					void reduceLives();
// 					void reset( const sf::Vector2f& pos, int lives );
// 					void update( const float& deltaTime );
//					virtual void move( const sf::Vector2f& direction, const float& deltaTime ) override;
//					void shoot( ProjectilePool& missileManager, GameSound& shootSFX );
//					
//	See also	:	GameSprite
//#######################################################
class Player : public MoveableGameSprite
{
private:
	bool	m_missileFired;		// Bool for if player has fired missile
	float	m_missileCooldown;	// Timer for cooldown between missiles fired
	int		m_lives;			// Number of lives

public:

	//#######################################################
	//	Function	:	Player 
	//	Purpose		:	Player constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	Player();

	//#######################################################
	//	Function	:	Player 
	//	Purpose		:	Player constructor overload
	//	Parameters	:	const sf::Texture& texture
	//					const sf::Vector2f& scale
	//					const sf::Vector2f& pos
	//					float speed
	//					int lives
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	Player( const sf::Texture& texture, const sf::Vector2f& scale, const sf::Vector2f& pos, float speed, int lives );

	//#######################################################
	//	Function	:	~Player 
	//	Purpose		:	Player destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	virtual
	//	See also	:	
	//#######################################################
	virtual ~Player();

	//#######################################################
	//	Function	:	setLives
	//	Purpose		:	Sets m_lives
	//	Parameters	:	const int& lives
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void setLives( const int& lives );

	//#######################################################
	//	Function	:	getLives
	//	Purpose		:	Gets m_lives
	//	Parameters	:	None
	//	Returns		:	const int& lives
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const int& getLives() const;

	//#######################################################
	//	Function	:	reduceLives
	//	Purpose		:	Reduces m_lives by 1
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void reduceLives();

	//#######################################################
	//	Function	:	reset
	//	Purpose		:	Resets player for new level/game
	//	Parameters	:	const sf::Vector2f& pos
	//					int lives
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void reset( const sf::Vector2f& pos, int lives );

	//#######################################################
	//	Function	:	update
	//	Purpose		:	Updates player
	//	Parameters	:	const float& deltaTime
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void update( const float& deltaTime );

	//#######################################################
	//	Function	:	move 
	//	Purpose		:	Moves player
	//	Parameters	:	const sf::Vector2f& direction
	//					const float& deltaTime
	//	Returns		:	void
	//	Notes		:	virtual override
	//	See also	:	
	//#######################################################
	virtual void move( const sf::Vector2f& direction, const float& deltaTime ) override;

	//#######################################################
	//	Function	:	shoot 
	//	Purpose		:	shoots projectile
	//	Parameters	:	ProjectilePool& missileManager
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void shoot( ProjectilePool& missileManager, GameSound& shootSFX );
};

#endif // !PLAYER_H

