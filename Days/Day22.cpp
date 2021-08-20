#include "Day22.h"

#include "../FileReader.h"

#include <map>
#include <set>

namespace day22
{
	enum Facing
	{
		Up,
		Right,
		Down,
		Left
	};

	Facing& operator++(Facing& facing)
	{
		switch (facing)
		{
		case Up: facing = Right; break;
		case Right: facing = Down; break;
		case Down: facing = Left; break;
		case Left: facing = Up; break;
		}
		return facing;
	}

	Facing& operator--(Facing& facing)
	{
		switch (facing)
		{
		case Up: facing = Left; break;
		case Right: facing = Up; break;
		case Down: facing = Right; break;
		case Left: facing = Down; break;
		}
		return facing;
	}

	Facing& operator~(Facing& facing)
	{
		switch (facing)
		{
		case Up: facing = Down; break;
		case Right: facing = Left; break;
		case Down: facing = Up; break;
		case Left: facing = Right; break;
		}
		return facing;
	}

	int64_t part1()
	{
		int64_t result = 0;
		std::set<std::pair<int64_t, int64_t>> infected;

		int64_t y = 12;
		for (const auto& line : getLineByLine("Days\\Day22.txt"))
		{
			int64_t x = -12;
			for (const auto& character : line)
			{
				if (character == '#')
				{
					infected.emplace(x, y);
				}
				++x;
			}
			--y;
		}

		auto current = std::make_pair(static_cast<int64_t>(0), static_cast<int64_t>(0));
		auto facing = Up;

		for (int64_t i = 0; i < 10'000; ++i)
		{
			const auto isInfected = infected.find(current) != infected.end();

			if (isInfected)
			{
				++facing;
				infected.erase(current);
			}
			else
			{
				--facing;
				infected.emplace(current);
				++result;
			}

			switch (facing)
			{
			case Up: ++current.second; break;
			case Right: ++current.first; break;
			case Down: --current.second; break;
			case Left: --current.first; break;
			}
		}

		return result;
	}

	enum State
	{
		Clean,
		Weakened,
		Infected,
		Flagged
	};

	State& operator++(State& state)
	{
		switch (state)
		{
		case Clean: state = Weakened; break;
		case Weakened: state = Infected; break;
		case Infected: state = Flagged; break;
		case Flagged: state = Clean; break;
		}
		return state;
	}

	int64_t part2()
	{
		int64_t result = 0;
		std::map<std::pair<int64_t, int64_t>, State> grid;

		int64_t y = 12;
		for (const auto& line : getLineByLine("Days\\Day22.txt"))
		{
			int64_t x = -12;
			for (const auto& character : line)
			{
				if (character == '#')
				{
					grid.emplace(std::make_pair(x, y), Infected);
				}
				else
				{
					grid.emplace(std::make_pair(x, y), Clean);
				}
				++x;
			}
			--y;
		}

		auto position = std::make_pair(static_cast<int64_t>(0), static_cast<int64_t>(0));
		auto facing = Up;

		for (int64_t i = 0; i < 10'000'000; ++i)
		{
			auto current = grid.find(position);
			if (current == grid.end())
			{
				grid.emplace(position, Clean);
				current = grid.find(position);
			}

			switch (current->second)
			{
			case Clean: --facing; break;
			case Weakened: break;
			case Infected: ++facing; break;
			case Flagged: ~facing; break;
			}

			++current->second;

			if (current->second == Infected) ++result;

			switch (facing)
			{
			case Up: ++position.second; break;
			case Right: ++position.first; break;
			case Down: --position.second; break;
			case Left: --position.first; break;
			}
		}

		return result;
	}
}