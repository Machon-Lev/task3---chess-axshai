#include "Piece.h"

Piece::Piece(Location loc, PlayerColor color)
{
	_location = loc;
	_color = color;
}

bool Piece::is_valid_move(Location dest, GameState* gameState) const
{
	bool validDir = false;
	Location calculatedDir, intermediateLoc;
	int steps = 1;
	
	if (!gameState->isCellInBoard(dest))
	{
		return false;
	}
	
	calculatedDir = dest - _location;
	for (auto &dir : _directions)
	{
		for (int i = 1; i < 8; i++)
		{
			if (Location{dir.horizontal * i, dir.vertical * i} == calculatedDir)
			{
				validDir = true;
				break;
			}
		}
		if (validDir == true)
		{
			break;
		}
	}
	if (!validDir)
	{
		return false;
	}
	calculatedDir = calculatedDir / calculatedDir;
	intermediateLoc = _location;
	while (steps <= _maxSteps)
	{
		intermediateLoc += calculatedDir;
		if (intermediateLoc == dest)
		{
			break;
		}
		if (gameState->getPiece(intermediateLoc)->getColor() != pEmpty)
		{
			return false;
		}
		steps++;
		//intermediateLoc += calculatedDir;
	}
	return intermediateLoc == dest;

}

void Piece::move(Location dest)
{
	_location = dest;
}

PlayerColor Piece::getColor() const
{
	return _color;
}

Location Piece::getLocation() const
{
	return _location;
}
