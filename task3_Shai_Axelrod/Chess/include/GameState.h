#pragma once
#include "Piece.h"
#include <vector>
#include <Chess.h>

constexpr int ROWS = 8;
constexpr int COLUMN = 8;

enum class StatusCode {
  // invalid (e for error) moves
  eNoPieceInSrc = 11,
  eOpposingPlayerInSrc,
  eSamePlayerInDest,

  eInvalidPieceMove = 21,
  eInvalidChessMove = 31,

  // valid (v for valid) moves
  vChessMove = 41,
  vRegularPieceMove

};

class GameState {
private:
	std::vector<std::vector<std::unique_ptr<Piece>>> _board;

public:
	GameState();
	bool isCellInBoard(Location loc) const;
	std::unique_ptr<Piece> getPiece(Location loc) const;
	Location getKingLocation(PlayerColor kingColor) const;
	bool checkForChess(PlayerColor kingColor) const;
	void move(Location src, Location dest);
};


