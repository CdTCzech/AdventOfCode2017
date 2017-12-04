#pragma once

#include "FileReader.h"

#include <algorithm>
#include <cstdint>
#include <iterator>
#include <set>
#include <sstream>
#include <vector>


namespace day4
{
	inline int64_t part1()
	{
		int64_t result = 0;

		for (auto line : getLineByLine("Day4.txt"))
		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
			std::set<std::string> unique;
			auto allUniques = true;

			for (const auto& token : tokens)
			{
				const auto search = unique.find(token);
				if (search == unique.end())
				{
					unique.insert(token);
				}
				else
				{
					allUniques = false;
					break;
				}
			}

			if (allUniques) ++result;
		}

		return result;
	}

	inline int64_t part2()
	{
		int64_t result = 0;

		for (auto line : getLineByLine("Day4.txt"))
		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
			std::set<std::string> unique;
			auto allUniques = true;

			for (auto& token : tokens)
			{
				std::sort(token.begin(), token.end());
			}

			for (const auto& token : tokens)
			{
				const auto search = unique.find(token);
				if (search == unique.end())
				{
					unique.insert(token);
				}
				else
				{
					allUniques = false;
					break;
				}
			}

			if (allUniques) ++result;
		}

		return result;
	}
}
