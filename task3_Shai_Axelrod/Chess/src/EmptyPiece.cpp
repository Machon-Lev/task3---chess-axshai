#include "EmptyPiece.h"

// empty piece - empty implementions. (no directions and steps for empty piece)
EmptyPiece::EmptyPiece(Location loc, PlayerColor color) : Piece(loc, color)
{
}

void EmptyPiece::initDirAndSteps()
{
}
