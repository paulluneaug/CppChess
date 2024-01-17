#include "PieceMoveFactory.h"
#include "../Utils/Utils.h"


namespace CppChess 
{
	// +----+----+----+----+----+----+----+----+
	// |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |
	// +----+----+----+----+----+----+----+----+
	// |  8 |  9 | 10 | 11 | 12 | 13 | 14 | 15 |
	// +----+----+----+----+----+----+----+----+
	// | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 |
	// +----+----+----+----+----+----+----+----+
	// | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 |
	// +----+----+----+----+----+----+----+----+
	// | 32 | 33 | 34 | 35 | 36 | 37 | 38 | 39 |
	// +----+----+----+----+----+----+----+----+
	// | 40 | 41 | 42 | 43 | 44 | 45 | 46 | 47 |
	// +----+----+----+----+----+----+----+----+
	// | 48 | 49 | 50 | 51 | 52 | 53 | 54 | 55 |
	// +----+----+----+----+----+----+----+----+
	// | 56 | 57 | 58 | 59 | 60 | 61 | 62 | 63 |
	// +----+----+----+----+----+----+----+----+

	int PieceMoveFactory::KNIGHT_MOVES_OFFSETS[8] = { -10, -17, -15, -6, 10, 17, 15, 6 };
	int PieceMoveFactory::DIAGONALS_OFFSETS[4] = { -9, -7, 9, 7 };
	int PieceMoveFactory::NEIGHBOUR_TILES_OFFSETS[4] = { -8, 1, 8, -1 };

	bool PieceMoveFactory::GetPieceMoves(Board& board, int piecePosition, MoveArray& o_pieceMoves)
	{
		ChessPiece piece = board[piecePosition];
		o_pieceMoves = MoveArray{};
		if (piece.IsValidCompositePiece()) 
		{
			if (piece.IsPawn()) 
			{
				return GetPawnMoves(board, piecePosition, o_pieceMoves);
			}
			if (piece.IsBishop())
			{
				return GetBishopMoves(board, piecePosition, o_pieceMoves);
			}
			if (piece.IsKnight())
			{
				return GetKnightMoves(board, piecePosition, o_pieceMoves);
			}
			if (piece.IsRook())
			{
				return GetRookMoves(board, piecePosition, o_pieceMoves);
			}
			if (piece.IsQueen())
			{
				return GetQueenMoves(board, piecePosition, o_pieceMoves);
			}
			if (piece.IsKing())
			{
				return GetKingMoves(board, piecePosition, o_pieceMoves);
			}
		}
		return false;
	}

	bool PieceMoveFactory::GetPawnMoves(Board& board, int piecePosition, MoveArray& o_pawnMoves)
	{
		ChessPiece pawn = board[piecePosition];

		return false;
	}

	bool PieceMoveFactory::GetBishopMoves(Board& board, int piecePosition, MoveArray& o_bishopMoves)
	{
		bool success = true;
		for (int directionOffset : DIAGONALS_OFFSETS)
		{
			bool keepGoing = true;
			for (int i = 1; keepGoing; i++)
			{
				keepGoing = CheckTileForSlidingPiece(board, piecePosition, piecePosition + directionOffset * i, o_bishopMoves);
			}
		}

		return success;
	}

	bool PieceMoveFactory::GetKnightMoves(Board& board, int piecePosition, MoveArray& o_knightMoves)
	{
		ChessPiece knight = board[piecePosition];
		for (int offset : KNIGHT_MOVES_OFFSETS)
		{
			int targetPosition = piecePosition + offset;
			CheckTileForPiece(board, piecePosition, targetPosition, o_knightMoves);
		}
		return true;
	}


	bool PieceMoveFactory::GetRookMoves(Board& board, int piecePosition, MoveArray& o_rookMoves)
	{
		bool success = true;
		for (int directionOffset : NEIGHBOUR_TILES_OFFSETS)
		{
			bool keepGoing = true;
			for (int i = 1; keepGoing; i++)
			{
				keepGoing = CheckTileForSlidingPiece(board, piecePosition, piecePosition + directionOffset * i, o_rookMoves);
			}
		}

		return success;
	}

	bool PieceMoveFactory::GetQueenMoves(Board& board, int piecePosition, MoveArray& o_queenMoves)
	{
		bool sucess = true;
		sucess &= GetBishopMoves(board, piecePosition, o_queenMoves);
		sucess &= GetRookMoves(board, piecePosition, o_queenMoves);
		return sucess;
	}

	bool PieceMoveFactory::GetKingMoves(Board& board, int piecePosition, MoveArray& o_kingMoves)
	{
		return false;
	}

	bool PieceMoveFactory::CheckTileForPiece(Board& board, int piecePosition, int targetPosition, MoveArray& o_pieceMoves)
	{
		if (board.ContainsTile(targetPosition))
		{
			ChessPiece piece = board[targetPosition];
			ChessPiece target = board[targetPosition];
			if (piece.ShareColorWith(target))
			{
				return true;
			}
			if (target.IsEmpty())
			{
				o_pieceMoves.push_back(std::make_shared<PieceMove>(board, piecePosition, targetPosition, false));
			}
			else
			{
				o_pieceMoves.push_back(std::make_shared<PieceMove>(board, piecePosition, targetPosition, true));
			}
			return true;
		}
		return true;
	}

	bool PieceMoveFactory::CheckTileForSlidingPiece(Board& board, int piecePosition, int targetPosition, MoveArray& o_pieceMoves)
	{
		if (board.ContainsTile(targetPosition))
		{
			ChessPiece piece = board[targetPosition];
			ChessPiece target = board[targetPosition];
			if (piece.ShareColorWith(target))
			{
				return false;
			}
			if (target.IsEmpty())
			{
				o_pieceMoves.push_back(std::make_shared<PieceMove>(board, piecePosition, targetPosition, false));
			}
			else
			{
				o_pieceMoves.push_back(std::make_shared<PieceMove>(board, piecePosition, targetPosition, true));
			}
			return true;
		}
		return false;
	}
}
