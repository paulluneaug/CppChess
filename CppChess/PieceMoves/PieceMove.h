#pragma once
#include "../ChessPiece.h"
#include "../Board.h"
#include "IPieceMove.h"

namespace CppChess 
{
	class PieceMove : public IPieceMove
	{
	private:
		int m_startTile;
		int m_endTile;

		bool m_killingMove;
		int m_killedPiecePosition;
		ChessPiece m_killedPiece;

		bool m_done;

	public:

		PieceMove(Board& board, int startTile, int endTile, bool killingMove, int killedPieceTile = -1);

		virtual void Do(Board& board);
		virtual void Undo(Board& board);
	};
}

