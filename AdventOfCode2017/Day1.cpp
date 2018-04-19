#include "Day1.h"

#include "FileReader.h"


namespace day1
{
	int64_t part1()
	{
		auto line = getLine("Day1.txt");

		if (line.empty())
		{
			return 0;
		}

		line += line[0];

		int64_t result = 0;

		for (size_t i = 0; i < line.size() - 1; ++i)
		{
			if (line[i] == line[i + 1])
			{
				result += line[i] - '0';
			}
		}

		return result;
	}

	int64_t part2()
	{
		const auto line = getLine("Day1.txt");

		if (line.empty())
		{
			return 0;
		}

		const auto halfway = line.size() / 2;

		int64_t result = 0;

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
