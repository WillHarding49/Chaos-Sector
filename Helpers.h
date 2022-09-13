#ifndef HELPERS_H
#define HELPERS_H

#include <cassert>
#include <math.h>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>

namespace Math
{
	const float k_pi		= 3.141592653589793238462f; // Value for pi
	const float k_1pi		= 0.318309886183790671538f; // Value for 1/pi
	const float k_tolerance = 0.00001f;					// Small float tolerance for comparisons

	//#######################################################
	//	Function	:	vectorDistance 
	//	Purpose		:	calculates distance between vectors
	//	Parameters	:	const sf::Vector2<T>& vector1
	//					const sf::Vector2<T>& vector2 
	//	Returns		:	const T
	//	Notes		:	Template, T is dataType
	//	See also	:	vectorDistanceSquared
	//#######################################################
	template<typename T>
	const T vectorDistance( const sf::Vector2<T>& vector1, const sf::Vector2<T>& vector2 )
	{
		T x = ( vector1.x - vector2.x );
		T y = ( vector1.y - vector2.y );

		return sqrt( x * x + y * y );
	}

	//#######################################################
	//	Function	:	vectorDistanceSquared 
	//	Purpose		:	calculates squared distance between vectors
	//	Parameters	:	const sf::Vector2<T>& vector1
	//					const sf::Vector2<T>& vector2 
	//	Returns		:	const T
	//	Notes		:	Template, T is dataType
	//	See also	:	vectorDistance
	//#######################################################
	template<typename T>
	const T vectorDistanceSquared( const sf::Vector2<T>& vector1, const sf::Vector2<T>& vector2 )
	{
		float x = ( vector2.x - vector1.x );
		float y = ( vector2.y - vector1.y );

		return ( x * x ) + ( y * y );
	}

	//#######################################################
	//	Function	:	normalise 
	//	Purpose		:	Makes vector length 1
	//	Parameters	:	const sf::Vector2<T>& vector
	//	Returns		:	sf::Vector2<T>
	//	Notes		:	Template, T is dataType
	//	See also	:	
	//#######################################################
	template<typename T>
	sf::Vector2<T> normalise( const sf::Vector2<T>& vector )
	{
		float magnitude = sqrtf( static_cast<float>( ( vector.x * vector.x ) + ( vector.y * vector.y ) ) );
		if( magnitude > Math::k_tolerance )
		{
			return ( vector / magnitude );
		}
		else
		{
			return vector;
		}
	}

	//#######################################################
	//	Function	:	clamp 
	//	Purpose		:	Restricts value to be between lower and higher
	//	Parameters	:	const T& value
	//					const T& lower
	//					const T& higer
	//	Returns		:	const T&
	//	Notes		:	Template, T is dataType
	//	See also	:	
	//#######################################################
	template<typename T>
	const T& clamp( const T& value, const T& lower, const T& higher )
	{
		assert( higher > lower );

		if( value < lower )
		{
			return lower;
		}
		else if( value > higher )
		{
			return higher;
		}
		else
		{
			return value;
		}
	}

	//#######################################################
	//	Function	:	CubicBezier 
	//	Purpose		:	Used to move something across a cubic bezier curve
	//	Parameters	:	const sf::Vector2f& point0
	//					const sf::Vector2f& point1
	//					const sf::Vector2f& point2
	//					const sf::Vector2f& point3
	//					float& t 
	//	Returns		:	const T&
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const sf::Vector2f CubicBezier( const sf::Vector2f& point0, const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3, float& t );
	
	//#######################################################
	//	Function	:	CubicBezier 
	//	Purpose		:	Used to move something across a cubic bezier curve
	//	Parameters	:	const sf::Vector2f* points
	//					float& t
	//	Returns		:	const T&
	//	Notes		:	Overload using array of points
	//	See also	:	
	//#######################################################
	const sf::Vector2f CubicBezier( const sf::Vector2f* points, float& t );

	//#######################################################
	//	Function	:	CubicBezierDer1 
	//	Purpose		:	Used to move calculate the 1st derivative
	//					of the bezier curve at point t
	//	Parameters	:	const sf::Vector2f& point0
	//					const sf::Vector2f& point1
	//					const sf::Vector2f& point2
	//					const sf::Vector2f& point3
	//					float& t 
	//	Returns		:	const T&
	//	Notes		:	
	//	See also	:	
	//#######################################################
	const sf::Vector2f CubicBezierDer1( const sf::Vector2f& point0, const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3, float& t );
	
	//#######################################################
	//	Function	:	CubicBezierDer1 
	//	Purpose		:	Used to move calculate the 1st derivative
	//					of the bezier curve at point t
	//	Parameters	:	const sf::Vector2f* points
	//					float& t
	//	Returns		:	const T&
	//	Notes		:	Overload using array of points
	//	See also	:	
	//#######################################################
	const sf::Vector2f CubicBezierDer1( const sf::Vector2f* points, float& t );

