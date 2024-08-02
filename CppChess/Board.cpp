#include "Board.h"

#include "Debug.h"

namespace CppChess
{
    Board::Board()
    {
        Initialize(m_defaultStartConfiguration);
    }

    Board::Board(std::string startConfiguration)
    {
        Initialize(startConfiguration);
    }

    ChessPiece Board::operator[](int index) const
    {
        if (index < SIZE)
        {
            return m_board[index];
        }
        Debug::LogError(index + " is outside of the array");
        return ChessPiece::None();
    }

    ChessPiece Board::MovePiece(int startPosition, int endPosition)
    {
        ChessPiece targetTile = m_board[endPosition];
        m_board[endPosition] = m_board[startPosition];
        m_board[startPosition] = ChessPiece::None();
        return targetTile;
    }

    ChessPiece Board::AddPiece(ChessPiece pieceToAdd, int piecePosition)
    {
        ChessPiece targetTile = m_board[piecePosition];
        m_board[piecePosition] = pieceToAdd;
        return targetTile;
    }

    void Board::Initialize(const std::string& startConfiguration)
    {
        LoadConfiguration(startConfiguration);
    }

    void Board::LoadConfiguration(const std::string& configuration)
    {
        int offset = 0;
        int configSize = configuration.size();
        for (int i = 0; i < configSize; ++i)
        {
            char currentChar = configuration[i];
            if (Utils::IsDigit(currentChar))
            {
                std::string number = std::string{ currentChar };
                while (i < configSize - 1 && Utils::IsDigit(configuration[i + 1]))
                {
                    //i++;
                    currentChar = configuration[++i];
                    number += currentChar;
                }

                int offsetToApply = std::stoi(number);
                for (int j = 0; j < offsetToApply; ++j)
                {
                    if (offset >= SIZE)
                    {
                        Debug::LogError("Board overflow : " + offset);
                    }
                    else
                    {
                        m_board[offset++] = ChessPiece::None();
                    }
                }
            }
            else
            {
                if (offset >= SIZE)
                {
                    Debug::LogError("Board overflow : " + offset);
                }
                else
                {
                    m_board[offset++] = GetPiece(currentChar);
                }
            }
        }
    }

    ChessPiece Board::GetPiece(char identifier)
    {
        char lowerIdentifier = Utils::ToLower(identifier);
        bool isLowerCase = lowerIdentifier == identifier;
        ChessPiece color = isLowerCase ? ChessPiece::Black() : ChessPiece::White();

        switch (lowerIdentifier)
        {
            case 'p':
                return ChessPiece::Pawn() | color;
            case 'b':
                return ChessPiece::Bishop() | color;
            case 'n':
                return ChessPiece::Knight() | color;
            case 'r':
                return ChessPiece::Rook() | color;
            case 'q':
                return ChessPiece::Queen() | color;
            case 'k':
                return ChessPiece::King() | color;
            default :
                Debug::LogError(lowerIdentifier + " is not a valid piece identifier");
                return ChessPiece::None();
        };
    }

    char Board::GetPieceRepresentationString(ChessPiece chessPiece)
    {
        if (chessPiece == ChessPiece::None())
        {
            return ' ';
        }
        if (!chessPiece.IsValidCompositePiece())
        {
            Debug::LogError(chessPiece.GetValue() + " is not a valid Value for a chessPiece");
            return ' ';
        }
        char pieceType = GetPieceType(chessPiece);
        return chessPiece.IsBlack() ? pieceType : Utils::ToUpper(pieceType); // @TODO upper
    }

    std::string Board::GetBoardRepresentationString()
    {
        std::string result = "";
        for (int i = 0; i < SIZE; ++i)
        {
            if (m_board[i] == ChessPiece::None())
            {
                int contiguousNoneTileCount = 0;
                while (i < SIZE && m_board[i] == ChessPiece::None())
                {
                    ++i;
                    ++contiguousNoneTileCount;
                }
                --i;
                result += contiguousNoneTileCount;
            }
            else
            {
                result += GetPieceRepresentationString(m_board[i]);
            }
        }

        return result;
    }

    char Board::GetPieceType(ChessPiece chessPiece)
    {
        if (chessPiece.IsPawn()) { return 'p'; }
        if (chessPiece.IsBishop()) { return 'b'; }
        if (chessPiece.IsKnight()) { return 'n'; }
        if (chessPiece.IsRook()) { return 'r'; }
        if (chessPiece.IsQueen()) { return 'q'; }
        if (chessPiece.IsKing()) { return 'k'; }
        return ' ';
    }

    std::ostream& operator<<(std::ostream& stream, const Board& board)
    {
        for (int y = 0; y < board.Height(); y++)
        {
            for (int x = 0; x < board.Width(); x++)
            {
                stream << board.GetPieceRepresentationString(board[x + y * board.Width()]) << ' ';
            }
            stream << "\n";
        }
        return stream;
    }
};

