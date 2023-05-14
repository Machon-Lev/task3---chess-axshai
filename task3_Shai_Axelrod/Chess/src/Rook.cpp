#include "Rook.h"

Rook::Rook(Location loc, PlayerColor color): Piece(loc, color)
{
	initDirAndSteps();

}


void Rook::initDirAndSteps()
{
	// The rook can move horizontally and vertically, any number of steps.

	_maxSteps = 7;
	_directions.push_back(Direction{ Up ,HNone });
	_directions.push_back(Direction{ Down ,HNone });
	_directions.push_back(Direction{ VNone ,Left });
	_directions.push_back(Direction{ VNone ,Right });
}
