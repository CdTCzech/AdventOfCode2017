#pragma once

#include "FileReader.h"

#include <cstdint>
#include <sstream>


namespace day2
{
	inline int64_t part1()
	{
		int64_t result = 0;

		for (auto line : getLineByLine("Day2.txt"))
		{
			int64_t min = INT64_MAX;
			int64_t max = 0;
			int64_t current = 0;

			std::istringstream iss(line);
			while (iss >> current)
			{
				if (current > max) max = current;
				if (current < min) min = current;
			}

			result += max - min;
		}

		return result;
	}

	inline int64_t calc(const std::vector<int64_t>& numbers)
	{
		for (size_t i = 0; i < numbers.size() - 1; ++i)
		{
			for (auto j = i + 1; j < numbers.size() - 1; ++j)
			{
				if ((numbers[i] % numbers[j]) == 0)
				{
					return numbers[i] / numbers[j];
				}

				if ((numbers[j] % numbers[i]) == 0)
				{
					return numbers[j] / numbers[i];
				}
			}
		}

		return 0;
	}

	inline int64_t part2()
	{
		int64_t result = 0;

		for (auto line : getLineByLine("Day2.txt"))
		{
			int64_t current;
			std::vector<int64_t> numbers;
			std::istringstream iss(line);
			while (iss >> current)
			{
				numbers.emplace_back(current);
			}

			result += calc(numbers);
		}

		return result;
	}
}
