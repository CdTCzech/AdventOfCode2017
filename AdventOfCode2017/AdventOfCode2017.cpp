#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"

#include "Test.h"


int main(int /*argc*/, char** /*argv*/)
{
	test::test<int64_t>( 1,  1,      1'119, day1::part1);
	test::test<int64_t>( 1,  2,      1'420, day1::part2);
	test::test<int64_t>( 2,  1,     36'174, day2::part1);
	test::test<int64_t>( 2,  2,        244, day2::part2);
	test::test<int64_t>( 3,  1,        326, day3::part1);
	test::test<int64_t>( 3,  2,    363'010, day3::part2);
	test::test<int64_t>( 4,  1,        451, day4::part1);
	test::test<int64_t>( 4,  2,        223, day4::part2);
	test::test<int64_t>( 5,  1,    387'096, day5::part1);
	test::test<int64_t>( 5,  2, 28'040'648, day5::part2);

	system("pause");
	return 0;
}
