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
        const int m_width = 8;
        const int m_height = 8;

        const int m_size = m_height * m_width;

        const std::string m_defaultStartConfiguration = "P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1P1p1";
        //private const string m_defaultStartConfiguration = "rnbkqbnrpppppppp32PPPPPPPPPRNBKQBNR";

        std::vector<ChessPiece> m_board;



    public:
        Board();
        Board(std::string startConfiguration);

        __forceinline int Height() { return m_height; }
        __forceinline int Width() { return m_width; }
        __forceinline int Size() { return m_size; }

        __forceinline bool ContainsTile(int piecePosition) { return Utils::IsBetween(piecePosition, 0, m_size - 1); }

        __forceinline ChessPiece operator[](int index);

        ChessPiece MovePiece(int startPosition, int endPosition);
        ChessPiece AddPiece(ChessPiece pieceToAdd, int piecePosition);

        std::string GetBoardRepresentationString();
        std::ostream& operator << (std::ostream& stream);

    private:
        void Initialize(std::string startConfiguration);
        void LoadConfiguration(std::string configuration);
        
        ChessPiece GetPiece(char identifier);
        char GetPieceRepresentationString(ChessPiece chessPiece);
        char GetPieceType(ChessPiece chessPiece);

        bool IsDigit(char c);
        char ToLower(char c);
	};
}

