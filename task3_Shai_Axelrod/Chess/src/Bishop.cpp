#include "Bishop.h"

Bishop::Bishop(Location loc, PlayerColor color) : Piece(loc, color)
{
	initDirAndSteps();

}

void Bishop::initDirAndSteps()
{
	_maxSteps = 7;

	_directions.push_back(Direction{ Up ,Right });
	_directions.push_back(Direction{ Up ,Left });
	_directions.push_back(Direction{ Down ,Right });
	_directions.push_back(Direction{ Down ,Left });
}