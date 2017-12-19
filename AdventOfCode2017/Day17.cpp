#include "Day17.h"

#include "FileReader.h"

#include <list>

#include <iostream>


namespace day17
{
	int64_t part1()
	{
		const auto steps = std::stoll(getLine("Day17.txt"));

		std::list<int64_t> numbers{ 0 };
		size_t current = 0;

		for (int64_t i = 1; i < 2018; ++i)
		{
			current = (current + steps) % numbers.size() + 1;
			numbers.insert(std::next(numbers.begin(), current), i);
		}

		return *std::next(numbers.begin(), current + 1);
	}

	int64_t part2()
	{
		const auto steps = std::stoll(getLine("Day17.txt"));

		size_t current = 0;
		int64_t result = 0;

		for (int64_t i = 1; i <= 50'000'000; ++i)
		{
			current = ((current + steps + 1) % i);
			if (current == 0)
			{
				result = i;
			}
		}

		return result;
	}
}
