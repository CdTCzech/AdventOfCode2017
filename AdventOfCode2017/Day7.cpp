#include "Day7.h"

#include "FileReader.h"
#include "Utils.h"

#include <algorithm>
#include <array>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <vector>


namespace day7
{
	std::string part1()
	{
		std::set<std::string> programs;
		std::set<std::string> pointedPrograms;

		for (auto line : getLineByLine("Day7.txt"))
		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };

			programs.insert(tokens[0]);

			if (tokens.size() > 3)
			{
				for (size_t i = 3; i < tokens.size() - 1; ++i)
				{
					pointedPrograms.insert(tokens[i].substr(0, tokens[i].size() - 1));
				}

				pointedPrograms.insert(tokens.back());
			}
		}

		std::vector<std::string> result;
		std::set_symmetric_difference(programs.begin(), programs.end(), pointedPrograms.begin(), pointedPrograms.end(), std::inserter(result, result.end()));
		return result[0];
	}

	int64_t getWeight(const std::map<std::string, std::pair<int64_t, std::vector<std::string>>>& programs, const std::string& disc)
	{
		auto result = programs.at(disc).first;
		auto myDiscs = programs.at(disc).second;

		for (const auto& myDisc : myDiscs)
		{
			result += getWeight(programs, myDisc);
		}

		return result;
	}

	int64_t part2()
	{
		std::map<std::string, std::pair<int64_t, std::vector<std::string>>> programs;

		for (auto line : getLineByLine("Day7.txt"))
		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
			std::vector<std::string> points;

			if (tokens.size() > 3)
			{
				for (size_t i = 3; i < tokens.size() - 1; ++i)
				{
					points.emplace_back(tokens[i].substr(0, tokens[i].size() - 1));
				}

				points.emplace_back(tokens.back());
			}

			programs.insert({ tokens[0], { utils::toInteger(tokens[1].substr(1, tokens[1].size() - 1)), points} });
		}

		auto startDiscs = programs["xegshds"].second;
		std::vector<std::pair<std::string, int64_t>> weights;

		for (const auto& disc : startDiscs)
		{
			weights.emplace_back(disc, getWeight(programs, disc));
		}

		std::vector<std::pair<std::string, int64_t>> previousWeights;

		while (!std::equal(weights.begin() + 1, weights.end(), weights.begin(), [](const std::pair<std::string, int64_t>& a, const std::pair<std::string, int64_t>& b)
		{
			return a.second == b.second;
		}))
		{
			const auto first = weights[0];
			std::pair<std::string, int64_t> second { "", -1};
			int64_t firstCount = 1;

			for (size_t i = 1; i < weights.size(); ++i)
			{
				if (weights[i].second == first.second)
				{
					++firstCount;
				}
				else
				{
					if (second.first.empty())
					{
						second = weights[i];
					}
				}
			}

			if (firstCount == 1) startDiscs = programs[first.first].second;
			else startDiscs = programs[second.first].second;

			previousWeights = weights;
			weights.clear();

			for (const auto& disc : startDiscs)
			{
				weights.emplace_back(disc, getWeight(programs, disc));
			}
		}

		const auto first = previousWeights[0];
		std::pair<std::string, int64_t> second{ "", -1 };
		int64_t firstCount = 1;

		for (size_t i = 1; i < previousWeights.size(); ++i)
		{
			if (previousWeights[i].second == first.second)
			{
				++firstCount;
			}
			else
			{
				if (second.first.empty())
				{
					second = previousWeights[i];
				}
			}
		}

		int64_t result;

		if (firstCount == 1) result = programs[first.first].first + (second.second - first.second);
		else result = programs[second.first].first + (first.second - second.second);

		return result;
	}
}
