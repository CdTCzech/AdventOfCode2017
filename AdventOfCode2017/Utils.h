#pragma once

#include <string>
#include <sstream>


namespace utils
{
	template<typename T = int64_t, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
	auto toInteger(const std::string& number)
	{
		T result;
		std::istringstream numberStream(number);
		numberStream >> result;
		return result;
	}
}
