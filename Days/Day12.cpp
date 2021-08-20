#include "Day12.h"

#include "../FileReader.h"

#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>


namespace day12
{
	void getGroup(const std::map<int64_t, std::vector<int64_t>>& travelList, int64_t connection, std::set<int64_t>& group0)
	{
		group0.insert(connection);
		auto travels = travelList.at(connection);
		for (const auto& travel : travels)
		{
			if (group0.find(travel) == group0.end())
			{
				getGroup(travelList, travel, group0);
			}
		}
	}

	int64_t part1()
	{
		std::map<int64_t, std::vector<int64_t>> travelList;

		for (const auto& line : getLineByLine("Days\\Day12.txt"))
		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
			std::vector<int64_t> travels;

			if (tokens.size() > 3)
			{
				for (size_t i = 2; i < tokens.size() - 1; ++i)
				{
					travels.emplace_back(std::stoll(tokens[i].substr(0, tokens[i].size() - 1)));
				}
			}

			travels.emplace_back(std::stoll(tokens.back()));
			travelList.insert({ std::stoll(tokens[0]), travels });
		}

		std::set<int64_t> group0;
		getGroup(travelList, 0, group0);

		return group0.size();
	}

	int64_t part2()
	{
		std::map<int64_t, std::vector<int64_t>> travelList;

		for (const auto& line : getLineByLine("Days\\Day12.txt"))
		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
			std::vector<int64_t> travels;

			if (tokens.size() > 3)
			{
				for (size_t i = 2; i < tokens.size() - 1; ++i)
				{
					travels.emplace_back(std::stoll(tokens[i].substr(0, tokens[i].size() - 1)));
				}
			}

			travels.emplace_back(std::stoll(tokens.back()));
			travelList.insert({ std::stoll(tokens[0]), travels });
		}

		int64_t result = 0;
		std::set<int64_t> group;
		std::set<int64_t> all;
		for (int64_t i = 0; i < 2000; ++i)
		{
			all.insert(i);
		}

		while (!all.empty())
		{
			getGroup(travelList, *all.begin(), group);
			for (const auto& member : group)
			{
				const auto it = all.find(member);
				if (it != all.end())
				{
					all.erase(it);
				}
			}
			++result;
		}

		return result;
	}
}
