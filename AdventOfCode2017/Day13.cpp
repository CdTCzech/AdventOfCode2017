#include "Day13.h"

#include "FileReader.h"

#include <algorithm>
#include <iterator>
#include <sstream>


namespace day13
{
	int64_t part1()
	{
		std::vector<std::pair<int64_t, int64_t>> scanners;
		for (const auto& line : getLineByLine("Day13.txt"))
		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
			scanners.emplace_back(std::stoll(tokens[0].substr(0, tokens[0].size() - 1)), std::stoll(tokens[1]));
		}

		int64_t result = 0;

		for (const auto& scaner : scanners)
		{
			if (scaner.first % ((scaner.second - 1) * 2) == 0)
			{
				result += scaner.first * scaner.second;
			}
		}

		return result;
	}

	int64_t part2()
	{
		std::vector<std::pair<int64_t, int64_t>> scanners;
		for (const auto& line : getLineByLine("Day13.txt"))
		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
			scanners.emplace_back(std::stoll(tokens[0].substr(0, tokens[0].size() - 1)), std::stoll(tokens[1]));
		}

		int64_t result = 0;

		while (std::any_of(std::begin(scanners), std::end(scanners), [result](const std::pair<int64_t, int64_t>& scan)
		{
			return (result + scan.first) % ((scan.second - 1) * 2) == 0;
		}))
		{
			++result;
		}

		return result;
	}
}
