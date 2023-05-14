#pragma once
#include "Piece.h"

/**
 * @class King
 * @brief Represents a king chess piece
 */
class King : public Piece {
private:
	void initDirAndSteps() override;
public:
	King(Location Loc, PlayerColor color);
};
