#pragma once
#include "Piece.h"

class EmptyPiece : public Piece {
public:
	virtual void initDirAndSteps() override;
public:
	EmptyPiece(Location loc, PlayerColor color);
};