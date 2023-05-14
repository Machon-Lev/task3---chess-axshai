#include "GameState.h"
#include "Rook.h"
#include "EmptyPiece.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include <memory>

GameState::GameState()
{
    //Initialize the chess game board:
    for (int r = 0; r < ROWS; r++)
    {
        std::vector<std::shared_ptr<Piece>> row;
        PlayerColor color;

        // In row 0 are the pieces of the white.
        // In 7 the are the pieces of the black
        switch (r)
        {
        case 0:
            color = pWhite;
            break;
        case 7:
            color = pBlack;
            break;
        default:
            color = pEmpty;
        }
        

        for (int c = 0; c < COLUMNS; c++)
        {
            if (r == 0 or r == 7)
            {
                switch (c)
                {
                    // columns 0 and 7: Rooks
                case 0:
                case 7:
                    row.push_back(std::make_shared<Rook>(Location{ r, c }, color));
                    break;
                    // column 4: King
                case 4:
                    row.push_back(std::make_shared<King>(Location{ r, c }, color));
                    break;
                    // column 2 and 5: Bishops
                case 2:
                case 5:
                    row.push_back(std::make_shared<Bishop>(Location{ r, c }, color));
                    break;
                    // column 3: Queen
                case 3:
                    row.push_back(std::make_shared<Queen>(Location{ r, c }, color));
                    break;
                default:
                    row.push_back(std::make_shared<EmptyPiece>(Location{ r, c }, pEmpty));
                    break;
                }
            }
            else
            {
                row.push_back((std::make_shared<EmptyPiece>(Location{ r, c }, color)));
            }
        }
        _board.push_back(row);
    }
}

bool GameState::isCellInBoard(Location loc) const
{
    return 0 <= loc.row && loc.row < ROWS && 0 <= loc.column && loc.column < COLUMNS;
}

std::shared_ptr<Piece>& GameState::getPiece(Location loc)
{
    auto &row = _board[loc.row];
    return row[loc.column];
}

Location GameState::getKingLocation(PlayerColor kingColor) const
{
    for (auto &row : _board)
    {
        for (auto & piece : row)
        {
            if (piece->getColor() == kingColor && dynamic_cast<King*>(piece.get()))
            {
                return piece->getLocation();
            }
        }
    }
    // if no king on board (this is an illegal situation that shouldn't happen) - 
    // return an off-board location
    return Location{ROWS, COLUMNS};
}

bool GameState::checkForChess(PlayerColor kingColor)
{
    Location kingLoc = getKingLocation(kingColor);
    PlayerColor other = otherPlayer(kingColor);
    
    // For each piece of the opponent's color - check if it threatens the king.
    for (auto& row : _board)
    {
        for (auto& piece : row)
        {
            if (piece->getColor() == other && piece->is_valid_move(kingLoc, this))
            {
                return true;
            }
        }
    }
    return false;
}

void GameState::move(Location src, Location dest)
{
    std::shared_ptr<Piece>& movedPiece = getPiece(src);

    // move the piece itself
    movedPiece->move(dest);

    // update the board as well
    _board[dest.row][dest.column] = movedPiece;
    _board[src.row][src.column] = std::make_shared<EmptyPiece>(Location{ src.row, src.column }, pEmpty);
}
