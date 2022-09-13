#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <vector>

//#######################################################
//	class		:	FileManager
//	Purpose		:	Class for loading and managing files
//	Usage		:	Make in game
//	Functions	:	FileManager();
//					~FileManager();
// 					std::string* getEnemyArrays();
//					void makeEnemyArrays();
//					std::vector<std::pair<int, std::string>> getLeaderboard();
//					void setLeaderboard( std::vector<std::pair<int, std::string>> leaderboard );
// 
//	See also	:	
//#######################################################
class FileManager
{
private:
	std::string* m_enemyArrays; // Array of string templates of enemy layouts for each level


public:
	//#######################################################
	//	Function	:	FileManager 
	//	Purpose		:	FileManager constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	FileManager();

	//#######################################################
	//	Function	:	~FileManager 
	//	Purpose		:	FileManager destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	~FileManager();

	//#######################################################
	//	Function	:	getEnemyArrays
	//	Purpose		:	Returns the array of enemy layout strings
	//	Parameters	:	None
	//	Returns		:	std::string* enemy layouts array
	//	Notes		:	
	//	See also	:	
	//#######################################################
	std::string* getEnemyArrays();

	//#######################################################
	//	Function	:	makeEnemyArrays
	//	Purpose		:	Converts text file contents to string for 
	//					loading enemy layouts
	//	Parameters	:	None
	//	Returns		:	void 
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void makeEnemyArrays();
	
	//#######################################################
	//	Function	:	getLeaderboard
	//	Purpose		:	Reads leaderboard file and returns the
	//					leaderboard player-score entries
	//	Parameters	:	None
	//	Returns		:	std::vector<std::pair<int, std::string>> leaderboard 
	//	Notes		:	
	//	See also	:	
	//#######################################################
	std::vector<std::pair<int, std::string>> getLeaderboard();

	//#######################################################
	//	Function	:	setLeaderboard
	//	Purpose		:	Writes leaderboard to file
	//	Parameters	:	std::vector<std::pair<int, std::string>> leaderboard
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	void setLeaderboard( std::vector<std::pair<int, std::string>> leaderboard );
};

#endif // !FILEMANAGER_H
