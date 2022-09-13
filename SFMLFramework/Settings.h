#ifndef SETTINGS_H
#define SETTINGS_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

#include <string>
#include <vector>

namespace Settings
{
	//Audio
	// const used twice here to make the pointer value and the pointer itself const
	const char* const k_bgMusic = "Assets/Audio/BGSong.wav";
	const char* const k_shootSound = "Assets/Audio/shoot.wav";
	const char* const k_diveSound = "Assets/Audio/dive.wav";
	const char* const k_deathSound = "Assets/Audio/death.wav";


	// Textures
	// const used twice here to make the pointer value and the pointer itself const
	const char* const k_playerTexture = "Assets/Textures/Player_Ship.PNG";
	const char* const k_missileTexture = "Assets/Textures/Missiles.PNG";
	const char* const k_ufoShipTexture = "Assets/Textures/UFO_Ship.PNG";
	const char* const k_sphereShipTexture = "Assets/Textures/Sphere_Ship.PNG";
	const char* const k_ringShipTexture = "Assets/Textures/Ring_Ship.PNG";
	const char* const k_backgoundTexture = "Assets/Textures/Background_Sheet_Extra.PNG";

	// Font
	const char* const k_font = "Assets/Fonts/emulogic.ttf";


	// IntRects of sections of textures for loading the correct textures
	const sf::IntRect k_playerMissileRect( 0, 0, 620, 1059 );
	const sf::IntRect k_enemyMissileRect(620, 0, 1240, 1059 );


	// Speeds
	const float k_playerSpeed = 500.0f;
	const float k_missileSpeed = 300.0f;
	const float k_enemySpeed = 500;

	// Player movement damping
	const float k_dampingMultiplier = 0.75f;

	// Window size
	const sf::Vector2i k_windowSize( 1400, 800 );
	const sf::Vector2i k_playAreaSize( 1200, 800 );


	// Player bounds on the screen
	const sf::Vector2f k_playerBoundsMin( 0, 500.0f );
	const sf::Vector2f k_playerBoundsMax( static_cast<float>( k_playAreaSize.x ), static_cast< float >( k_playAreaSize.y ) );


	// Start Positions
	const sf::Vector2f k_playerStartPos( 600, 600 );
	const sf::Vector2f k_outOfBoundsPos( 500, -100 );


	// Framerate
	const int k_framerate = 60;


	// Scales
	const sf::Vector2f k_playerScale( 0.05f, 0.05f );
	const sf::Vector2f k_enemyScale( 0.05f, 0.05f );
	const sf::Vector2f k_missileScale( 0.025f, 0.025f );


	// Timer limits
	const float k_missileCooldownLength = 0.3f;
	const float k_enemyFormationDelay = 0.15f;
	const float k_enemyDiveDelay = 3.0f;
	const float k_invincibilityTime = 3.0f;

	// Max number of missiles on the screen
	const int k_maxMissiles = 25;

	// Number of lives the player starts with
	const int k_playerLives = 3;

	// Number of levels in the game
	const int k_levelAmount = 5;


	// Display spacings
	const float k_enemyArraySpaceMultiplier = 100.0f;
	const sf::Vector2f k_enemyArraySpacing( 150.0f, 50.0f );

	// Max number of leaderboard entries to save and display
	const int k_leaderboardMaxLength = 10;

	// Amount of digits to display on leaderboard
	const int k_leaderboardDigits = 5;


	// Enemy and enemy manager  misc. consts
	
	// Number of columns and rows in the enemy array
	const sf::Vector2i k_enemyGrid( 10, 5 );

	// Number of entrance formations per level, and enemies per formation group
	const sf::Vector2i k_enemyFromations [ k_levelAmount ] = { sf::Vector2i( 1, 10 ), sf::Vector2i( 2, 10 ), sf::Vector2i( 3, 10 ), sf::Vector2i( 4, 10 ), sf::Vector2i( 5, 8 ) };
	
	// Default array template for displaying enemies
	const std::string k_defaultEnemyArray = "x  x  x  A2 A2 A2 A2 x  x  x\nx  A3 A3 A2 A1 A1 A2 A3 A3 x\nx  A3 A3 A2 A1 A1 A2 A3 A3 x\nA5 A5 A4 A4 A1 A1 A4 A4 A5 A5\nA5 A5 A4 A4 A1 A1 A4 A4 A5 A5";

	// Random range and start point for enemy shooting timer delay
	const sf::Vector2i k_enemyShootDelay( 10, 5 );

}

#endif // !SETTINGS_H
