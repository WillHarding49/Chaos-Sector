#ifndef CURVESANDPATHS_H
#define CURVESANDPATHS_H

#include <SFML/System/Vector2.hpp>
#include <vector>

#include "Settings.h"

namespace BezierCurve
{
	const std::vector<sf::Vector2f> k_halfHeartLeftEnter = { sf::Vector2f( 960, 500 ), sf::Vector2f( 1080, 700 ), sf::Vector2f( 720, 700 ), sf::Vector2f( 720, 500 ) };
	const std::vector<sf::Vector2f> k_halfHeartRightEnter = { sf::Vector2f( 240, 500 ), sf::Vector2f( 120, 700 ), sf::Vector2f( 480, 700 ), sf::Vector2f( 480, 500 ) };


	const std::vector<sf::Vector2f> k_loopLeftHalf1 = { sf::Vector2f( 480, 500 ), sf::Vector2f( 480, 200 ), sf::Vector2f( 120, 200 ), sf::Vector2f( 120, 500 ) };
	const std::vector<sf::Vector2f> k_loopLeftHalf2 = { sf::Vector2f( 120, 500 ), sf::Vector2f( 120, 800 ), sf::Vector2f( 480, 800 ), sf::Vector2f( 480, 500 ) };

	const std::vector<sf::Vector2f> k_loopLeftReversedHalf1 = { sf::Vector2f( 120, 500 ), sf::Vector2f( 120, 200 ), sf::Vector2f( 480, 200 ), sf::Vector2f( 480, 500 ) };
	const std::vector<sf::Vector2f> k_loopLeftReversedHalf2 = { sf::Vector2f( 480, 500 ), sf::Vector2f( 480, 800 ), sf::Vector2f( 120, 800 ), sf::Vector2f( 120, 500 ) };

	const std::vector<sf::Vector2f> k_loopRightHalf1 = { sf::Vector2f( 720, 500 ), sf::Vector2f( 720, 200 ), sf::Vector2f( 1080, 200 ), sf::Vector2f( 1080, 500 ) };
	const std::vector<sf::Vector2f> k_loopRightHalf2 = { sf::Vector2f( 1080, 500 ), sf::Vector2f( 1080, 800 ), sf::Vector2f( 720, 800 ), sf::Vector2f( 720, 500 ) };

	const std::vector<sf::Vector2f> k_loopRightReversedHalf1 = { sf::Vector2f( 1080, 500 ), sf::Vector2f( 1080, 200 ), sf::Vector2f( 720, 200 ), sf::Vector2f( 720, 500 ) };
	const std::vector<sf::Vector2f> k_loopRightReversedHalf2 = { sf::Vector2f( 720, 500 ), sf::Vector2f( 720, 800 ), sf::Vector2f( 1080, 800 ), sf::Vector2f( 1080, 500 ) };

	const std::vector<sf::Vector2f> k_cCurve = { sf::Vector2f( 180, 500 ), sf::Vector2f( 60, 600 ), sf::Vector2f( 192, 700 ), sf::Vector2f( 300, 600 ) };
	const std::vector<sf::Vector2f> k_cCurveReversed = { sf::Vector2f( 1020, 500 ), sf::Vector2f( 1140, 600 ), sf::Vector2f( 1008, 700 ), sf::Vector2f( 900, 600 ) };

}

namespace EntrancePaths
{
	const std::vector<std::vector<sf::Vector2f>> k_halfHeartLeftEnter = { std::vector<sf::Vector2f>{ sf::Vector2f( 360, 0 )}, std::vector<sf::Vector2f>{ sf::Vector2f( 960, 500 )}, BezierCurve::k_halfHeartLeftEnter, std::vector<sf::Vector2f>{ sf::Vector2f( 600, 400 )} };
	const std::vector<std::vector<sf::Vector2f>> k_halfHeartRightEnter = { std::vector<sf::Vector2f>{ sf::Vector2f( 840, 0 )}, std::vector<sf::Vector2f>{ sf::Vector2f( 240, 500 )}, BezierCurve::k_halfHeartRightEnter, std::vector<sf::Vector2f>{ sf::Vector2f( 600, 400 )} };

