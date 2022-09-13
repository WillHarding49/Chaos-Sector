#ifndef GAMESOUND
#define GAMESOUND

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

//#######################################################
//	class		:	GameSound
//	Purpose		:	Class for sound effects and music
//	Usage		:	Make new objects in game to play audio
//	Functions	:	GameSound();
//					~GameSound();
//					bool load( const char* fileName );
// 
//	See also	:	Sound
//#######################################################
class GameSound : public sf::Sound
{
private:
	sf::SoundBuffer m_buffer; // Where the audiofile is loaded to and played from

public:
	//#######################################################
	//	Function	:	GameSound 
	//	Purpose		:	GameSound constructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	GameSound();

	//#######################################################
	//	Function	:	~GameSound 
	//	Purpose		:	GameSound destructor
	//	Parameters	:	None
	//	Returns		:	void
	//	Notes		:	
	//	See also	:	
	//#######################################################
	~GameSound();

	//#######################################################
	//	Function	:	load 
	//	Purpose		:	Loads an audio wav file
	//	Parameters	:	const char* fontFileName
	//	Returns		:	bool loaded
	//	Notes		:	
	//	See also	:	
	//#######################################################
	bool load( const char* fileName );
};

#endif