	//#######################################################
	//	Function	:	lerp 
	//	Purpose		:	Linear Interploates between 2 points
	//	Parameters	:	const sf::Vector2f& a
	//					const sf::Vector2f& b
	//					float& t 
	//	Returns		:	sf::Vector2f
	//	Notes		:	
	//	See also	:	
	//#######################################################
	sf::Vector2f lerp( const sf::Vector2f& a, const sf::Vector2f& b, float t );

	//#######################################################
	//	Function	:	lerp 
	//	Purpose		:	Linear Interploates between 2 points
	//	Parameters	:	const sf::Vector3f& a
	//					const sf::Vector3f& b
	//					float& t 
	//	Returns		:	sf::Vector3f
	//	Notes		:	Overload using Vector3
	//	See also	:	
	//#######################################################
	sf::Vector3f lerp( const sf::Vector3f& a, const sf::Vector3f& b, float t );

	//#######################################################
	//	Function	:	lerp3 
	//	Purpose		:	Linear Interploates between 3 points
	//	Parameters	:	const sf::Vector2f& a
	//					const sf::Vector2f& b
	//					const sf::Vector2f& c
	//					float& t 
	//	Returns		:	sf::Vector2f
	//	Notes		:	
	//	See also	:	
	//#######################################################
	sf::Vector2f lerp3( const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& c, float t );

	//#######################################################
	//	Function	:	lerp3 
	//	Purpose		:	Linear Interploates between 3 points
	//	Parameters	:	const sf::Vector3f& a
	//					const sf::Vector3f& b
	//					const sf::Vector3f& c
	//					float& t 
	//	Returns		:	sf::Vector3f
	//	Notes		:	Overload using Vector3
	//	See also	:	
	//#######################################################
	sf::Vector3f lerp3( const sf::Vector3f& a, const sf::Vector3f& b, const sf::Vector3f& c, float t );

	//#######################################################
	//	Function	:	lerp3ReturnBack 
	//	Purpose		:	Linear Interploates between 3 points
	//					and returns to point a
	//	Parameters	:	const sf::Vector2f& a
	//					const sf::Vector2f& b
	//					const sf::Vector2f& c
	//					float& t 
	//	Returns		:	sf::Vector2f
	//	Notes		:	
	//	See also	:	
	//#######################################################
	sf::Vector2f lerp3ReturnBack( const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& c, float t );

	//#######################################################
	//	Function	:	lerp3ReturnBack 
	//	Purpose		:	Linear Interploates between 3 points
	//					and returns to point a
	//	Parameters	:	const sf::Vector3f& a
	//					const sf::Vector3f& b
	//					const sf::Vector3f& c
	//					float& t 
	//	Returns		:	sf::Vector3f
	//	Notes		:	Overload using Vector3
	//	See also	:	
	//#######################################################
	sf::Vector3f lerp3ReturnBack( const sf::Vector3f& a, const sf::Vector3f& b, const sf::Vector3f& c, float t );

	//#######################################################
	//	Function	:	lerp2ReturnBack 
	//	Purpose		:	Linear Interploates between 2 points
	//					and returns to point a
	//	Parameters	:	const sf::Vector3f& a
	//					const sf::Vector3f& b
	//					float& t 
	//	Returns		:	sf::Vector2f
	//	Notes		:	
	//	See also	:	
	//#######################################################
	//sf::Vector2f lerpReturnBack( const sf::Vector2f& a, const sf::Vector2f& b, float t );

	//#######################################################
	//	Function	:	floatsEqual 
	//	Purpose		:	Checks if two floats are equal within a
	//					small tolerance
	//	Parameters	:	float a
	//					float b
	//	Returns		:	bool
	//	Notes		:	
	//	See also	:	
	//#######################################################
	bool floatsEqual( float a, float b );
}

#ifdef _DEBUG
#define ASSERT(a) assert(a)
#else
#define ASSERT(a)
#endif // _DEBUG

//#######################################################
//	Function	:	safeDeletePointer 
//	Purpose		:	Deletes pointer
//	Parameters	:	T*& a
//	Returns		:	void
//	Notes		:	Template, T is dataType
//	See also	:	
//#######################################################
template<typename T>
void safeDeletePointer( T*& a )
{
	if( a )
	{	
		delete a;
		a = nullptr;
	}
}

//#######################################################
//	Function	:	safeDeletePointerArray 
//	Purpose		:	Deletes pointer array
//	Parameters	:	T*& a
//	Returns		:	void
//	Notes		:	Template, T is dataType
//	See also	:	
//#######################################################
template<typename T>
void safeDeleteArray( T*& a )
{
	if( a )
	{
		delete[] a;
		a = nullptr;
	}
}

#endif // End of '#ifndef HELPERS_H'
