#include "MoveStack.h"

namespace CppChess 
{
	MoveStack::MoveStack()
	{
		m_moveStack = std::stack<std::unique_ptr<IPieceMove>>();
	}

	void MoveStack::AddMove(std::unique_ptr<IPieceMove> pieveMove)
	{
		m_moveStack.push(std::move(pieveMove));
	}

	std::unique_ptr<IPieceMove> MoveStack::PopMove()
	{
		if (m_moveStack.empty()) 
		{
			return nullptr;
		}
		std::unique_ptr<IPieceMove> poppedMove = std::move(m_moveStack.top());
		m_moveStack.pop();
		return poppedMove;
	}
	bool MoveStack::IsEmpty() const
	{
		return m_moveStack.empty();
	}
}
