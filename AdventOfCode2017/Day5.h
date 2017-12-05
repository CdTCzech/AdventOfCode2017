#pragma once

#include "FileReader.h"
#include "Utils.h"

#include <cstdint>
#include <vector>


namespace day5
{
	inline int64_t part1()
	{
		std::vector<int64_t> jumpList;

		for (auto line : getLineByLine("Day5.txt"))
		{
			jumpList.emplace_back(utils::toInteger(line));
		}

		int64_t result = 0;
		size_t index = 0;

		while (index < jumpList.size())
		{
			const auto newIndex = index + jumpList[index];
			++jumpList[index];
			index = newIndex;
			++result;
		}

		return result;
	}

	inline int64_t part2()
	{
		std::vector<int64_t> jumpList;

		for (auto line : getLineByLine("Day5.txt"))
		{
			jumpList.emplace_back(utils::toInteger(line));
		}

		int64_t result = 0;
		size_t index = 0;

		while (index < jumpList.size())
		{
			const auto newIndex = index + jumpList[index];
			if (jumpList[index] > 2)
			{
				--jumpList[index];
			}
			else
			{
				++jumpList[index];
			}
			index = newIndex;
			++result;
		}

		return result;
	}
}
