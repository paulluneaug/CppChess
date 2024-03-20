#include "ChessPiece.h"

namespace CppChess 
{
	const int ChessPiece::s_noneOffset   = 0;
	const int ChessPiece::s_pawnOffset   = 1;
	const int ChessPiece::s_bishopOffset = 2;
	const int ChessPiece::s_knightOffset = 3;
	const int ChessPiece::s_rookOffset   = 4;
	const int ChessPiece::s_queenOffset  = 5;
	const int ChessPiece::s_kingOffset   = 6;
	const int ChessPiece::s_whiteOffset  = 7;
	const int ChessPiece::s_blackOffset  = 8;

	const ChessPiece ChessPiece::s_none   = ChessPiece(1 << s_noneOffset - 1);
	const ChessPiece ChessPiece::s_pawn   = ChessPiece(1 << s_pawnOffset - 1);
	const ChessPiece ChessPiece::s_bishop = ChessPiece(1 << s_bishopOffset - 1);
	const ChessPiece ChessPiece::s_knight = ChessPiece(1 << s_knightOffset - 1);
	const ChessPiece ChessPiece::s_rook   = ChessPiece(1 << s_rookOffset - 1);
	const ChessPiece ChessPiece::s_queen  = ChessPiece(1 << s_queenOffset - 1);
	const ChessPiece ChessPiece::s_king   = ChessPiece(1 << s_kingOffset - 1);
	const ChessPiece ChessPiece::s_white  = ChessPiece(1 << s_whiteOffset - 1);
	const ChessPiece ChessPiece::s_black  = ChessPiece(1 << s_blackOffset - 1);

	const ChessPiece ChessPiece::s_pieceTypeMask =
		ChessPiece::s_pawn |
		ChessPiece::s_bishop |
		ChessPiece::s_knight |
		ChessPiece::s_rook |
		ChessPiece::s_queen |
		ChessPiece::s_king;

	const ChessPiece ChessPiece::s_colorMask =
		ChessPiece::s_black |
		ChessPiece::s_white;

	ChessPiece::ChessPiece(int value)
	{
		m_value = value;
	}

	ChessPiece::ChessPiece() : ChessPiece(0)
	{
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
		return (*this & s_pieceTypeMask).IsEmpty();
	}

	bool ChessPiece::IsPieceTypeOnly() const
	{
		return (*this & s_colorMask).IsEmpty();
	}

	bool ChessPiece::IsPureType() const
	{
		return IsColorOnly() || IsPieceTypeOnly();
	}

	bool ChessPiece::HasColor() const
	{
		return (*this & s_colorMask) != s_none;
	}

	bool ChessPiece::HasPieceType() const
	{
		return (*this & s_pieceTypeMask) != s_none;
	}

	bool ChessPiece::HasSingleColor() const
	{
		return IsWhite() ^ IsBlack();
	}
	
	bool ChessPiece::HasSinglePieceType() const
	{
		int flagCount =
			((*this & s_pawn) >> (s_pawnOffset - 1)).GetValue() +
			((*this & s_bishop) >> (s_bishopOffset - 1)).GetValue() +
			((*this & s_knight) >> (s_knightOffset - 1)).GetValue() +
			((*this & s_rook) >> (s_rookOffset - 1)).GetValue() +
			((*this & s_queen) >> (s_queenOffset - 1)).GetValue() +
			((*this & s_king) >> (s_kingOffset - 1)).GetValue();

		return flagCount == 1;
	}        
	
	bool ChessPiece::IsValidCompositePiece() const
	{
		return HasSingleColor() && HasSinglePieceType();
	}

	bool ChessPiece::ShareColorWith(const ChessPiece& other) const
	{
		ChessPiece combination = *this & other;
		return combination.HasColor();
	}

	bool ChessPiece::SharePieceTypeWith(const ChessPiece& other) const
	{
		ChessPiece combination = *this & other;
		return combination.HasPieceType();
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

	ChessPiece ChessPiece::operator>>(const int offset) const
	{
		return ChessPiece(m_value >> offset);
	}

	ChessPiece ChessPiece::operator<<(const int offset) const
	{
		return ChessPiece(m_value << offset);
	}
}