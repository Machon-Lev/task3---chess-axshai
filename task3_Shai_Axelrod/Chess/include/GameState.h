#pragma once
#include "Piece.h"
#include <vector>
#include <Chess.h>

constexpr int ROWS = 8;
constexpr int COLUMN = 8;

enum StatusCode {
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
  bool isCellInBoard(int row, int col) const;
  Piece getPiece(int row, int col) const;
  Location getKingLocation(PlayerColor kingColor) const;
  bool checkForChess(int row, int col, PlayerColor kingColor) const;

public:
  GameState();
  StatusCode move(int srcRow, int srcCol, int destRow, int DestCol);
};


