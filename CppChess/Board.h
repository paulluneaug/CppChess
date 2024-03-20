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
    private:
        static const int m_width = 8;
        static const int m_height = 8;

        static const int m_size = m_height * m_width;

        const std::string m_defaultStartConfiguration = "P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1";
        //private const string m_defaultStartConfiguration = "rnbkqbnrpppppppp32PPPPPPPPPRNBKQBNR";

        ChessPiece m_board[m_size];



    public:
        Board();
        Board(std::string startConfiguration);

        __forceinline int Height() const { return m_height; }
        __forceinline int Width() const { return m_width; }
        __forceinline int Size() const { return m_size; }

        __forceinline bool ContainsTile(int piecePosition) const { return Utils::IsBetween(piecePosition, 0, m_size - 1); }

        ChessPiece operator[](int index) const;

        ChessPiece MovePiece(int startPosition, int endPosition);
        ChessPiece AddPiece(ChessPiece pieceToAdd, int piecePosition);

        std::string GetBoardRepresentationString();
        friend std::ostream& operator << (std::ostream& stream, const Board& board);

    private:
        void Initialize(std::string startConfiguration);
        void LoadConfiguration(std::string configuration);
        
        static ChessPiece GetPiece(char identifier);
        static char GetPieceRepresentationString(ChessPiece chessPiece);
        static char GetPieceType(ChessPiece chessPiece);

        static bool IsDigit(char c);
        static char ToLower(char c);
        static char ToUpper(char c);
	};
}

