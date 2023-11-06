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
};

