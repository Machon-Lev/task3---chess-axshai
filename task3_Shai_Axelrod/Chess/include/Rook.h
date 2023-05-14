#pragma once
#include "Piece.h"

/**
 * @class Rook
 * @brief Represents a rook chess piece
 */
class Rook : public Piece {
	void initDirAndSteps() override;
public:
	Rook(Location Loc, PlayerColor color);
};