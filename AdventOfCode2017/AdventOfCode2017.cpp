#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"
#include "Day6.h"
#include "Day7.h"
#include "Day8.h"
#include "Day9.h"
#include "Day10.h"
#include "Day11.h"
#include "Day12.h"
#include "Day13.h"
#include "Day14.h"
#include "Day15.h"
#include "Day16.h"
#include "Day17.h"
//#include "Day18.h"

#include "Test.h"

#include <cstdint>
#include <iostream>
#include <string>


int main(int /*argc*/, char** /*argv*/)
{
	try
	{
		test::test<int64_t>(     1, 1,                              1'119,  day1::part1);
		test::test<int64_t>(     1, 2,                              1'420,  day1::part2);
		test::test<int64_t>(     2, 1,                             36'174,  day2::part1);
		test::test<int64_t>(     2, 2,                                244,  day2::part2);
		test::test<int64_t>(     3, 1,                                326,  day3::part1);
		test::test<int64_t>(     3, 2,                            363'010,  day3::part2);
		test::test<int64_t>(     4, 1,                                451,  day4::part1);
		test::test<int64_t>(     4, 2,                                223,  day4::part2);
		test::test<int64_t>(     5, 1,                            387'096,  day5::part1);
		test::test<int64_t>(     5, 2,                         28'040'648,  day5::part2);
		test::test<int64_t>(     6, 1,                             14'029,  day6::part1);
		test::test<int64_t>(     6, 2,                              2'765,  day6::part2);
		test::test<std::string>( 7, 1,                          "xegshds",  day7::part1);
		test::test<int64_t>(     7, 2,                                299,  day7::part2);
		test::test<int64_t>(     8, 1,                              4'902,  day8::part1);
		test::test<int64_t>(     8, 2,                              7'037,  day8::part2);
		test::test<int64_t>(     9, 1,                             11'846,  day9::part1);
		test::test<int64_t>(     9, 2,                              6'285,  day9::part2);
		test::test<int64_t>(    10, 1,                              9'656, day10::part1);
		test::test<std::string>(10, 2, "20b7b54c92bf73cf3e5631458a715149", day10::part2);
		test::test<int64_t>(    11, 1,                                764, day11::part1);
		test::test<int64_t>(    11, 2,                              1'532, day11::part2);
		test::test<int64_t>(    12, 1,                                130, day12::part1);
		test::test<int64_t>(    12, 2,                                189, day12::part2);
		test::test<int64_t>(    13, 1,                              1'476, day13::part1);
		test::test<int64_t>(    13, 2,                          3'937'334, day13::part2);
		test::test<int64_t>(    14, 1,                              8'230, day14::part1);
		test::test<int64_t>(    14, 2,                              1'103, day14::part2);
		test::test<int64_t>(    15, 1,                                594, day15::part1);
		test::test<int64_t>(    15, 2,                                328, day15::part2);
		test::test<std::string>(16, 1,                 "fnloekigdmpajchb", day16::part1);
		test::test<std::string>(16, 2,                 "amkjepdhifolgncb", day16::part2);
		test::test<int64_t>(    17, 1,                                926, day17::part1);
		test::test<int64_t>(    17, 2,                         10'150'888, day17::part2);
		//test::test<int64_t>(    18, 1,                              3'423, day18::part1);
		//test::test<int64_t>(    18, 2,                              3'423, day18::part2);
	}
	catch (std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}

	system("pause");
	return 0;
}
