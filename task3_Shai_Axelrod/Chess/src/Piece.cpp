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
	
	// check that the destination is a valid cell
	if (!gameState->isCellInBoard(dest))
	{
		return false;
	}
	
	// calaulate the direction of the move and check that 
	// it is a valid direction for this piece:
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
	
	// Check that there is no piece between the destination and the source
	// that blocks the move:
	calculatedDir = calculatedDir / calculatedDir;
	intermediateLoc = _location;
	while (steps <= _maxSteps)
	{
		// Take one step towards the destination
		intermediateLoc += calculatedDir;
		if (intermediateLoc == dest)
		{
			break;
		}
		// it there is a piece there - its block the move and the move is invalid.
		if (gameState->getPiece(intermediateLoc)->getColor() != pEmpty)
		{
			return false;
		}
		steps++;
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
