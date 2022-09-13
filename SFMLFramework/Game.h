#ifndef GAME_H
#define GAME_H

#include <SFML\System.hpp>

#include "Player.h"
#include "InputManager.h"
#include "MissilePool.h"
#include "EnemyManager.h"
#include "GameSound.h"
#include "TextureManager.h"
#include "FileManager.h"
#include "GameText.h"
#include "CollisionManager.h"
#include "Background.h"
#include "GameStates.h"

namespace sf
{
	class RenderWindow;
}

//class Missile;
//#######################################################
//	class		:	Game
//	Purpose		:	Manages gameObjects
//	Usage		:	Made in game and checks called in updates
//	Functions	:	void handleWindowsEvents();
//					void update( float deltaTime );
//					void updateGamePlay( const float& deltaTime );
//					void render();
//				 	void changeState( GameStates state );
// 					void enterState();
// 					void leaveState();
//					void reset( int numLives );
//					Game();
//					~Game();
//					void run();
// 
//	See also	:	
//#######################################################
class Game
{
private:
	sf::Context								 m_context;				// Gives a OpenGL context so textures can load in manager before window exits
	sf::RenderWindow*						 m_pWindow;				// The window in which the game is displayed
	sf::Clock								 m_clock;				// Clock to track timers
	int										 m_level;				// Current level
	TextureManager							 m_textureManager;		// Manager for textures
	Player									 m_player;				// Player ship
	InputManager							 m_inputManager;		// Manager for player inputs
	MissilePool								 m_missileManager;		// The object pooling 
	FileManager								 m_fileManager;			// Manager for files
	EnemyManager							 m_enemyManager;		// Manager for enemies
	GameSound								 m_bgMusic;				// Sound buffer for background music
	GameSound								 m_shootSFX;			// Sound buffer for shoot sound effect
	GameSound								 m_diveSFX;				// Sound buffer for enemy dives
	GameSound								 m_deathSFX;			// Sound buffer for death
	GameText								 m_menuText;			// Menu Text
	GameText								 m_menuText2;			// Another menu text
	GameText								 m_menuText3;			// Another menu text
	GameText								 m_scoreText;			// Text to display the score
	CollisionManager						 m_collisionManager;	// Manager for collisions
	Background								 m_background;			// Background object
	GameStates								 m_state;				// The current state of the game
	int										 m_score;				// The current score
	std::vector<std::pair<int, std::string>> m_leaderboard;			// The leaderboard score-name pairs
	sf::RectangleShape						 m_sidebarBG;			// A rectangle to give a background for the score and lives during gameplay

	//#######################################################
	//	Function	:	handleWindowsEvents 
	//	Purpose		:	Handles events for the game window
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void handleWindowsEvents();

	//#######################################################
	//	Function	:	update 
	//	Purpose		:	updates gameObjects and logic
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void update( float deltaTime );

	//#######################################################
	//	Function	:	updateGamePlay 
	//	Purpose		:	updates gameObjects and logic during gameplay
	//	Parameters	:	const float& deltaTime
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void updateGamePlay( const float& deltaTime );

	//#######################################################
	//	Function	:	render 
	//	Purpose		:	renders gameObejcts
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void render();

	//#######################################################
	//	Function	:	changeState 
	//	Purpose		:	Changes game state and calls enterState()
	//					and leaveState()
	//	Parameters	:	GameStates state
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void changeState( GameStates state );
	
	//#######################################################
	//	Function	:	enterState 
	//	Purpose		:	run code for when you enter a specific state
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void enterState();
	
	//#######################################################
	//	Function	:	leaveState 
	//	Purpose		:	run code for when you leave a specific state
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void leaveState();

	//#######################################################
	//	Function	:	reset 
	//	Purpose		:	resets gameObjects to make a new level
	//	Parameters	:	int numLives
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void reset( int numLives );

public:
	//#######################################################
	//	Function	:	Game 
	//	Purpose		:	Game constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	Game();

	//#######################################################
	//	Function	:	Game 
	//	Purpose		:	Game destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	~Game();

	//#######################################################
	//	Function	:	run 
	//	Purpose		:	calls update and render
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void run();


};

#endif // End of '#ifndef GAME_H'
