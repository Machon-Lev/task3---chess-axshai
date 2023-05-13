#pragma once
#include "Piece.h"

class Bishop : public Piece {
	void initDirAndSteps() override;
public:
	Bishop(Location Loc, PlayerColor color);
};
