#include "ChessEngine.h"
/*
#include <King.h>
#include <Rook.h>
#include <EmptyPiece.h>
#include <Bishop.h>
#include <Queen.h>
*/

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
    std::shared_ptr<Piece>& playerToMove = _gameState.getPiece(src);

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

    if (!playerToMove->is_valid_move(dest, &_gameState))
    {
        return StatusCode::eInvalidPieceMove;
    }

    GameState futureState(_gameState);
    futureState.move(src, dest);

    bool causeChess = futureState.checkForChess(_turn);

    futureState.getPiece(dest)->move(src);
    if (causeChess)
    {
        return StatusCode::eInvalidChessMove;
    }

    _gameState.move(src, dest);
    _turn = otherPlayer(_turn);

    if (_gameState.checkForChess(_turn))
    {
        return StatusCode::vChessMove;
    }
    else
    {
        return StatusCode::vRegularPieceMove;
    }


}

/*
void ChessEngine::print()
{
    std::cout << "ZOO MAP:\n";
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLUMNS; c++)
        {

            auto p = this->_gameState.getPiece(Location{ r,c });
            if (dynamic_cast<King*>(p.get()))
                std::cout << "k" << " ";
            if (dynamic_cast<Rook*>(p.get()))
                std::cout << "R" << " ";
            if (dynamic_cast<Bishop*>(p.get()))
                std::cout << "B" << " ";
            if (dynamic_cast<Queen*>(p.get()))
                std::cout << "q" << " ";
            if (dynamic_cast<EmptyPiece*>(p.get()))
                std::cout << "-" << " ";

        }
        std::cout << "\n";
    }
}
*/