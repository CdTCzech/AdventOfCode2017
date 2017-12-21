#include "Day18.h"

#include "FileReader.h"

#include <iterator>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <locale>


namespace day18
{
	int64_t part1()
	{
		std::vector<int64_t> registers(26, 0);
		std::vector<std::vector<std::string>> instructions;

		for (const auto& line : getLineByLine("Day18.txt"))
		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
			instructions.emplace_back(tokens);
		}

		const std::locale loc;
		int64_t lastFrequency = -1993;
		size_t index = 0;

		while (true)
		{
			if (instructions[index][0] == "snd")
			{
				lastFrequency = registers[instructions[index][1][0] - 'a'];
			}
			else if (instructions[index][0] == "set" && std::isalpha(instructions[index][2][0], loc))
			{
				registers[instructions[index][1][0] - 'a'] = registers[instructions[index][2][0] - 'a'];
			}
			else if (instructions[index][0] == "set")
			{
				registers[instructions[index][1][0] - 'a'] = std::stoll(instructions[index][2]);
			}
			else if (instructions[index][0] == "add" && std::isalpha(instructions[index][2][0], loc))
			{
				registers[instructions[index][1][0] - 'a'] += registers[instructions[index][2][0] - 'a'];
			}
			else if (instructions[index][0] == "add")
			{
				registers[instructions[index][1][0] - 'a'] += std::stoll(instructions[index][2]);
			}
			else if (instructions[index][0] == "mul" && std::isalpha(instructions[index][2][0], loc))
			{
				registers[instructions[index][1][0] - 'a'] *= registers[instructions[index][2][0] - 'a'];
			}
			else if (instructions[index][0] == "mul")
			{
				registers[instructions[index][1][0] - 'a'] *= std::stoll(instructions[index][2]);
			}
			else if (instructions[index][0] == "mod" && std::isalpha(instructions[index][2][0], loc))
			{
				registers[instructions[index][1][0] - 'a'] %= registers[instructions[index][2][0] - 'a'];
			}
			else if (instructions[index][0] == "mod")
			{
				registers[instructions[index][1][0] - 'a'] %= std::stoll(instructions[index][2]);
			}
			else if (instructions[index][0] == "rcv")
			{
				if (registers[instructions[index][1][0] - 'a'] != 0)
				{
					return lastFrequency;
				}
			}
			else if (instructions[index][0] == "jgz")
			{
				if (registers[instructions[index][1][0] - 'a'] > 0)
				{
					if (std::isalpha(instructions[index][2][0], loc))
					{
						index += registers[instructions[index][2][0] - 'a'];
					}
					else
					{
						index += std::stoll(instructions[index][2]);
					}
					continue;
				}
			}
			++index;
		}
	}

	class Cpu
	{
	public:
		Cpu() : m_registers(26, 0), m_sendTimes(0)
		{	
		}

		int64_t& operator[](const size_t index)
		{
			return m_registers[index];
		}

		void send(const size_t index)
		{
			m_toSend.push(m_registers[index]);
			++m_sendTimes;
		}

		int64_t recieve()
		{
			const auto temp = m_toSend.front();
			m_toSend.pop();
			return temp;
		}

		int64_t sendTimes() const
		{
			return m_sendTimes;
		}

	private:
		std::vector<int64_t> m_registers;
		std::queue<int64_t> m_toSend;
		int64_t m_sendTimes;
	};

	Cpu cpu0;
	Cpu cpu1;

	void cpuWork(const std::vector<std::vector<std::string>>& instructions, Cpu& cpu, Cpu& otherCpu)
	{
		const std::locale loc;
		size_t index = 0;

		while (true)
		{
			if (instructions[index][0] == "snd")
			{
				cpu.send(instructions[index][1][0] - 'a');
			}
			else if (instructions[index][0] == "set" && std::isalpha(instructions[index][2][0], loc))
			{
				cpu[instructions[index][1][0] - 'a'] = cpu[instructions[index][2][0] - 'a'];
			}
			else if (instructions[index][0] == "set")
			{
				cpu[instructions[index][1][0] - 'a'] = std::stoll(instructions[index][2]);
			}
			else if (instructions[index][0] == "add" && std::isalpha(instructions[index][2][0], loc))
			{
				cpu[instructions[index][1][0] - 'a'] += cpu[instructions[index][2][0] - 'a'];
			}
			else if (instructions[index][0] == "add")
			{
				cpu[instructions[index][1][0] - 'a'] += std::stoll(instructions[index][2]);
			}
			else if (instructions[index][0] == "mul" && std::isalpha(instructions[index][2][0], loc))
			{
				cpu[instructions[index][1][0] - 'a'] *= cpu[instructions[index][2][0] - 'a'];
			}
			else if (instructions[index][0] == "mul")
			{
				cpu[instructions[index][1][0] - 'a'] *= std::stoll(instructions[index][2]);
			}
			else if (instructions[index][0] == "mod" && std::isalpha(instructions[index][2][0], loc))
			{
				cpu[instructions[index][1][0] - 'a'] %= cpu[instructions[index][2][0] - 'a'];
			}
			else if (instructions[index][0] == "mod")
			{
				cpu[instructions[index][1][0] - 'a'] %= std::stoll(instructions[index][2]);
			}
			else if (instructions[index][0] == "rcv")
			{
				cpu[instructions[index][1][0] - 'a'] = otherCpu.recieve();
			}
			else if (instructions[index][0] == "jgz")
			{
				if (cpu[instructions[index][1][0] - 'a'] > 0)
				{
					if (std::isalpha(instructions[index][2][0], loc))
					{
						index += cpu[instructions[index][2][0] - 'a'];
					}
					else
					{
						index += std::stoll(instructions[index][2]);
					}
					continue;
				}
			}
			++index;
		}
	}

	int64_t part2()
	{
		std::vector<std::vector<std::string>> instructions;

		for (const auto& line : getLineByLine("Day18.txt"))
		{
			std::istringstream iss(line);
			std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
			instructions.emplace_back(tokens);
		}
		
		return 0;
	}
}
