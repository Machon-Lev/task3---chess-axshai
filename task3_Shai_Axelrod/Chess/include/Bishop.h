#pragma once
#include "Piece.h"

/**
 * @class Bishop
 * @brief Represents a bishop chess piece
 */
class Bishop : public Piece {
	void initDirAndSteps() override;
public:
	Bishop(Location Loc, PlayerColor color);
};
