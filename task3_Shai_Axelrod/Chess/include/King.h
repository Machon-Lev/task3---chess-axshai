#pragma once
#include "Piece.h"

class King : public Piece {
private:
	void initDirAndSteps() override;
public:
	King(Location Loc, PlayerColor color);
};
