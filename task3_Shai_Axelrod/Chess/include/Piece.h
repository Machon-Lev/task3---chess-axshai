#pragma once
#include <vector>
#include "Location.h"
#include "Direction.h"
#include "GameState.h"
#include "Player.h"

class GameState;

class Piece {
protected:
	std::vector<Direction> _directions;
	int _maxSteps;
	Location _location;
	PlayerColor _color;
	virtual void initDirAndSteps() = 0;

public:
	Piece(Location loc, PlayerColor color);
	bool is_valid_move(Location dest, GameState* gameState) const;
	void move(Location dest);

	PlayerColor getColor() const;
	Location getLocation() const;
};