#pragma once

#include <cstdint>
#include <functional>
#include <iostream>
#include <string>

#include <Windows.h>


namespace test
{
	template<typename T>
	bool test(const uint8_t day, const uint8_t part, const T expected, std::function<T()> func)
	{
		const auto result = func();
		const auto same = result == expected;
		const auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO info;
		WORD attributes = 7;
		if (GetConsoleScreenBufferInfo(handle, &info))
		{
			attributes = info.wAttributes;
		}

		if (same)
		{
			SetConsoleTextAttribute(handle, 10);
			std::cout << "Day " << std::to_string(day) << " Part " << std::to_string(part) << " result: OK (" << result << ")\n";
			SetConsoleTextAttribute(handle, attributes);
		}
		else
		{
			SetConsoleTextAttribute(handle, 12);
			std::cout << "Day " << std::to_string(day) << " Part " << std::to_string(part) << " result: FAIL (" << result << ")\n";
			SetConsoleTextAttribute(handle, attributes);
		}

		return same;
	}
}
