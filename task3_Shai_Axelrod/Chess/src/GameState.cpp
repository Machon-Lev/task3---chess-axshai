
#include "GameState.h"
#include <Rook.h>
#include <EmptyPiece.h>
#include <Bishop.h>
#include <Queen.h>
#include <King.h>

GameState::GameState()
{
    for (int r = 0; r < ROWS; r++)
    {
        std::vector<std::unique_ptr<Piece>> row;
        PlayerColor color;

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
        

        for (int c = 0; c < COLUMN; c++)
        {
            if (r == 0 or r == 7)
            {
                switch (c)
                {
                case 0:
                case 7:
                    row.push_back(std::make_unique<Rook>(Location{ r, c }, color));
                    break;
                case 2:
                case 5:
                    row.push_back(std::make_unique<Bishop>(Location{ r, c }, color)); // Bishop
                    break;
                case 3:
                    row.push_back(std::make_unique<Queen>(Location{ r, c }, color)); //Queen
                    break;
                case 4:
                    row.push_back(std::make_unique<King>(Location{ r, c }, color)); //King
                    break;

                default:
                    row.push_back(std::make_unique<EmptyPiece>(Location{ r, c }, pEmpty));
                    break;
                }
            }
            else
            {
                row.push_back(std::make_unique<EmptyPiece>(Location{ r, c }, color));
            }
        }
        _board.push_back(row);
    }
}

