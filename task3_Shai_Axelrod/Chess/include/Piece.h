#pragma once
#include <vector>
#include "Location.h"
#include "Direction.h"
#include "GameState.h"
#include "Player.h"

class GameState;

/**
 * @class Piece
 * @brief Represents a chess piece with common properties and behaviors.
 */
class Piece {
protected:
	std::vector<Direction> _directions; // List of valid directions for movement.
	int _maxSteps; // Maximum number of steps the piece can move in a single direction.
	Location _location;
	PlayerColor _color;

	/**
	 * @brief Initializes the directions and maximum steps for the piece.
	 *
	 * This method must be implemented by each derived piece class to define the
	 * valid directions and maximum steps for that specific piece.
	 */
	virtual void initDirAndSteps() = 0;

public:
	/**
	 * @brief Constructs a new Piece object.
	 *
	 * @param loc The initial location of the piece on the chessboard.
	 * @param color The color of the player the piece belongs to.
	 */
	Piece(Location loc, PlayerColor color);

	/**
	 * @brief Checks if the piece can move to the specified destination location.
	 *
	 * @param dest The destination location to check.
	 * @param gameState Pointer to the current game state.
	 * @return True if the move is valid, false otherwise.
	 */
	bool is_valid_move(Location dest, GameState* gameState) const;

	/**
	 * @brief Moves the piece to the specified destination location.
	 *
	 * @param dest The destination location to move the piece to.
	 */
	void move(Location dest);

	/**
	 * @brief Retrieves the color of the player the piece belongs to.
	 *
	 * @return The color of the player.
   	 */
	PlayerColor getColor() const;

	/**
	 * @brief Retrieves the current location of the piece on the chessboard.
	 *
	 * @return The current location of the piece.
	 */
	Location getLocation() const;
};