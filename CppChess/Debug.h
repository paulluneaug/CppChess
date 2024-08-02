#pragma once
#include <string>
#include <iostream>

namespace CppChess 
{
    static class Debug
    {
    public:
        __forceinline static void Log(std::string message)
        {
            std::cout << message;
        }

        __forceinline static void LogWarning(std::string warning)
        {
            std::cout << warning;
        }

        __forceinline static void LogError(std::string error)
        {
            std::cout << error;
        }
    };
}

