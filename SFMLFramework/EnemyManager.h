#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H

#include "Enemy.h"

#include <vector>
#include "TextureManager.h"
#include "EnemyManagerStates.h"
#include "GameSound.h"

//#######################################################
//	class		:	EnemyManager
//	Purpose		:	Manager for enemies
//	Usage		:	Make in game and call update and render
//	Functions	:	EnemyManager();
// 					EnemyManager( const sf::Vector2i& arraySize, const sf::Vector2i& formationSize, const std::string& arrayTemplate );
//					virtual ~EnemyManager();
// 					const int getArraySize() const;
// 					std::vector<Enemy*>& getArray();
// 					void makeNewLevel( const sf::Vector2i& arraySize, const sf::Vector2i& formationSize,
//									   std::string& levelArray, TextureManager& textureManager, 
//									   std::vector<std::vector<std::vector<sf::Vector2f>>>& entrancePaths );
// 					bool checkAllEnemiesDead();
// 					void makeArray( TextureManager& textureManager );
// 					bool checkFormationCompleteEntrance();
//					void sendOutFormations( const float& deltaTime );
// 					void update( const sf::Vector2f& playerPos, ProjectilePool& missilePool, GameSound& diveSound, const float& deltaTime );
// 					void render( sf::RenderWindow& window );
// 
//	See also	:	Enemy
//#######################################################
class EnemyManager
{
private:
	std::vector<Enemy*>										m_pEnemyArray;			// Array of all the enemies
	std::vector<std::vector<int>>							m_formationIndexes;		// 2D vector containing the indexes of the enemies in the array
	std::string												m_levelArray;			// the shape of the array taken from a text file
	sf::Vector2i											m_arraySize;			// Size of the enemy array
	sf::Vector2i											m_formationSize;		// Size of the formation vector, and the size and number of each entrance formation
	int														m_activeFormation;		// What formation is currently doing their entrance
	float													m_enemyTimer;			// Timer for sending in enemies to do their entrances
	bool													m_formationComplete;	// Bool for if the current entrance formation has completed its entrance dive
	EnemyManagerStates										m_state;				// State the enemies as a collective are in
	std::vector<std::vector<std::vector<sf::Vector2f>>>		m_entracePaths;			// Array of entance paths

public:
	//#######################################################
	//	Function	:	EnemyManager 
	//	Purpose		:	EnemyManager constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	EnemyManager();

	//#######################################################
	//	Function	:	EnemyManager 
	//	Purpose		:	EnemyManager constructor overload
	//	Parameters	:	const sf::Vector2i& arraySize
	//					const sf::Vector2i& formationSize
	//					const std::string& arrayTemplate
	//					TextureManager& textureManager
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	EnemyManager( const sf::Vector2i& arraySize, const sf::Vector2i& formationSize, const std::string& arrayTemplate );

	//#######################################################
	//	Function	:	~EnemyManager 
	//	Purpose		:	EnemyManager destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	~EnemyManager();

	//#######################################################
	//	Function	:	getArraySize
	//	Purpose		:	Gets m_arraySize
	//	Parameters	:	None
	//	Returns		:	const int arraySize
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const int getArraySize() const;

	//#######################################################
	//	Function	:	getArray
	//	Purpose		:	Gets m_pEnemyArray
	//	Parameters	:	None
	//	Returns		:	std::vector<Enemy*>& enemyArray
	//	Notes		:	
	//	See also	:	
	//#######################################################
	std::vector<Enemy*>& getArray();

	//#######################################################
	//	Function	:	makeNewLevel
	//	Purpose		:	Resets all containers and makes new enemy array
	//	Parameters	:	const sf::Vector2i& arraySize
	//					const sf::Vector2i& formationSize
	//					std::string& levelArray
	//					TextureManager& textureManager
	//					std::vector<std::vector<std::vector<sf::Vector2f>>>& entrancePaths
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void makeNewLevel( const sf::Vector2i& arraySize, const sf::Vector2i& formationSize,
					   std::string& levelArray, TextureManager& textureManager,
					   std::vector<std::vector<std::vector<sf::Vector2f>>>& entrancePaths );

	//#######################################################
	//	Function	:	checkAllEnemiesDead
	//	Purpose		:	Checks if all the enemies are inactive
	//	Parameters	:	None
	//	Returns		:	bool
	//	Notes		:	
	//	See also	:	
	//#######################################################
	bool checkAllEnemiesDead();

	//#######################################################
	//	Function	:	makeArray
	//	Purpose		:	Makes enemy array and fills formations
	//					vector based on level template
	//	Parameters	:	TextureManager& textureManager
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void makeArray( TextureManager& textureManager );

	//#######################################################
	//	Function	:	checkFormationCompleteEntrance
	//	Purpose		:	Checks if the current entrance formation
	//					has completed its entrance dive
	//	Parameters	:	None
	//	Returns		:	bool
	//	Notes		:	
	//	See also	:	
	//#######################################################
	bool checkFormationCompleteEntrance();

	//#######################################################
	//	Function	:	sendOutFormations
	//	Purpose		:	Sends out next entrance formation
	//	Parameters	:	const float& deltaTime
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void sendOutFormations( const float& deltaTime );

	//#######################################################
	//	Function	:	update
	//	Purpose		:	Updates all enemies
	//	Parameters	:	const sf::Vector2f& playerPos
	//					ProjectilePool& missilePool
	//					GameSound& diveSound
	//					const float& deltaTime
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void update( const sf::Vector2f& playerPos, ProjectilePool& missilePool, GameSound& diveSound, const float& deltaTime );

	//#######################################################
	//	Function	:	render
	//	Purpose		:	Calls render for each enemy in array
	//	Parameters	:	sf::RenderWindow& window
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void render( sf::RenderWindow& window );

};

#endif // !ENEMYMANAGER_H
