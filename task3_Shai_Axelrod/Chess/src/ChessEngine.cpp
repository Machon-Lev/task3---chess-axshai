#include "ChessEngine.h"

ChessEngine* ChessEngine::_engineInstance = nullptr;

ChessEngine::ChessEngine() : _turn(pWhite) {};

ChessEngine::~ChessEngine()
{
	delete _engineInstance;
}

ChessEngine* ChessEngine::getChessEngine()
{
    // if there is no instatnce yet - creat one.
    if (_engineInstance == nullptr)
    {
        _engineInstance = new ChessEngine();
    }
    // returning the instance pointer
    return _engineInstance;


}

Location ChessEngine::parseSrcLoc(std::string input)
{
    // input tamplate for example: "b1c5" src = b1, dest = c5. 
    // so return (1,0)
    return Location{ input[0] - 'a', input[1] - '1' };
}


Location ChessEngine::parseDestLoc(std::string input)
{
    // input tamplate for example: "b1c5" src = b1, dest = c5.
    // so return (2,4)
    return Location{ input[2] - 'a', input[3] - '1' };
}



StatusCode ChessEngine::performMove(std::string input)
{
    Location src = parseSrcLoc(input), dest = parseDestLoc(input);
    std::shared_ptr<Piece>& playerToMove = _gameState.getPiece(src);

    // 1.check there is a piece in src that belongs to the current player:
    if (playerToMove->getColor() == pEmpty)
    {
        return StatusCode::eNoPieceInSrc;
    }
    else if (playerToMove->getColor() != _turn)
    {
        return StatusCode::eOpposingPlayerInSrc;
    }

    // 2.check if the destination location has a piece belonging to the same player:
    if (_gameState.getPiece(dest)->getColor() == _turn)
    {
        return StatusCode::eSamePlayerInDest;
    }

    // 3.check if the move is valid for the piece:
    if (!playerToMove->is_valid_move(dest, &_gameState))
    {
        return StatusCode::eInvalidPieceMove;
    }
    
    // 4.check if the move will cause chess for the current player:
    
    // create a future state to check for a chess position after the move
    GameState futureState(_gameState); 
    futureState.move(src, dest);

    bool causeChess = futureState.checkForChess(_turn);
    
    // undo the move. (the piece location is affected by the future state because 
    // it contains refernces to the pieces.)
    futureState.getPiece(dest)->move(src); 
    if (causeChess)
    {
        return StatusCode::eInvalidChessMove;
    }

    // 5. the move is valid - do the move!
    _gameState.move(src, dest);
    _turn = otherPlayer(_turn);

    // 6. check if the move cause chess to the opposing player:
    if (_gameState.checkForChess(_turn))
    {
        return StatusCode::vChessMove;
    }
    else
    {
        return StatusCode::vRegularPieceMove;
    }

}
