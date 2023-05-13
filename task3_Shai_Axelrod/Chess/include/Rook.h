#pragma once
#include "Piece.h"

class Rook : public Piece {
	void initDirAndSteps() override;
public:
	Rook(Location Loc, PlayerColor color);
};