#include "Bishop.h"

Bishop::Bishop(Location loc, PlayerColor color) : Piece(loc, color)
{
	initDirAndSteps();

}

void Bishop::initDirAndSteps()
{
	// The bishop can move diagonally in four directions any number of steps.
	_maxSteps = 7;

	_directions.push_back(Direction{ Up ,Right });
	_directions.push_back(Direction{ Up ,Left });
	_directions.push_back(Direction{ Down ,Right });
	_directions.push_back(Direction{ Down ,Left });
}