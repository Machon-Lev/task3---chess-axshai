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
/**
 * @class GameState
 * @brief Represents the state of a chess game.
 *
 * The game state stores the current configuration and status 
 * of the chessboard.
 */
class GameState {
private:
	std::vector<std::vector<std::shared_ptr<Piece>>> _board; //2D vector representing the chessboard.

public:
	/**
	 * @brief Constructs a new GameState object.
	 */
	GameState();

	/**
	* @brief Checks if the specified location is within the bounds of the chessboard.
	*
	* @param loc The location to check.
	* @return True if the location is within the chessboard, false otherwise.
	*/
	bool isCellInBoard(Location loc) const;
	
	/**
	* @brief Retrieves the piece at the specified location.
	*
	* @param loc The location to retrieve the piece from.
	* @return A reference to the piece at the specified location.
	*/
	std::shared_ptr<Piece>& getPiece(Location loc);

	/**
   * @brief Retrieves the location of the king for the specified player color.
   *
   * @param kingColor The color of the player whose king's location is requested.
   * @return The location of the king for the specified player color.
   */
	Location getKingLocation(PlayerColor kingColor)const;

	/**
	 * @brief Checks if the specified player color is in a chess position.
	 *
	 * @param kingColor The color of the player to check for a chess position.
	 * @return True if the player is in a chess position, false otherwise.
	 */
	bool checkForChess(PlayerColor kingColor);

	/**
	* @brief Moves a piece from the source location to the destination location.
	*
	* @param src The source location of the piece to move.
	* @param dest The destination location to move the piece to.
	*/
	void move(Location src, Location dest);
};


