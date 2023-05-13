#include "Queen.h"

Queen::Queen(Location loc, PlayerColor color) : Piece(loc, color)
{
	initDirAndSteps();

}

void Queen::initDirAndSteps()
{
	_maxSteps = 7;
	_directions.push_back(Direction{ Up ,HNone });
	_directions.push_back(Direction{ Down ,HNone });
	_directions.push_back(Direction{ VNone ,Left });
	_directions.push_back(Direction{ VNone ,Right });

	_directions.push_back(Direction{ Up ,Right });
	_directions.push_back(Direction{ Up ,Left });
	_directions.push_back(Direction{ Down ,Right });
	_directions.push_back(Direction{ Down ,Left });
}
