#include "Day15.h"

#include "FileReader.h"

#include <array>
#include <sstream>


namespace day15
{
	int64_t part1()
	{
		int64_t result = 0;
		std::array<uint64_t, 2> values{};
		auto second = false;

		for (const auto& line : getLineByLine("Day15.txt"))
		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };

			if (second)
			{
				values[1] = std::stoull(tokens.back());
			}
			else
			{
				values[0] = std::stoull(tokens.back());
				second = true;
			}
		}

		for (size_t i = 0; i < 40'000'000; ++i)
		{
			values[0] = (values[0] * 16'807ull) % 2'147'483'647ull;
			values[1] = (values[1] * 48'271ull) % 2'147'483'647ull;

			const auto tempA = values[0] & 0xFFFF;
			const auto tempB = values[1] & 0xFFFF;

			if (tempA == tempB)
			{
				++result;
			}
		}

		return result;
	}

	int64_t part2()
	{
		int64_t result = 0;
		std::array<uint64_t, 2> values{};
		auto second = false;

		for (const auto& line : getLineByLine("Day15.txt"))
		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };

			if (second)
			{
				values[1] = std::stoull(tokens.back());
			}
			else
			{
				values[0] = std::stoull(tokens.back());
				second = true;
			}
		}

		for (size_t i = 0; i < 5'000'000; ++i)
		{
			values[0] = (values[0] * 16'807ull) % 2'147'483'647ull;
			while (values[0] % 4 != 0)
			{
				values[0] = (values[0] * 16'807ull) % 2'147'483'647ull;
			}

			values[1] = (values[1] * 48'271ull) % 2'147'483'647ull;
			while (values[1] % 8 != 0)
			{
				values[1] = (values[1] * 48'271ull) % 2'147'483'647ull;
			}

			const auto tempA = values[0] & 0xFFFF;
			const auto tempB = values[1] & 0xFFFF;

			if (tempA == tempB)
			{
				++result;
			}
		}

		return result;
	}
}
