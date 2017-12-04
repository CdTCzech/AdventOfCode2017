#pragma once

#include "FileReader.h"

#include <cstdint>


namespace day1
{
	inline uint64_t part1()
	{
		auto line = getLine("Day1.txt");

		if (line.empty())
		{
			return 0;
		}

		line += line[0];

		uint64_t result = 0;

		for (size_t i = 0; i < line.size() - 1; ++i)
		{
			if (line[i] == line[i + 1])
			{
				result += line[i] - '0';
			}
		}

		return result;
	}

	inline uint64_t part2()
	{
		auto line = getLine("Day1.txt");

		if (line.empty())
		{
			return 0;
		}

		const auto halfway = line.size() / 2;

		uint64_t result = 0;

		for (size_t i = 0; i < line.size() - 1; ++i)
		{
			const auto index = (i + halfway) % line.size();
			if (line[i] == line[index])
			{
				result += line[i] - '0';
			}
		}

		return result;
	}
}
