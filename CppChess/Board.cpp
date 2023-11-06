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

    ChessPiece Board::operator[](int index)
    {
        if (index < m_size)
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

    void Board::Initialize(std::string startConfiguration)
    {
        LoadConfiguration(startConfiguration);
    }

    void Board::LoadConfiguration(std::string configuration) {
        m_board = std::vector<ChessPiece>{};
        int boardSize = m_height * m_width;
        m_board.reserve(boardSize);

        int offset = 0;
        int configSize = configuration.size();
        for (int i = 0; i < configSize; ++i)
        {
            char currentChar = configuration[i];
            //std::isdigit
            if (IsDigit(currentChar))
            {
                std::string number = std::string{ currentChar };// currentChar.ToString();
                while (i < configSize - 1 && IsDigit(configuration[i + 1]))
                {
                    //i++;
                    currentChar = configuration[++i];
                    number += currentChar;
                }

                int offsetToApply = std::stoi(number);
                for (int j = 0; j < offsetToApply; ++j)
                {
                    if (offset >= boardSize)
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
                if (offset >= boardSize)
                {
                    Debug::LogError("Board overflow : " + offset);
                }
                else
                {
                    m_board[offset++] = GetPiece(currentChar/*.ToString().ToLower().ToCharArray().First()*/);
                }
            }
        }
    }

    ChessPiece Board::GetPiece(char identifier)
    {
        char lowerIdentifier = ToLower(identifier);
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
        return chessPiece.IsBlack() ? pieceType : pieceType; // @TODO upper
    }

    std::string Board::GetBoardRepresentationString()
    {
        std::string result = "";
        int boardSize = m_board.size();
        for (int i = 0; i < boardSize; ++i)
        {
            if (m_board[i] == ChessPiece::None())
            {
                int contiguousNoneTileCount = 0;
                while (i < boardSize && m_board[i] == ChessPiece::None())
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

    std::ostream& Board::operator<<(std::ostream& stream)
    {
        for (int y = 0; y < m_height; y++)
        {
            for (int x = 0; x < m_width; x++)
            {
                stream << GetPieceRepresentationString(m_board[x + y * m_width]) << ' ';
            }
            stream << "\n";
        }
        return stream;
    }

    bool Board::IsDigit(char c)
    {
        return '0' <= c && c <= '9';
    }

    char Board::ToLower(char c)
    {
        return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
};

