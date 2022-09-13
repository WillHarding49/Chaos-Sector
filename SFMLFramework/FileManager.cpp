#include <fstream>	// For std::ifstream and std::ofstream             
#include <string>

#include "FileManager.h"
#include "Helpers.h"
#include "Settings.h"

FileManager::FileManager()
	: m_enemyArrays	( nullptr )
{
	// Makes array
	m_enemyArrays = new std::string[ Settings::k_levelAmount ];
	makeEnemyArrays();
}

FileManager::~FileManager()
{
	safeDeleteArray( m_enemyArrays );
}

std::string* FileManager::getEnemyArrays()
{
	return m_enemyArrays;
}

void FileManager::makeEnemyArrays()
{
	// For the number of levels
	for( int i = 1; i <= Settings::k_levelAmount; i++ )
	{
		std::ifstream levelFile;

		// Open file with fileName
		std::string fileName = "Assets/Level Formations/Level" + std::to_string( i ) + ".txt";
		levelFile.open( fileName );

		std::string enemyRow;	// For single line of text
		std::string fullArray;	// Storage for ALL lines of text
		if( levelFile.is_open() )
		{
			// Opened the file for reading successfully
			while( std::getline( levelFile, enemyRow ) )
			{
				//Add each enemy row to the full array of text with a \n at the end
				fullArray += enemyRow;
				fullArray += "\n";
			}
			levelFile.close();

			// Add fullArray to the enemy template list once complete
			m_enemyArrays[ i - 1 ] = fullArray;
		}
		else
		{
			// Couldn't open that file!
			std::cout << "Couldn't open that file!" << "\n";
		}
	}
	
}

std::vector<std::pair<int, std::string>> FileManager::getLeaderboard()
{
	// score-name pair for leaderboard
	std::vector<std::pair<int, std::string>> leaderboard;

	std::ifstream leaderboardFile;

	// Open file with fileName
	std::string fileName = "Assets/Leaderboard.txt";
	leaderboardFile.open( fileName );

	int score;
	std::string name;

	std::string entry;	// For single line of text
	
	if( leaderboardFile.is_open() )
	{
		// Opened the file for reading successfully
		while( std::getline( leaderboardFile, entry ) )
		{
			// If the line of text is not empty
			if( !entry.empty() )
			{
				// Find the position of the space in the string
				int i = entry.find( ' ' );

				// Get the score, the string up until the space converted to an int
				score = std::stoi( entry.substr( 0, i + 1 ) );

				// The name is the rest of the string
				name += entry.substr( i + 1 );

				// Add the score-name pair to the leaderboard vector
				leaderboard.push_back( std::make_pair( score, name ) );
				name = "";
			}

		}
		leaderboardFile.close();
	}
	else
	{
		// Couldn't open that file!
		std::cout << "Couldn't open that file!" << "\n";
	}

	// Sort leaderboard by descending score
	std::sort( leaderboard.begin(), leaderboard.end(), std::greater<>() );

	// If the leaderboard is greater than the max size it can be
	if( leaderboard.size() > Settings::k_leaderboardMaxLength )
	{
		// Resize to the max length
		leaderboard.resize( Settings::k_leaderboardMaxLength );
	}

	return leaderboard;

}

void FileManager::setLeaderboard( std::vector<std::pair<int, std::string>> leaderboard )
{
	// Sort leaderboard, score descending
	std::sort( leaderboard.begin(), leaderboard.end(), std::greater<>() );

	std::ofstream leaderboardFile;

	// Open file with fileName
	std::string fileName = "Assets/Leaderboard.txt";
	leaderboardFile.open( fileName );

	if( leaderboardFile.is_open() )
	{
		// Loop through leaderboard
		for( int i = 0; i < static_cast< int >( leaderboard.size() ); i++ )
		{
			// Write "[score] [name]" to the fil
			leaderboardFile << leaderboard[ i ].first << " " << leaderboard[ i ].second << "\n";
		}
		leaderboardFile.close();
	}
	else
	{
		// Couldn't open that file!
		std::cout << "Couldn't open that file!" << "\n";
	}
}
