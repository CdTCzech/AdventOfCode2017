#pragma once

#include <chrono>
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
		const auto start = std::chrono::high_resolution_clock::now();
		const auto result = func();
		const auto time = std::chrono::high_resolution_clock::now() - start;
		const auto same = result == expected;
		const auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO info;
		WORD attributes = 7;
		if (GetConsoleScreenBufferInfo(handle, &info))
		{
			attributes = info.wAttributes;
		}

		auto dayString = std::to_string(day);
		if (day < 10) dayString = '0' + dayString;
		auto partSring = std::to_string(part);
		if (part < 10) partSring = '0' + partSring;

		const auto message = dayString + '|' + partSring + " time: " + std::to_string(std::chrono::duration_cast<std::chrono::microseconds>(time).count()) + " result: ";

		if (same)
		{
			SetConsoleTextAttribute(handle, 10);
			std::cout << message << result << ") status: OK\n";
			SetConsoleTextAttribute(handle, attributes);
		}
		else
		{
			SetConsoleTextAttribute(handle, 12);
			std::cout << message << result << " expected: " << expected << ") status: FAIL\n";
			SetConsoleTextAttribute(handle, attributes);
		}

		return same;
	}
}
