#include "Day10.h"

#include "../FileReader.h"

#include <iomanip>
#include <sstream>
#include <string>
#include <vector>


namespace day10
{
	int64_t part1()
	{
		constexpr size_t SIZE = 256;
		const auto line = getLine("Days\\Day10.txt");

		std::vector<int64_t> tokens;
		std::size_t start = 0, end = 0;
		while ((end = line.find(',', start)) != std::string::npos)
		{
			if (end != start)
			{
				tokens.emplace_back(std::stoll(line.substr(start, end - start)));
			}
			start = end + 1;
		}
		if (end != start)
		{
			tokens.emplace_back(std::stoll(line.substr(start)));
		}

		size_t currentPosition = 0;
		size_t skipSize = 0;
		std::vector<int64_t> numbers(SIZE);

		for (size_t i = 0; i < SIZE; ++i)
		{
			numbers[i] = i;
		}

		for (const auto& token : tokens)
		{
			for (size_t i = 0; i < static_cast<size_t>(token / 2); ++i)
			{
				const auto first = (currentPosition + i) % SIZE;
				const auto second = (currentPosition + token - i - 1) % SIZE;
				std::swap(numbers[first], numbers[second]);
			}

			currentPosition += token + skipSize;
			++skipSize;
		}

		return numbers[0] * numbers[1];
	}

	std::string part2()
	{
		constexpr size_t SIZE = 256;
		const auto line = getLine("Days\\Day10.txt");

		std::vector<size_t> lenghts;
		for (const auto& character : line)
		{
			lenghts.emplace_back(static_cast<size_t>(character));
		}
		lenghts.emplace_back(17);
		lenghts.emplace_back(31);
		lenghts.emplace_back(73);
		lenghts.emplace_back(47);
		lenghts.emplace_back(23);

		size_t currentPosition = 0;
		size_t skipSize = 0;
		std::vector<int64_t> numbers(SIZE);

		for (size_t i = 0; i < SIZE; ++i)
		{
			numbers[i] = i;
		}

		for (size_t i = 0; i < 64; ++i)
		{
			for (const auto& lenght : lenghts)
			{
				for (size_t j = 0; j < static_cast<size_t>(lenght / 2); ++j)
				{
					const auto first = (currentPosition + j) % SIZE;
					const auto second = (currentPosition + lenght - j - 1) % SIZE;
					std::swap(numbers[first], numbers[second]);
				}

				currentPosition += lenght + skipSize;
				++skipSize;
			}
		}

		std::vector<int64_t> hashes;
		for (size_t i = 0; i < 16; ++i)
		{
			auto hash = numbers[i * 16];
			for (size_t j = 1; j < 16; ++j)
			{
				hash ^= numbers[i * 16 + j];
			}
			hashes.emplace_back(hash);
		}

		std::string result;
		for (const auto& hash : hashes)
		{
			std::stringstream stream;
			stream << std::setfill('0') << std::setw(2) << std::hex << hash;
			result += stream.str();
		}

		return result;
	}
}
