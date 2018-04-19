#include "Day16.h"

#include "FileReader.h"

#include <algorithm>
#include <array>
#include <vector>

#include <iostream>


namespace day16
{
	std::string part1()
	{
		std::string programs{ "abcdefghijklmnop" };

		const auto line = getLine("Day16.txt");

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

		for (const auto& token : tokens)
		{
			if (token[0] == 's')
			{
				const auto number = std::stoull(token.substr(1));
				std::rotate(programs.begin(), programs.end() - number, programs.end());
			}
			else if (token[0] == 'x')
			{
				const auto slash = std::distance(token.begin(), std::find(token.begin(), token.end(), '/'));
				const auto first = std::stoull(token.substr(1, slash));
				const auto second = std::stoull(token.substr(slash + 1));
				std::swap(programs[first], programs[second]);
			}
			else if (token[0] == 'p')
			{
				const auto first = std::distance(programs.begin(), std::find(programs.begin(), programs.end(), token[1]));
				const auto second = std::distance(programs.begin(), std::find(programs.begin(), programs.end(), token[3]));
				std::swap(programs[first], programs[second]);
			}
		}

		return programs;
	}

	std::string part2()
	{
		std::string programs{ "abcdefghijklmnop" };
		std::string tempPrograms{ "abcdefghijklmnop" };

		const auto line = getLine("Day16.txt");

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

		std::vector<std::string> values;

		while (true)
		{
			values.emplace_back(programs);

			for (const auto& token : tokens)
			{
				if (token[0] == 's')
				{
					const auto number = std::stoull(token.substr(1));
					std::rotate(programs.begin(), programs.end() - number, programs.end());
				}
				else if (token[0] == 'x')
				{
					const auto slash = std::distance(token.begin(), std::find(token.begin(), token.end(), '/'));
					const auto first = std::stoull(token.substr(1, slash));
					const auto second = std::stoull(token.substr(slash + 1));
					std::swap(programs[first], programs[second]);
				}
				else if (token[0] == 'p')
				{
					const auto first = std::distance(programs.begin(), std::find(programs.begin(), programs.end(), token[1]));
					const auto second = std::distance(programs.begin(), std::find(programs.begin(), programs.end(), token[3]));
					std::swap(programs[first], programs[second]);
				}
			}

			if (programs == "abcdefghijklmnop")
			{
				break;
			}
		}

		return values[1'000'000'000ull % values.size()];
	}
}
