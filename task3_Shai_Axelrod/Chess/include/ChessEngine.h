#pragma once
#include <string>
#include "GameState.h"

/**
 * @class ChessEngine
 * @brief Represents the chess engine responsible for managing the game state and moves.
 *
 * The ChessEngine class controls the flow of the chess game, including the game state,
 * player turns, and move execution.
 * 
 * ChessEngine implements the Singleton pattern.
 */
class ChessEngine
{
	GameState _gameState;
	PlayerColor _turn;
	static ChessEngine* _engineInstance;

	/**
	 * @brief Parses the source location from the input string.
	 *
	 * @param input The input string containing the source location.
	 * @return The parsed source location.
	 */
	static Location parseSrcLoc(std::string input);

	/**
	 * @brief Parses the destination location from the input string.
	 *
	 * @param input The input string containing the destination location.
	 * @return The parsed destination location.
	 */
	static Location parseDestLoc(std::string input);

	/**
	 * @brief ChessEngine ctor.
	 */
	ChessEngine();
public:

	ChessEngine(const ChessEngine& obj) = delete;

	/**
	 * @brief Retrieves the singleton instance of the ChessEngine.
	 *
	 * @return The ChessEngine instance.
	 */
	static ChessEngine* getChessEngine();
	
	/**
	 * @brief Destroys the ChessEngine instance.
	 */
	~ChessEngine();

	/**
	 * @brief Performs a move based on the input string.
	 *
	 * @param input The input string representing the move.
	 * @return The status code indicating the result of the move.
	 */
	StatusCode performMove(std::string input);
	
};