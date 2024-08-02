#pragma once

#include <vector>
#include <memory>
#include <string>
#include <iostream>

#include "ChessPiece.h"
#include "Debug.h"
#include "Utils/Utils.h"


namespace CppChess
{
	class Board
	{
    public:
        static const int WIDTH = 8;
        static const int HEIGHT = 8;

        static const int SIZE = HEIGHT * WIDTH;

    private:
        const std::string m_defaultStartConfiguration = "P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1";
        //private const string m_defaultStartConfiguration = "rnbkqbnrpppppppp32PPPPPPPPPRNBKQBNR";

        ChessPiece m_board[SIZE];

    public:
        Board();
        Board(std::string startConfiguration);

        __forceinline int Height() const { return HEIGHT; }
        __forceinline int Width() const { return WIDTH; }
        __forceinline int Size() const { return SIZE; }

        __forceinline bool ContainsTile(int piecePosition) const { return Utils::IsBetween(piecePosition, 0, SIZE - 1); }

        ChessPiece operator[](int index) const;

        ChessPiece MovePiece(int startPosition, int endPosition);
        ChessPiece AddPiece(ChessPiece pieceToAdd, int piecePosition);

        std::string GetBoardRepresentationString();
        friend std::ostream& operator << (std::ostream& stream, const Board& board);

    private:
        void Initialize(const std::string& startConfiguration);
        void LoadConfiguration(const std::string& configuration);
        
        static ChessPiece GetPiece(char identifier);
        static char GetPieceRepresentationString(ChessPiece chessPiece);
        static char GetPieceType(ChessPiece chessPiece);
	};
}

