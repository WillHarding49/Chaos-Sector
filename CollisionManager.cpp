#include "CollisionManager.h"
#include "Helpers.h"

CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{

}

bool CollisionManager::collisionCheckCircles( const GameSprite& object1, const GameSprite& object2 )
{
	// distance between objects, squared
	float distanceSquared = Math::vectorDistanceSquared( object1.getPosition(), object2.getPosition() );
	
	// Get the average of half the sum of the width and height, which is 1/4 the sum when simplified
	// This acts as the radius of the object since it doesn't have a real circle collider, and this 
	// compensates for objects with one short and one long dimension
	float obj1Halves = ( object1.getGlobalBounds().width + object1.getGlobalBounds().height ) * 0.25f;
	float obj2Halves = ( object2.getGlobalBounds().width + object2.getGlobalBounds().height ) * 0.25f;

	float sumAverageHalves = obj1Halves + obj2Halves;

	// If the distance² < (the sum of the average halves)², then the objects are colliding
	return ( distanceSquared < ( sumAverageHalves * sumAverageHalves ) );
	
}

bool CollisionManager::collisionCheckRect( const GameSprite& object1, const GameSprite& object2 )
{
	// return if the rectangles of the objects intersect
	return( object1.getGlobalBounds().intersects( object2.getGlobalBounds() ) );
}

bool CollisionManager::checkPlayerProjectileCollisions( Projectile& projectile, Player& player )
{
	bool collided = false;

	// If a projectile collides with the player and the player did NOT fire it
	if( collisionCheckCircles( projectile, player ) && !projectile.getPlayerProjectile() )
	{
		// Set projectile to inactive
		projectile.setActive( false );

		collided = true;
	}

	return collided;
}

bool CollisionManager::checkEnemyProjectileCollisions( Projectile& projectile, EnemyManager& enemyManager )
{
	// Collided is false until made true so there are no false positives
	bool collided = false;

	// Loop through enemies
	for( int j = 0; j < enemyManager.getArraySize(); j++ )
	{
		// If enemy isn't nullptr and active
		if( enemyManager.getArray()[ j ] != nullptr && enemyManager.getArray()[ j ]->getActive() )
		{
			// If enemy collides with a projectile and it WAS fired by the player
			if( collisionCheckCircles( *enemyManager.getArray()[ j ], projectile ) && projectile.getPlayerProjectile() )
			{
				// Set enemy and projectile to inactive
				enemyManager.getArray()[ j ]->setActive( false );
				projectile.setActive( false );
				 
				collided = true;
				
				// Break since a collision has happened
				break;
			}
		}
	}

	return collided;
}

bool CollisionManager::checkEnemyPlayerCollisions( EnemyManager& enemyManager, Player& player)
{
	// Collided is false until made true so there are no false positives
	bool collided = false;

	// Loop through enemies
	for( int i = 0; i < enemyManager.getArraySize(); i++ )
	{
		// If enemy isn't nullptr and active
		if( enemyManager.getArray()[ i ] != nullptr && enemyManager.getArray()[ i ]->getActive() )
		{
			// If player collides with enemy
			if( collisionCheckCircles( player, *enemyManager.getArray()[ i ] ) )
			{
				// Set enemy to inactive
				enemyManager.getArray()[ i ]->setActive( false );
				
				collided = true;

				// Break since a collision has happened
				break;
			}
		}
	}

	return collided;
}
