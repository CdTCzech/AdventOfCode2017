#include "Day1.h"
#include "Day2.h"
#include "Day3.h"

#include "Test.h"


int main(int /*argc*/, char** /*argv*/)
{
	test::test<int64_t>(1, 1,   1'119, day1::part1);
	test::test<int64_t>(1, 2,   1'420, day1::part2);
	test::test<int64_t>(2, 1,  36'174, day2::part1);
	test::test<int64_t>(2, 2,     244, day2::part2);
	test::test<int64_t>(3, 1,     326, day3::part1);
	test::test<int64_t>(3, 2, 363'010, day3::part2);

	system("pause");
	return 0;
}
