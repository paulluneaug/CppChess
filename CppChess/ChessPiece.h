#pragma once
namespace CppChess 
{
	struct ChessPiece
	{
        #pragma region Static Fields and Methods
    public :
        [[nodiscard]] __forceinline static const ChessPiece None()   { return s_none; }
        [[nodiscard]] __forceinline static const ChessPiece Pawn()   { return s_pawn; }
        [[nodiscard]] __forceinline static const ChessPiece Bishop() { return s_bishop; }
        [[nodiscard]] __forceinline static const ChessPiece Knight() { return s_knight; }
        [[nodiscard]] __forceinline static const ChessPiece Rook()   { return s_rook; }
        [[nodiscard]] __forceinline static const ChessPiece Queen()  { return s_queen; }
        [[nodiscard]] __forceinline static const ChessPiece King()   { return s_king; }
        [[nodiscard]] __forceinline static const ChessPiece White()  { return s_white; }
        [[nodiscard]] __forceinline static const ChessPiece Black()  { return s_black; }

        static const bool HaveSameColor(const ChessPiece& a, const ChessPiece& b);

    private:

        static const int s_noneOffset;
        static const int s_pawnOffset;
        static const int s_bishopOffset;
        static const int s_knightOffset;
        static const int s_rookOffset;
        static const int s_queenOffset;
        static const int s_kingOffset;
        static const int s_whiteOffset;
        static const int s_blackOffset;

        static const ChessPiece s_none;
        static const ChessPiece s_pawn;
        static const ChessPiece s_bishop;
        static const ChessPiece s_knight;
        static const ChessPiece s_rook;
        static const ChessPiece s_queen;
        static const ChessPiece s_king;
        static const ChessPiece s_white;
        static const ChessPiece s_black;

        static const ChessPiece s_pieceTypeMask;
        static const ChessPiece s_colorMask;
    #pragma endregion

    public:
        /// <summary>Wether the piece has the given flag</summary>
        [[nodiscard]] __forceinline bool HasFlag(const ChessPiece flag) const;

        /// <summary>Wether the piece has no flag</summary>
        [[nodiscard]] __forceinline bool IsEmpty() const { return m_value == 0; }

        /// <summary>Wether the piece has the flag "Pawn"</summary>
        [[nodiscard]] __forceinline bool IsPawn() const { return HasFlag(s_pawn); }
        /// <summary>Wether the piece has the flag "Bishop"</summary>
        [[nodiscard]] __forceinline bool IsBishop() const { return HasFlag(s_bishop); }
        /// <summary>Wether the piece has the flag "Knight"</summary>
        [[nodiscard]] __forceinline bool IsKnight() const { return HasFlag(s_knight); }
        /// <summary>Wether the piece has the flag "Rook"</summary>
        [[nodiscard]] __forceinline bool IsRook() const { return HasFlag(s_rook); }
        /// <summary>Wether the piece has the flag "Queen"</summary>
        [[nodiscard]] __forceinline bool IsQueen() const { return HasFlag(s_queen); }
        /// <summary>Wether the piece has the flag "Kink"</summary>
        [[nodiscard]] __forceinline bool IsKing() const { return HasFlag(s_king); }
        /// <summary>Wether the piece has the flag "White"</summary>
        [[nodiscard]] __forceinline bool IsWhite() const { return HasFlag(s_white); }
        /// <summary>Wether the piece has the flag "Black"</summary>
        [[nodiscard]] __forceinline bool IsBlack() const { return HasFlag(s_black); }

    public:
        /// <summary>Returns the </summary>
        [[nodiscard]] __forceinline int GetValue() const { return m_value; }

    private:
        int m_value;


    private:
        ChessPiece(int value);

    public:
        ChessPiece();
        ChessPiece(const ChessPiece& other);

        /// <summary>Wether the piece has no piece type flag</summary>
        [[nodiscard]] bool IsColorOnly() const;
        /// <summary>Wether the piece has no color flag</summary>
        [[nodiscard]] bool IsPieceTypeOnly() const;

        /// <summary>Wether the piece is only a color or only a piece type</summary>
        [[nodiscard]] bool IsPureType() const;

        /// <summary>Wether the piece has a color flag</summary>
        [[nodiscard]] bool HasColor() const;
        /// <summary>Wether the piece has a piece type flag</summary>
        [[nodiscard]] bool HasPieceType() const;

        /// <summary>Wether the piece has a single color flag</summary>
        [[nodiscard]] bool HasSingleColor() const;
        /// <summary>Wether the piece has a single piece type flag</summary>
        [[nodiscard]] bool HasSinglePieceType() const;

        /// <summary>Wether the piece has a single color flag and a single piece type flag</summary>
        [[nodiscard]] bool IsValidCompositePiece() const;

        /// <summary>Wether the two pieces share at least one color</summary>
        [[nodiscard]] bool ShareColorWith(const ChessPiece& other) const;
        /// <summary>Wether the two pieces share at least one piece type</summary>
        [[nodiscard]] bool SharePieceTypeWith(const ChessPiece& other) const;

        // Operators
        [[nodiscard]] __forceinline bool operator ==(const ChessPiece other) const;
        [[nodiscard]] __forceinline bool operator !=(const ChessPiece other) const;
        [[nodiscard]] __forceinline ChessPiece operator |(const ChessPiece other) const;
        [[nodiscard]] __forceinline ChessPiece operator &(const ChessPiece other) const;
        [[nodiscard]] __forceinline ChessPiece operator ^(const ChessPiece other) const;
        [[nodiscard]] __forceinline ChessPiece operator ~() const;

        [[nodiscard]] __forceinline ChessPiece operator >>(const int offset) const;
        [[nodiscard]] __forceinline ChessPiece operator <<(const int offset) const;
	};
}

