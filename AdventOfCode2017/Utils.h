#pragma once

#include <string>
#include <sstream>
#include <utility>


#define EXCEPTION(what) utils::AoCException(what, __FILE__, __LINE__)


namespace utils
{
	class AoCException : public std::exception
	{
	public:
		AoCException(const std::string& what, const std::string& file, const int line) : m_what("!!! EXCEPTION !!!\nFile: " + file + "\nLine: " + std::to_string(line) + "\nError: " + what)
		{
		}

		const char* what() const override
		{
			return m_what.c_str();
		}

	private:
		std::string m_what;
	};

	template<typename T = int64_t, typename std::enable_if<std::is_integral<T>::value, int>::type = 0>
	auto toInteger(const std::string& number)
	{
		if (number.empty())
		{
			EXCEPTION("Converting empty string to number");
		}

		T result;
		std::istringstream numberStream(number);
		numberStream >> result;
		return result;
	}
}
