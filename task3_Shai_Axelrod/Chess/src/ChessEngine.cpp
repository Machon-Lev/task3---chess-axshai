#include "ChessEngine.h"

ChessEngine* ChessEngine::_engineInstance = nullptr;

ChessEngine::ChessEngine() : _turn(pWhite) {};

ChessEngine::~ChessEngine()
{
	delete _engineInstance;
}

ChessEngine* ChessEngine::getChessEngine()
{
    if (_engineInstance == nullptr)
    {
        _engineInstance = new ChessEngine();
    }
    // returning the instance pointer
    return _engineInstance;


}

Location ChessEngine::parseSrcLoc(std::string input)
{
    return Location{ input[0] - 'a', input[1] - '1' };
}


Location ChessEngine::parseDestLoc(std::string input)
{
    return Location{ input[2] - 'a', input[3] - '1' };
}



StatusCode ChessEngine::performMove(std::string input)
{
    Location src = parseSrcLoc(input), dest = parseDestLoc(input);
    std::unique_ptr<Piece> playerToMove = _gameState.getPiece(src);
    
    if (playerToMove->getColor() == pEmpty)
    {
        return StatusCode::eNoPieceInSrc;
    }
    else if (playerToMove->getColor() != _turn)
    {
        return StatusCode::eOpposingPlayerInSrc;
    }

    if (_gameState.getPiece(dest)->getColor() == _turn)
    {
        return StatusCode::eSamePlayerInDest;
    }

    if (!playerToMove->is_valid_move(dest))
    {
        return StatusCode::eInvalidPieceMove;
    }

    GameState futureState(_gameState);
    futureState.move(src, dest);
    
    if (futureState.checkForChess(_turn))
    {
        return StatusCode::eInvalidChessMove;
    }

    _gameState.move(src, dest);
    _turn = (PlayerColor)((int)_turn + 1 % MAX_PLAYERS_NUM));
 
    if (_gameState.checkForChess(_turn))
    {
        return StatusCode::vChessMove;
    }
    else
    {
        return StatusCode::vRegularPieceMove;
    }


}
