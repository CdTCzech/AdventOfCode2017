#include "Day14.h"

#include "../FileReader.h"

#include <bitset>
#include <string>
#include <vector>


namespace day14
{
	std::vector<int64_t> knotHash(const std::string& toHash)
	{
		constexpr size_t SIZE = 256;

		std::vector<size_t> lenghts;
		for (const auto& character : toHash)
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

		return hashes;
	}

	int64_t part1()
	{
		const auto line = getLine("Days\\Day14.txt");
		int64_t result = 0;

		for (size_t i = 0; i < 128; ++i)
		{
			auto hash = knotHash(line + '-' + std::to_string(i));
			for (const auto& number : hash)
			{
				std::bitset<8> bits = number;
				result += bits.count();
			}
		}

		return result;
	}

	void removeGroup(std::vector<std::string>& grid, const size_t x, const size_t y)
	{
		if (x > 127 || y > 127 || grid[y][x] != '1')
		{
			return;
		}

		grid[y][x] = 'X';

		removeGroup(grid, x - 1, y);
		removeGroup(grid, x + 1, y);
		removeGroup(grid, x, y - 1);
		removeGroup(grid, x, y + 1);
	}

	int64_t part2()
	{
		const auto line = getLine("Days\\Day14.txt");
		std::vector<std::string> grid;

		for (size_t i = 0; i < 128; ++i)
		{
			auto hash = knotHash(line + '-' + std::to_string(i));
			std::string row;
			for (const auto& number : hash)
			{
				std::bitset<8> bits = number;
				row += bits.to_string();
			}
			grid.push_back(row);
		}

		int64_t result = 0;

		for (size_t y = 0; y < 128; ++y)
		{
			for (size_t x = 0; x < 128; ++x)
			{
				if (grid[y][x] == '1')
				{
					removeGroup(grid, x, y);
					++result;
				}
			}
		}

		return result;
	}
}
