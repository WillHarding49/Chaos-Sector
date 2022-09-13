#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "GameSound.h"
#include "Player.h"
#include "ProjectilePool.h"

//#######################################################
//	class		:	InputManager
//	Purpose		:	Manages inputs for player
//	Usage		:	Made in game and checks called in update
//	Functions	:	InputManager();
//					~InputManager();
//					void checkPlayerInputs( Player& player, ProjectilePool& missileManager, GameSound& shootSFX, const float& deltaTime );
//					
//	See also	:	player
//#######################################################
class InputManager
{
private:

public:
	//#######################################################
	//	Function	:	InputManager 
	//	Purpose		:	InputManager constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	InputManager();

	//#######################################################
	//	Function	:	~InputManager 
	//	Purpose		:	InputManager destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	~InputManager();

	//#######################################################
	//	Function	:	checkPlayerInputs 
	//	Purpose		:	checks inputs and calls functions for player
	//	Parameters	:	Player& player
	//					ProjectilePool& missileManager
	//					GameSound& shootSFX
	//					float deltaTime
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void checkPlayerInputs( Player& player, ProjectilePool& missileManager, GameSound& shootSFX, const float& deltaTime );

};

#endif // !INPUTMANAGER_H
