#pragma once
#include <vector>
#include<memory>

#include "PieceMove.h"
#include "../Board.h"

namespace CppChess
{
	static class PieceMoveFactory
	{
		using MoveArray = std::vector<std::unique_ptr<IPieceMove>>;

	private:
		static int KNIGHT_MOVES_OFFSETS[];
		static int DIAGONALS_OFFSETS[];
		static int NEIGHBOUR_TILES_OFFSETS[];

	public:
		static bool GetPieceMoves(Board& board, int piecePosition, MoveArray& o_pieceMoves);

	private:
		__forceinline static std::unique_ptr<IPieceMove> CreateMove(Board& board, int startTile, int endTile, bool killingMove, int killedPieceTile = -1);

		static bool GetPawnMoves(Board& board, int piecePosition, MoveArray& o_pawnMoves);		
		static bool GetBishopMoves(Board& board, int piecePosition, MoveArray& o_bishopMoves);
		static bool GetKnightMoves(Board& board, int piecePosition, MoveArray& o_knightMoves);
		static bool GetRookMoves(Board& board, int piecePosition, MoveArray& o_rookMoves);
		static bool GetQueenMoves(Board& board, int piecePosition, MoveArray& o_queenMoves);
		static bool GetKingMoves(Board& board, int piecePosition, MoveArray& o_kingMoves);

		static bool CheckTileForPiece(Board& board, int piecePosition, int targetPosition, MoveArray& o_pieceMoves);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="board">Current game's board</param>
		/// <param name="piecePosition">Piece to check the tile for</param>
		/// <param name="targetPosition">Target tile</param>
		/// <param name="o_pieceMoves"></param>
		/// <returns>Wether it's needed to continue to check in that direction</returns>
		static bool CheckTileForSlidingPiece(Board& board, int piecePosition, int targetPosition, MoveArray& o_pieceMoves);
	};
}

