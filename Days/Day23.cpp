#include "Day23.h"

#include "../FileReader.h"

#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <locale>

namespace day23
{
	int64_t part1()
	{
		int64_t result = 0;
		std::vector<int64_t> registers(8, 0);
		std::vector<std::vector<std::string>> instructions;

		for (const auto& line : getLineByLine("Days\\Day23.txt"))
		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
			instructions.emplace_back(tokens);
		}

		const std::locale loc;
		size_t index = 0;

		while (index < instructions.size())
		{
			const auto& current = instructions.at(index);

			if (current[0] == "set")
			{
				if (std::isalpha(current[2][0], loc))
				{
					registers[current[1][0] - 'a'] = registers[current[2][0] - 'a'];
				}
				else
				{
					registers[current[1][0] - 'a'] = std::stoll(current[2]);
				}
			}
			else if (instructions[index][0] == "sub")
			{
				if (std::isalpha(current[2][0], loc))
				{
					registers[current[1][0] - 'a'] -= registers[current[2][0] - 'a'];
				}
				else
				{
					registers[current[1][0] - 'a'] -= std::stoll(current[2]);
				}
			}
			else if (instructions[index][0] == "mul")
			{
				if (std::isalpha(current[2][0], loc))
				{
					registers[current[1][0] - 'a'] *= registers[current[2][0] - 'a'];
				}
				else
				{
					registers[current[1][0] - 'a'] *= std::stoll(current[2]);
				}
				++result;
			}
			else if (instructions[index][0] == "jnz")
			{
				if (std::isalpha(current[1][0], loc))
				{
					if (registers[current[1][0] - 'a'] != 0)
					{
						index += std::stoll(current[2]);
						continue;
					}
				}
				else
				{
					if (std::stoll(current[1]) != 0)
					{
						index += std::stoll(current[2]);
						continue;
					}
				}
			}
			++index;
		}
		return result;
	}

	int64_t part2()
	{
		int64_t result = 0;

		for (int64_t b = 109'900; b <= 126'900; b += 17)
		{
			auto isPrime = true;

			for (int64_t i = 2; i <= b / 2; ++i)
			{
				if (b % i == 0)
				{
					isPrime = false;
					break;
				}
			}

			if (!isPrime)
			{
				++result;
			}
		}

		return result;
	}

	/*
	int64_t part2Slow()
	{
		int64_t g = 0;
		int64_t h = 0;

		for (int64_t b = 109'900; b <= 126'900; b += 17)
		{
			int64_t f = 1;
			int64_t d = 2;

			do
			{
				if (b % d == 0 && b / d >= 2)
				{
					f = 0;
				}

				++d;
				g = d - b;
			} while (g != 0);

			if (f == 0)
			{
				++h;
			}
		}

		return h;
	}
	*/

	/*
	int64_t part2Assembler()
	{
		int64_t g = 0;
		int64_t h = 0;

		for (int64_t b = 109'900; b <= 126'900; b += 17)
		{
			int64_t f = 1;
			int64_t d = 2;

			do
			{
				int64_t e = 2;

				do
				{
					g = d * e - b;
					if (g == 0)
					{
						f = 0;
					}
					++e;
					g = e - b;
				} while (g != 0);

				++d;
				g = d - b;
			} while (g != 0);

			if (f == 0)
			{
				++h;
			}
		}

		return h;
	}
	*/
}
