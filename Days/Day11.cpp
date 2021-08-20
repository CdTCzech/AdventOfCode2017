#include "Day11.h"

#include "../FileReader.h"


namespace day11
{
	int64_t part1()
	{
		const auto line = getLine("Days\\Day11.txt");

		std::vector<std::string> tokens;
		std::size_t start = 0, end = 0;
		while ((end = line.find(',', start)) != std::string::npos)
		{
			if (end != start)
			{
				tokens.emplace_back(line.substr(start, end - start));
			}
			start = end + 1;
		}
		if (end != start)
		{
			tokens.emplace_back(line.substr(start));
		}

		int64_t x = 0;
		int64_t y = 0;

		for (const auto& token : tokens)
		{
			if (token == "n")
			{
				++y;
			}
			else if (token == "ne")
			{
				++x;
			}
			else if (token == "se")
			{
				++x;
				--y;
			}
			else if (token == "s")
			{
				--y;
			}
			else if (token == "sw")
			{
				--x;
			}
			else if (token == "nw")
			{
				--x;
				++y;
			}
		}

		return (std::abs(x) + std::abs(y) + std::abs(x + y)) / 2;
	}

	int64_t part2()
	{
		const auto line = getLine("Days\\Day11.txt");

		std::vector<std::string> tokens;
		std::size_t start = 0, end = 0;
		while ((end = line.find(',', start)) != std::string::npos)
		{
			if (end != start)
			{
				tokens.emplace_back(line.substr(start, end - start));
			}
			start = end + 1;
		}
		if (end != start)
		{
			tokens.emplace_back(line.substr(start));
		}

		int64_t result = 0;
		int64_t x = 0;
		int64_t y = 0;

		for (const auto& token : tokens)
		{
			if (token == "n")
			{
				++y;
			}
			else if (token == "ne")
			{
				++x;
			}
			else if (token == "se")
			{
				++x;
				--y;
			}
			else if (token == "s")
			{
				--y;
			}
			else if (token == "sw")
			{
				--x;
			}
			else if (token == "nw")
			{
				--x;
				++y;
			}

			const auto temp = (std::abs(x) + std::abs(y) + std::abs(x + y)) / 2;
			if (temp > result)
			{
				result = temp;
			}
		}

		return result;
	}
}
