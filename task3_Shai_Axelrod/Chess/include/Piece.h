#pragma once
#include "Location.h"
#include "Direction.h"
#include <vector>

enum PlayerColor {
	pWhite,
	pBlack,
	pEmpty
};

class Piece {
	std::vector<Direction> _directions;
	int _maxSteps;
	Location _location;
	PlayerColor color;
	virtual void initDirAndSteps() = 0;

public:
	Piece(Location Loc, PlayerColor color);
	bool is_valid_move(Location dest) const;
	void move(Location dest);

	PlayerColor getColor();
	// Location getLocation();
};