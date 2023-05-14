#pragma once
#include "Piece.h"
/**
 * @class Queen
 * @brief Represents a queen chess piece
 */
class Queen : public Piece {
	void initDirAndSteps();
public:
	Queen(Location Loc, PlayerColor color);
};
