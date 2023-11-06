#pragma once
namespace CppChess 
{
	struct ChessPiece
	{
        #pragma region Static Fields and Methods
    public :
        __forceinline static const ChessPiece None() { return s_none; }
        __forceinline static const ChessPiece Pawn() { return s_pawn; }
        __forceinline static const ChessPiece Bishop() { return s_bishop; }
        __forceinline static const ChessPiece Knight() { return s_knight; }
        __forceinline static const ChessPiece Rook() { return s_rook; }
        __forceinline static const ChessPiece Queen() { return s_queen; }
        __forceinline static const ChessPiece King() { return s_king; }
        __forceinline static const ChessPiece White() { return s_white; }
        __forceinline static const ChessPiece Black() { return s_black; }

        static const bool HaveSameColor(const ChessPiece& a, const ChessPiece& b);

    private:
        static const ChessPiece s_none;
        static const ChessPiece s_pawn;
        static const ChessPiece s_bishop;
        static const ChessPiece s_knight;
        static const ChessPiece s_rook;
        static const ChessPiece s_queen;
        static const ChessPiece s_king;
        static const ChessPiece s_white;
        static const ChessPiece s_black;
    #pragma endregion

    public:
        __forceinline bool HasFlag(const ChessPiece flag) const;

        __forceinline bool IsEmpty() const { return m_value == 0; }

        __forceinline bool IsPawn() const { return HasFlag(s_pawn); }
        __forceinline bool IsBishop() const { return HasFlag(s_bishop); }
        __forceinline bool IsKnight() const { return HasFlag(s_knight); }
        __forceinline bool IsRook() const { return HasFlag(s_rook); }
        __forceinline bool IsQueen() const { return HasFlag(s_queen); }
        __forceinline bool IsKing() const { return HasFlag(s_king); }
        __forceinline bool IsWhite() const { return HasFlag(s_white); }
        __forceinline bool IsBlack() const { return HasFlag(s_black); }

    public:
        __forceinline int GetValue() const { return m_value; }

    private:
        int m_value;


    private:
        ChessPiece(int value);

        ChessPiece() = delete;

    public:
        ChessPiece(const ChessPiece& other);

        bool IsPieceTypeOnly() const;
        bool IsColorOnly() const;

        bool IsPureType() const;

        bool HasSingleColor() const;
        bool HasSinglePieceType() const;

        bool IsValidCompositePiece() const;

        // Operators
        bool operator ==(const ChessPiece other) const;
        bool operator !=(const ChessPiece other) const;
        ChessPiece operator |(const ChessPiece other) const;
        ChessPiece operator &(const ChessPiece other) const;
        ChessPiece operator ^(const ChessPiece other) const;
        ChessPiece operator ~() const;
	};
}

