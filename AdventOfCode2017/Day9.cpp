#include "Day9.h"

#include "FileReader.h"


namespace day9
{
	int64_t part1()
	{
		const auto line = getLine("Day9.txt");
		int64_t result = 0;
		int64_t depth = 0;
		auto garbage = false;

		for (size_t i = 0; i < line.size(); ++i)
		{
			const auto character = line[i];
			if (character == '!')
			{
				++i;
			}
			else if (garbage && character != '>')
			{
				
			}
			else if (character == '{')
			{
				++depth;
			}
			else if (character == '}')
			{
				result += depth--;
			}
			else if (character == '<')
			{
				garbage = true;
			}
			else if (character == '>')
			{
				garbage = false;
			}
		}
		return result;
	}

	int64_t part2()
	{
		const auto line = getLine("Day9.txt");
		int64_t result = 0;
		int64_t depth = 0;
		auto garbage = false;

		for (size_t i = 0; i < line.size(); ++i)
		{
			const auto character = line[i];
			if (character == '!')
			{
				++i;
			}
			else if (garbage && character != '>')
			{
				++result;
			}
			else if (character == '{')
			{
				++depth;
			}
			else if (character == '}')
			{
				--depth;
			}
			else if (character == '<')
			{
				garbage = true;
			}
			else if (character == '>')
			{
				garbage = false;
			}
		}
		return result;
	}
}