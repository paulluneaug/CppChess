#pragma once
#include <stack>
#include <memory>

#include "IPieceMove.h"

namespace CppChess 
{
	class MoveStack
	{
	private:
		std::stack<std::shared_ptr<IPieceMove>> m_moveStack;

	public:
		MoveStack(int capacity);
	};
}

