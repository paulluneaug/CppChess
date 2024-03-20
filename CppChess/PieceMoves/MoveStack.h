#pragma once
#include <stack>
#include <memory>

#include "IPieceMove.h"

namespace CppChess 
{
	class MoveStack
	{
	private:
		std::stack<std::unique_ptr<IPieceMove>> m_moveStack;

	public:
		MoveStack();

		void AddMove(std::unique_ptr<IPieceMove>);
		std::unique_ptr<IPieceMove> PopMove();

		bool IsEmpty() const;
	};
}

