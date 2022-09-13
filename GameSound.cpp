#include "GameSound.h"
#include "Helpers.h"

GameSound::GameSound()
{

}

GameSound::~GameSound()
{

}

bool GameSound::load( const char* fileName )
{
	// Load sound
	bool loaded = m_buffer.loadFromFile( fileName );
	ASSERT( loaded == true );

	// set sound to buffer
	setBuffer( m_buffer );

	return loaded;
}
