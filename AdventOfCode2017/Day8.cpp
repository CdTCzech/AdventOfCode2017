#include "Day8.h"

#include "FileReader.h"

#include <algorithm>
#include <iterator>
#include <map>
#include <sstream>
#include <string>


namespace day8
{
	int64_t part1()
	{
		std::map<std::string, int64_t> registers;

		for (const auto& line : getLineByLine("Day8.txt"))
		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };

			const auto firstInst = registers.find(tokens[0]);
			if (firstInst == registers.end())
			{
				registers.insert({ tokens[0], 0 });
			}

			const auto secondInst = registers.find(tokens[4]);
			if (secondInst == registers.end())
			{
				registers.insert({ tokens[4], 0 });
			}

			if (tokens[5] == ">")
			{
				if (registers[tokens[4]] > std::stoll(tokens[6]))
				{
					registers[tokens[0]] += tokens[1] == "inc" ? std::stoll(tokens[2]) : - std::stoll(tokens[2]);
				}
			}
			else if (tokens[5] == "<")
			{
				if (registers[tokens[4]] < std::stoll(tokens[6]))
				{
					registers[tokens[0]] += tokens[1] == "inc" ? std::stoll(tokens[2]) : -std::stoll(tokens[2]);
				}
			}
			else if (tokens[5] == ">=")
			{
				if (registers[tokens[4]] >= std::stoll(tokens[6]))
				{
					registers[tokens[0]] += tokens[1] == "inc" ? std::stoll(tokens[2]) : -std::stoll(tokens[2]);
				}
			}
			else if (tokens[5] == "<=")
			{
				if (registers[tokens[4]] <= std::stoll(tokens[6]))
				{
					registers[tokens[0]] += tokens[1] == "inc" ? std::stoll(tokens[2]) : -std::stoll(tokens[2]);
				}
			}
			else if (tokens[5] == "==")
			{
				if (registers[tokens[4]] == std::stoll(tokens[6]))
				{
					registers[tokens[0]] += tokens[1] == "inc" ? std::stoll(tokens[2]) : -std::stoll(tokens[2]);
				}
			}
			else if (tokens[5] == "!=")
			{
				if (registers[tokens[4]] != std::stoll(tokens[6]))
				{
					registers[tokens[0]] += tokens[1] == "inc" ? std::stoll(tokens[2]) : -std::stoll(tokens[2]);
				}
			}
		}

		return std::max_element(registers.begin(), registers.end(), [](const std::pair<std::string, int64_t>& first, const std::pair<std::string, int64_t>& second)
		{
			return first.second < second.second;
		})->second;
	}

	int64_t part2()
	{
		std::map<std::string, int64_t> registers;
		int64_t result = INT64_MIN;

		for (const auto& line : getLineByLine("Day8.txt"))
		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };

			const auto firstInst = registers.find(tokens[0]);
			if (firstInst == registers.end())
			{
				registers.insert({ tokens[0], 0 });
			}

			const auto secondInst = registers.find(tokens[4]);
			if (secondInst == registers.end())
			{
				registers.insert({ tokens[4], 0 });
			}

			if (tokens[5] == ">")
			{
				if (registers[tokens[4]] > std::stoll(tokens[6]))
				{
					registers[tokens[0]] += tokens[1] == "inc" ? std::stoll(tokens[2]) : -std::stoll(tokens[2]);
					if (registers[tokens[0]] > result)
					{
						result = registers[tokens[0]];
					}
				}
			}
			else if (tokens[5] == "<")
			{
				if (registers[tokens[4]] < std::stoll(tokens[6]))
				{
					registers[tokens[0]] += tokens[1] == "inc" ? std::stoll(tokens[2]) : -std::stoll(tokens[2]);
					if (registers[tokens[0]] > result)
					{
						result = registers[tokens[0]];
					}
				}
			}
			else if (tokens[5] == ">=")
			{
				if (registers[tokens[4]] >= std::stoll(tokens[6]))
				{
					registers[tokens[0]] += tokens[1] == "inc" ? std::stoll(tokens[2]) : -std::stoll(tokens[2]);
					if (registers[tokens[0]] > result)
					{
						result = registers[tokens[0]];
					}
				}
			}
			else if (tokens[5] == "<=")
			{
				if (registers[tokens[4]] <= std::stoll(tokens[6]))
				{
					registers[tokens[0]] += tokens[1] == "inc" ? std::stoll(tokens[2]) : -std::stoll(tokens[2]);
					if (registers[tokens[0]] > result)
					{
						result = registers[tokens[0]];
					}
				}
			}
			else if (tokens[5] == "==")
			{
				if (registers[tokens[4]] == std::stoll(tokens[6]))
				{
					registers[tokens[0]] += tokens[1] == "inc" ? std::stoll(tokens[2]) : -std::stoll(tokens[2]);
					if (registers[tokens[0]] > result)
					{
						result = registers[tokens[0]];
					}
				}
			}
			else if (tokens[5] == "!=")
			{
				if (registers[tokens[4]] != std::stoll(tokens[6]))
				{
					registers[tokens[0]] += tokens[1] == "inc" ? std::stoll(tokens[2]) : -std::stoll(tokens[2]);
					if (registers[tokens[0]] > result)
					{
						result = registers[tokens[0]];
					}
				}
			}
		}

		return result;
	}
}
