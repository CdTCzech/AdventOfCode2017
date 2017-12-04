#pragma once

#include "FileReader.h"
#include "Utils.h"

#include <algorithm>
#include <array>
#include <cstdint>


namespace day3
{
	inline int64_t part1()
	{
		const auto line = getLine("Day3.txt");
		const auto toFind = utils::toInteger(line);

		const auto root = static_cast<int64_t>(sqrt(toFind - 1));
		const auto index = toFind - root * root - 1;
		const auto half = root / 2;
		const auto low = abs(index - half);

		if (root % 2 == 0)
		{
			const auto high = abs(index - (root + half));
			return std::min(low, high) + half;
		}
		else
		{
			const auto high = abs(index - (root + half + 1));
			return std::min(low, high) + half + 1;
		}
	}

	inline int64_t part2()
	{
		const auto line = getLine("Day3.txt");
		const auto toFind = utils::toInteger(line);

		constexpr int64_t X = 11;
		constexpr int64_t Y = 11;
		constexpr auto XX = X / 2;
		constexpr auto YY = Y / 2;

		std::array<std::array<int64_t, Y>, X> grid{};
		for (auto& gridLine : grid) gridLine.fill(0);
		grid[XX][YY] = 1;

		int64_t x = 0;
		int64_t y = 0;
		int64_t dx = 0;
		int64_t dy = -1;
		auto t = std::max(X, Y);
		const auto maxI = t * t;

		for (int64_t i = 0; i < maxI; ++i)
		{
			if ((-X / 2 <= x) && (x <= X / 2) && (-Y / 2 <= y) && (y <= Y / 2))
			{
				const auto xx = x + XX;
				const auto yy = y + YY;
				int64_t sum = 0;

				for (int64_t j = -1; j < 2; ++j)
				{
					for (int64_t k = -1; k < 2; ++k)
					{
						sum += grid[xx + j][yy + k];
					}
				}

				if (sum > toFind)
				{
					return sum;
				}

				grid[xx][yy] = sum;
			}
			if ((x == y) || ((x < 0) && (x == -y)) || ((x > 0) && (x == 1 - y)))
			{
				t = dx;
				dx = -dy;
				dy = t;
			}
			x += dx;
			y += dy;
		}

		return 0;
	}
}
