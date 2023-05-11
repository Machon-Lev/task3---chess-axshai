#pragma once
#include <string>
#include "GameState.h"

class ChessEngine
{
	GameState _gameState;
	PlayerColor _turn;
	static ChessEngine* _engineInstance;
	static Location parseSrcLoc(std::string input);
	static Location parseDestLoc(std::string input);
	ChessEngine();
public:
	ChessEngine(const ChessEngine& obj) = delete;
	static ChessEngine* getChessEngine();
	~ChessEngine();
	StatusCode performMove(std::string input);
	//void print();

};