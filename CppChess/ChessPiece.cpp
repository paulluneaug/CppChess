#include "ChessPiece.h"

namespace CppChess 
{
	const ChessPiece ChessPiece::s_none = ChessPiece(0);
	const ChessPiece ChessPiece::s_pawn = ChessPiece(1 << 0);
	const ChessPiece ChessPiece::s_bishop = ChessPiece(1 << 1);
	const ChessPiece ChessPiece::s_knight = ChessPiece(1 << 2);
	const ChessPiece ChessPiece::s_rook = ChessPiece(1 << 3);
	const ChessPiece ChessPiece::s_queen = ChessPiece(1 << 4);
	const ChessPiece ChessPiece::s_king = ChessPiece(1 << 5);
	const ChessPiece ChessPiece::s_white = ChessPiece(1 << 6);
	const ChessPiece ChessPiece::s_black = ChessPiece(1 << 7);

	ChessPiece::ChessPiece(int value)
	{
		m_value = value;
	}

	ChessPiece::ChessPiece(const ChessPiece& other)
	{
		m_value = other.GetValue();
	}

	const bool ChessPiece::HaveSameColor(const ChessPiece& a, const ChessPiece& b)
	{
		return (a & (s_white | s_black)) == (b & (s_white | s_black));
	}

	bool ChessPiece::HasFlag(const ChessPiece flag) const
	{
		return (*this & flag) == flag;
	}

	bool ChessPiece::IsColorOnly() const
	{
		return *this == s_black ||
			*this == s_white;
	}

	bool ChessPiece::IsPieceTypeOnly() const
	{
		return *this == s_pawn ||
			*this == s_bishop ||
			*this == s_knight ||
			*this == s_rook ||
			*this == s_queen ||
			*this == s_king;
	}

	bool ChessPiece::IsPureType() const
	{
		return IsColorOnly() || IsPieceTypeOnly();
	}

	bool ChessPiece::HasSingleColor() const
	{
		return IsWhite() ^ IsBlack();
	}
	
	bool ChessPiece::HasSinglePieceType() const
	{
		int flagCount = 0;
		if (IsPawn()) { flagCount++; }
		if (IsBishop()) { flagCount++; }
		if (IsKnight()) { flagCount++; }
		if (IsRook()) { flagCount++; }
		if (IsQueen()) { flagCount++; }
		if (IsKing()) { flagCount++; }
		return flagCount == 1;
	}        
	
	bool ChessPiece::IsValidCompositePiece() const
	{
		return HasSingleColor() && HasSinglePieceType();
	}

	bool ChessPiece::operator ==(ChessPiece other) const
	{
		return m_value == other.GetValue();
	}

	bool ChessPiece::operator !=(ChessPiece other) const
	{
		return m_value != other.GetValue();
	}

	ChessPiece ChessPiece::operator |(ChessPiece other) const
	{
		return ChessPiece(m_value | other.GetValue());
	}

	ChessPiece ChessPiece::operator &(ChessPiece other) const
	{
		return ChessPiece(m_value & other.GetValue());
	}

	ChessPiece ChessPiece::operator ^(ChessPiece other) const
	{
		return ChessPiece(m_value ^ other.GetValue());
	}

	ChessPiece ChessPiece::operator ~() const
	{
		return ChessPiece(~m_value);
	}
}