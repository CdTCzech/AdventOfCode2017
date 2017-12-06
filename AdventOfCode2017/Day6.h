#pragma once

#include "FileReader.h"
#include "Utils.h"

#include <algorithm>
#include <cstdint>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <vector>


namespace day6
{
	inline std::string vectorToString(const std::vector<int64_t>& banks)
	{
		std::stringstream result;
		std::copy(banks.begin(), banks.end(), std::ostream_iterator<int64_t>(result, " "));
		return result.str();
	}

	inline int64_t part1()
	{
		const auto line = getLine("Day6.txt");
		std::vector<int64_t> banks;

		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
			for (const auto& token : tokens)
			{
				banks.emplace_back(utils::toInteger(token));
			}
		}

		if (banks.empty())
		{
			return 0;
		}

		std::set<std::string> states;
		int64_t result = 0;

		while (true)
		{
			const auto vectorString = vectorToString(banks);
			const auto it = states.find(vectorString);
			if (it != states.end())
			{
				return result;
			}

			states.insert(vectorString);

			auto maxIndex = std::distance(banks.begin(), std::max_element(banks.begin(), banks.end()));
			auto buffer = banks[maxIndex];
			banks[maxIndex] = 0;

			while (buffer != 0)
			{
				maxIndex = (maxIndex + 1) % banks.size();
				++banks[maxIndex];
				--buffer;
			}

			++result;
		}
	}

	inline int64_t part2()
	{
		const auto line = getLine("Day6.txt");
		std::vector<int64_t> banks;

		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
			for (const auto& token : tokens)
			{
				banks.emplace_back(utils::toInteger(token));
			}
		}

		if (banks.empty())
		{
			return 0;
		}

		std::map<std::string, int64_t> states;
		int64_t result = 0;

		while (true)
		{
			const auto vectorString = vectorToString(banks);
			const auto it = states.find(vectorString);
			if (it != states.end())
			{
				return result - it->second;
			}

			states.insert({ vectorString, result });

			auto maxIndex = std::distance(banks.begin(), std::max_element(banks.begin(), banks.end()));
			auto buffer = banks[maxIndex];
			banks[maxIndex] = 0;

			while (buffer != 0)
			{
				maxIndex = (maxIndex + 1) % banks.size();
				++banks[maxIndex];
				--buffer;
			}

			++result;
		}
	}
}
