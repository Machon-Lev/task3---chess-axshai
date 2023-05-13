#pragma once
#include "Piece.h"

class Queen : public Piece {
	void initDirAndSteps();
public:
	Queen(Location Loc, PlayerColor color);
};
