#pragma once
#include "../Board.h"
namespace CppChess 
{
    class IPieceMove
    {
        virtual void Do(Board& board) = 0;
        virtual void Undo(Board& board) = 0;
    };
}

