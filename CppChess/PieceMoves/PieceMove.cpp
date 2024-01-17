#include "PieceMove.h"

namespace CppChess
{
	PieceMove::PieceMove(Board& board, int startTile, int endTile, bool killingMove, int killedPieceTile)
	{
		m_startTile = startTile;
		m_endTile = endTile;
		m_done = false;
		m_killingMove = killingMove;

		if (killingMove) 
		{
			if (killedPieceTile == -1) 
			{
				killedPieceTile = endTile;
			}
			m_killedPiecePosition = killedPieceTile;
			m_killedPiece = board[killedPieceTile];
		}
		else 
		{
			m_killedPiecePosition = -1;
			m_killedPiece = ChessPiece::None();
		}

	}

	void PieceMove::Do(Board& board)
	{
		m_killedPiece = board.MovePiece(m_startTile, m_endTile);
		m_done = true;
	}

	void PieceMove::Undo(Board& board)
	{
		if (m_done) 
		{
			board.MovePiece(m_endTile, m_startTile);
			if (m_killingMove)
			{
				board.AddPiece(m_killedPiece, m_endTile);
			}
			m_done = false;
		}
	}

}
