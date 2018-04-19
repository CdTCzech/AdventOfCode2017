#include "Day19.h"

#include "FileReader.h"

#include <vector>


namespace day19
{
	enum class Direction
	{
		Down,
		Left,
		Right,
		Up
	};

	std::string part1()
	{
		std::string result;
		std::vector<std::string> grid;

		for (const auto& line : getLineByLine("Day19.txt"))
		{
			grid.emplace_back(line);
		}

		Direction direction = Direction::Down;
		size_t x = 0;
		size_t y = 0;

		for (const auto& character : grid[0])
		{
			if (character == '|')
			{
				break;
			}
			++x;
		}

		while (true)
		{
			if (grid[y][x] == ' ')
			{
				break;
			}

			if (grid[y][x] >= 'A' && grid[y][x] <= 'Z')
			{
				result += grid[y][x];
			}

			if (grid[y][x] == '+')
			{
				if (grid[y - 1][x] == '|' && direction != Direction::Down)
				{
					direction = Direction::Up;
				}
				else if (grid[y + 1][x] == '|' && direction != Direction::Up)
				{
					direction = Direction::Down;
				}
				else if (grid[y][x - 1] == '-' && direction != Direction::Right)
				{
					direction = Direction::Left;
				}
				else if (grid[y][x + 1] == '-' && direction != Direction::Left)
				{
					direction = Direction::Right;
				}
			}

			if (direction == Direction::Up)
			{
				--y;
			}
			else if (direction == Direction::Down)
			{
				++y;
			}
			else if (direction == Direction::Left)
			{
				--x;
			}
			else if (direction == Direction::Right)
			{
				++x;
			}
		}


		return result;
	}

	int64_t part2()
	{
		int64_t result = 0;
		std::vector<std::string> grid;

		for (const auto& line : getLineByLine("Day19.txt"))
		{
			grid.emplace_back(line);
		}

		Direction direction = Direction::Down;
		size_t x = 0;
		size_t y = 0;

		for (const auto& character : grid[0])
		{
			if (character == '|')
			{
				break;
			}
			++x;
		}

		while (true)
		{
			if (grid[y][x] == ' ')
			{
				break;
			}

			++result;

			if (grid[y][x] == '+')
			{
				if (grid[y - 1][x] == '|' && direction != Direction::Down)
				{
					direction = Direction::Up;
				}
				else if (grid[y + 1][x] == '|' && direction != Direction::Up)
				{
					direction = Direction::Down;
				}
				else if (grid[y][x - 1] == '-' && direction != Direction::Right)
				{
					direction = Direction::Left;
				}
				else if (grid[y][x + 1] == '-' && direction != Direction::Left)
				{
					direction = Direction::Right;
				}
			}

			if (direction == Direction::Up)
			{
				--y;
			}
			else if (direction == Direction::Down)
			{
				++y;
			}
			else if (direction == Direction::Left)
			{
				--x;
			}
			else if (direction == Direction::Right)
			{
				++x;
			}
		}


		return result;
	}
}
