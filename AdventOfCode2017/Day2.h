#pragma once

#include "FileReader.h"

#include <cstdint>
#include <sstream>


namespace day2
{
	inline uint64_t part1()
	{
		uint64_t result = 0;

		for (auto line : getLineByLine("Day2.txt"))
		{
			uint64_t min = UINT64_MAX;
			uint64_t max = 0;
			uint64_t current = 0;

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

	inline uint64_t part2()
	{
		uint64_t result = 0;

		for (auto line : getLineByLine("Day2.txt"))
		{
			uint64_t current;
			std::vector<uint64_t> numbers;
			std::istringstream iss(line);
			while (iss >> current)
			{
				numbers.emplace_back(current);
			}

			for (size_t i = 0; i < numbers.size() - 1; ++i)
			{
				for (size_t j = i + 1; j < numbers.size() - 1; ++j)
				{
					if ((numbers[i] % numbers[j]) == 0) result += numbers[i] / numbers[j];
					if ((numbers[j] % numbers[i]) == 0) result += numbers[j] / numbers[i];
				}
			}
		}

		return result;
	}
}
