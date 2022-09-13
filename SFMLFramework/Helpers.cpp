#include "Helpers.h"
#include "Settings.h"

namespace Math
{

	const sf::Vector2f CubicBezier( const sf::Vector2f& point0, const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3, float& t )
	{
		// Clamps t value between 0 and 1
		t = clamp( t, 0.0f, 1.0f );

		// var for 1 - t to make return cleaner
		float oneSubT = 1 - t;

		// var for ( 1 - t )² to not use powers and also to make return cleaner
		float oneSubTSquared = oneSubT * oneSubT;

		// return B(t) = (1 - t)³P0 + 3(1 - t)²tP1 + 3(1 - t)t²P2 + t³P3, the explicit equation of a cubic Bézier curve
		return ( ( oneSubTSquared * oneSubT ) * point0 ) + ( (3 * oneSubTSquared * t) * point1 ) + (3 * oneSubT * ( t * t ) * point2 ) + ( ( t * t * t ) * point3 );
	}

	const sf::Vector2f CubicBezier( const sf::Vector2f* points, float& t )
	{		
		// Clamps t value between 0 and 1
		t = clamp( t, 0.0f, 1.0f );

		// var for 1 - t to make return cleaner
		float oneSubT = 1 - t;

		// var for ( 1 - t )² to not use powers and also to make return cleaner
		float oneSubTSquared = oneSubT * oneSubT;

		// return B(t) = (1 - t)³P0 + 3(1 - t)²tP1 + 3(1 - t)t²P2 + t³P3, the explicit equation of a cubic Bézier curve 
		return ( ( oneSubTSquared * oneSubT ) * points[ 0 ] ) + ( ( 3 * oneSubTSquared * t ) * points[ 1 ] ) + ( 3 * oneSubT * ( t * t ) * points[ 2 ] ) + ( ( t * t * t ) * points[ 3 ] );
	}

	const sf::Vector2f CubicBezierDer1( const sf::Vector2f& point0, const sf::Vector2f& point1, const sf::Vector2f& point2, const sf::Vector2f& point3, float& t )
	{
		// Clamps t value between 0 and 1
		t = clamp( t, 0.0f, 1.0f );

		// var for 1 - t to make return cleaner
		float oneSubT = 1 - t;

		// var for ( 1 - t )² to not use powers and also to make return cleaner
		float oneSubTSquared = oneSubT * oneSubT;

		// return B'(t) = 3(1 - t)²(P1 - P0) + 6(1 - t)t(P2 - P1) + 3t²(P3 - P2), the first derivitive of the Bézier curve equation
		return 3.0f * oneSubTSquared * ( point1 - point0 ) + 6.0f * oneSubT * t * ( point2 - point1 ) + 3.0f * (t * t) * ( point3 - point2 );
	}

	const sf::Vector2f CubicBezierDer1( const sf::Vector2f* points, float& t )
	{
		// Clamps t value between 0 and 1
		t = clamp( t, 0.0f, 1.0f );

		// var for 1 - t to make return cleaner
		float oneSubT = 1 - t;

		// var for ( 1 - t )² to not use powers and also to make return cleaner
		float oneSubTSquared = oneSubT * oneSubT;

		// return B'(t) = 3(1 - t)²(P1 - P0) + 6(1 - t)t(P2 - P1) + 3t²(P3 - P2), the first derivitive of the Bézier curve equation
		return 3.0f * oneSubTSquared * ( points[1] - points[0] ) + 6.0f * oneSubT * t * ( points[2] - points[1] ) + 3.0f * ( t * t ) * ( points[3] - points[2] );
	}

	sf::Vector2f lerp( const sf::Vector2f& a, const sf::Vector2f& b, float t )
	{
		// Clamps t value between 0 and 1
		t = clamp( t, 0.0f, 1.0f );

		// return lerp point at t
		return a + ( b - a ) * t;
	}

	sf::Vector3f lerp( const sf::Vector3f& a, const sf::Vector3f& b, float t )
	{
		// Clamps t value between 0 and 1
		t = clamp( t, 0.0f, 1.0f );

		// return lerp point at t
		return a + ( b - a ) * t;
	}

	sf::Vector2f lerp3( const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& c, float t )
	{
		// For the 1st half of the lerp
		if( t <= 0.5f )
		{
			// Lerp between a & b using 2t
			// Since we're only using t values 0-0.5 here, t needs to be doubled to lerp properly
			return lerp( a, b, t * 2.0f );
		}
		// For the 2nd half of the lerp
		else
		{
			// Lerp between b & c using 2t - 1
			// Since we're only using t values 0.5-1 here, t needs to be doubled and offset by 1 to lerp properly
			return lerp( b, c, t * 2.0f - 1 );
		}
	}

	sf::Vector3f lerp3( const sf::Vector3f& a, const sf::Vector3f& b, const sf::Vector3f& c, float t )
	{
		// For the 1st half of the lerp
		if( t <= 0.5f )
		{
			// Lerp between a & b using 2t
			// Since we're only using t values 0-0.5 here, t needs to be doubled to lerp properly
			return lerp( a, b, t * 2.0f );
		}
		// For the 2nd half of the lerp
		else
		{
			// Lerp between b & c using 2t - 1
			// Since we're only using t values 0.5-1 here, t needs to be doubled and offset by 1 to lerp properly
			return lerp( b, c, t * 2.0f - 1 );
		}
	}

	sf::Vector2f lerp3ReturnBack( const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& c, float t )
	{
		// For the first 1/3 of the lerp
		if( t <= 0.333f )
		{
			// Lerp between a & b using 3t
			// Since we're only using t values 0-0.33 here, t needs to be tripled to lerp properly
			return lerp( a, b, t * 3.0f );
		}
		// For the second 1/3 of the lerp
		else if( t > 0.333f && t <= 0.666f )
		{
			// Lerp between b & c using 3t - 1
			// Since we're only using t values 0.33-0.66 here, t needs to be tripled and offset by 1 to lerp properly
			return lerp( b, c, t * 3.0f - 1 );
		}
		//For the final 1/3 of the lerp
		else
		{
			// Lerp between b & c using 3t - 2
			// Since we're only using t values 0.66-1 here, t needs to be tripled and offset by 2 to lerp properly
			return lerp( c, a, t * 3.0f - 2 );
		}
	}

	sf::Vector3f lerp3ReturnBack( const sf::Vector3f& a, const sf::Vector3f& b, const sf::Vector3f& c, float t )
	{
		// For the first 1/3 of the lerp
		if( t <= 0.333f )
		{
			// Lerp between a & b using 3t
			// Since we're only using t values 0-0.33 here, t needs to be tripled to lerp properly
			return lerp( a, b, t * 3.0f );
		}
		// For the second 1/3 of the lerp
		else if( t > 0.333f && t <= 0.666f )
		{
			// Lerp between b & c using 3t - 1
			// Since we're only using t values 0.33-0.66 here, t needs to be tripled and offset by 1 to lerp properly
			return lerp( b, c, t * 3.0f - 1 );
		}
		//For the final 1/3 of the lerp
		else
		{
			// Lerp between b & c using 3t - 2
			// Since we're only using t values 0.66-1 here, t needs to be tripled and offset by 2 to lerp properly
			return lerp( c, a, t * 3.0f - 2 );
		}
	}


	//sf::Vector2f lerpReturnBack( const sf::Vector2f& a, const sf::Vector2f& b, float t )
	//{
	//	return sf::Vector2f();
	//}

	bool floatsEqual( float a, float b )
	{
		// checks if the difference between the absolute values of a and b <= the tolerance
		return std::abs( a - b ) <= Math::k_tolerance;
	}
}

