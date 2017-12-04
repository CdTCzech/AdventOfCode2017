#include "Day1.h"

#include "Test.h"


int main(int /*argc*/, char** /*argv*/)
{
	test::test<int64_t>(1, 1, 1119, day1::part1);
	test::test<int64_t>(1, 2, 1420, day1::part2);

	system("pause");
	return 0;
}
