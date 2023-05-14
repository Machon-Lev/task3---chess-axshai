#pragma once
#include "Piece.h"

/**
 * @class EmptyPiece
 * @brief Represents a empty cell in the chess board
 */
class EmptyPiece : public Piece {
public:
	virtual void initDirAndSteps() override;
public:
	EmptyPiece(Location loc, PlayerColor color);
};