	const std::vector<std::vector<sf::Vector2f>> k_loopLeft = { std::vector<sf::Vector2f>{ sf::Vector2f( 0, 1000 )}, std::vector<sf::Vector2f>{ sf::Vector2f( 480, 500 )}, BezierCurve::k_loopLeftHalf1, BezierCurve::k_loopLeftHalf2, std::vector<sf::Vector2f>{ sf::Vector2f( 720, 300 )} };
	const std::vector<std::vector<sf::Vector2f>> k_loopRight = { std::vector<sf::Vector2f>{ sf::Vector2f( 1200, 1000 )}, std::vector<sf::Vector2f>{ sf::Vector2f( 720, 500 )}, BezierCurve::k_loopRightHalf1, BezierCurve::k_loopRightHalf2, std::vector<sf::Vector2f>{ sf::Vector2f( 480, 300 )} };

	const std::vector<std::vector<sf::Vector2f>> k_cCurve = { std::vector<sf::Vector2f>{ sf::Vector2f( 600, 0 )}, std::vector<sf::Vector2f>{ sf::Vector2f( 480, 200 )}, std::vector<sf::Vector2f>{ sf::Vector2f( 180, 500 )}, BezierCurve::k_cCurve, std::vector<sf::Vector2f>{ sf::Vector2f( 480, 420 )} };
	const std::vector<std::vector<sf::Vector2f>> k_cCurveReversed = { std::vector<sf::Vector2f>{ sf::Vector2f( 600, 0 )}, std::vector<sf::Vector2f>{ sf::Vector2f( 720, 200 )}, std::vector<sf::Vector2f>{ sf::Vector2f( 1020, 500 )}, BezierCurve::k_cCurveReversed, std::vector<sf::Vector2f>{ sf::Vector2f( 720, 420 )} };



	const std::vector < std::vector<std::vector<sf::Vector2f>>> k_level0Entrances = { k_cCurve, k_cCurveReversed };
	const std::vector < std::vector<std::vector<sf::Vector2f>>> k_level1Entrances = { k_loopLeft, k_loopRight, k_halfHeartLeftEnter };
	const std::vector < std::vector<std::vector<sf::Vector2f>>> k_level2Entrances = { k_cCurve, k_cCurveReversed, k_halfHeartLeftEnter, k_halfHeartRightEnter };
	const std::vector < std::vector<std::vector<sf::Vector2f>>> k_level3Entrances = { k_loopLeft, k_loopRight, k_halfHeartLeftEnter, k_halfHeartRightEnter, k_cCurve };
	const std::vector < std::vector<std::vector<sf::Vector2f>>> k_level4Entrances = { k_halfHeartLeftEnter, k_halfHeartRightEnter, k_loopLeft, k_loopRight, k_cCurve, k_cCurveReversed };

	const std::vector < std::vector<std::vector<sf::Vector2f>>> k_levelEntranceLists[ Settings::k_levelAmount ] = { k_level0Entrances, k_level1Entrances, k_level2Entrances, k_level3Entrances, k_level4Entrances };
}

namespace DivePaths
{
	const std::vector<std::vector<sf::Vector2f>> k_loopLeft = { std::vector<sf::Vector2f>{ sf::Vector2f( -1, -1 )}, std::vector<sf::Vector2f>{ sf::Vector2f( 120, 500 ) }, BezierCurve::k_loopLeftReversedHalf1, BezierCurve::k_loopLeftReversedHalf2, std::vector<sf::Vector2f>{ sf::Vector2f( 600, 400 )} };
	const std::vector<std::vector<sf::Vector2f>> k_loopRight = { std::vector<sf::Vector2f>{ sf::Vector2f( -1, -1 )}, std::vector<sf::Vector2f>{ sf::Vector2f( 1080, 500 ) }, BezierCurve::k_loopRightReversedHalf1, BezierCurve::k_loopRightReversedHalf2, std::vector<sf::Vector2f>{ sf::Vector2f( 600, 400 )} };

	//const std::vector<std::vector<std::vector<sf::Vector2f>>> k_diveList = { k_loopLeft, k_loopRight };

	const int k_diveListSize = 2;
	const std::vector<std::vector<sf::Vector2f>> k_diveList[ k_diveListSize ] = { k_loopLeft, k_loopRight };
}

#endif // !CURVESANDPATHS_H
