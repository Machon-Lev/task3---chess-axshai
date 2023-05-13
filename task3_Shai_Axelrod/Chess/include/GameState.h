#pragma once
#include <vector>
#include <memory>
#include "Chess.h"
#include "Piece.h"
#include "Player.h"

constexpr int ROWS = 8;
constexpr int COLUMNS = 8;

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

class Piece;

class GameState {
private:
	std::vector<std::vector<std::shared_ptr<Piece>>> _board;

public:
	GameState();
	bool isCellInBoard(Location loc) const;
	std::shared_ptr<Piece>& getPiece(Location loc);
	Location getKingLocation(PlayerColor kingColor)const;
	bool checkForChess(PlayerColor kingColor);
	void move(Location src, Location dest);
};


