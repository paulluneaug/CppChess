#pragma once
class Utils
{
public:
    template<typename T>
    __forceinline static bool IsBetween(T val, T lowerLimit, T upperLimit, bool limitsIncluded = true) 
    {
        if (limitsIncluded) 
        {
            return lowerLimit <= val && val <= upperLimit;
        }
        return lowerLimit < val && val < upperLimit;
    }



    __forceinline static bool IsDigit(char c)
    {
        return '0' <= c && c <= '9';
    }

    __forceinline static char ToLower(char c)
    {
        return static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }

    __forceinline static char ToUpper(char c)
    {
        return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    }
};

