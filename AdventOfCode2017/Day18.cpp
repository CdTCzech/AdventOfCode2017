#include "Day18.h"

#include "FileReader.h"

#include <atomic>
#include <condition_variable>
#include <iterator>
#include <locale>
#include <mutex>
#include <queue>
#include <sstream>
#include <string>
#include <thread>
#include <vector>


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

	std::mutex m;
	std::condition_variable cv;

	bool terminate = false;

	class Cpu
	{
	public:
		Cpu() : m_registers(26, 0), m_sendTimes(0), m_waiting(false)
		{	
		}

		int64_t& operator[](const size_t index)
		{
			return m_registers[index];
		}

		void send(const size_t index)
		{
			std::unique_lock<std::mutex> lk(m);
			m_toSend.push(m_registers[index]);
			++m_sendTimes;
			lk.unlock();
			cv.notify_one();
		}

		bool available() const
		{
			std::unique_lock<std::mutex> lk(m);
			return !m_toSend.empty();
		}

		int64_t recieve()
		{
			std::unique_lock<std::mutex> lk(m);
			cv.wait(lk, [toSend = &m_toSend] {return !toSend->empty() || terminate; });

			if (terminate)
			{
				return 0;
			}

			const auto temp = m_toSend.front();
			m_toSend.pop();

			lk.unlock();
			cv.notify_one();

			return temp;
		}

		int64_t sendTimes() const
		{
			return m_sendTimes;
		}

		void setWaiting(const bool waiting)
		{
			m_waiting = waiting;
		}


		bool isWaiting() const
		{
			return  m_waiting;
		}

	private:
		std::vector<int64_t> m_registers;
		std::queue<int64_t> m_toSend;
		int64_t m_sendTimes;
		std::atomic<bool> m_waiting;
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
				cpu.setWaiting(true);
				if (otherCpu.isWaiting() && !otherCpu.available() && !cpu.available())
				{
					terminate = true;
					cv.notify_one();
					return;
				}
				const auto temp = otherCpu.recieve();
				if (terminate)
				{
					return;
				}
				cpu[instructions[index][1][0] - 'a'] = temp;
				cpu.setWaiting(false);
			}
			else if (instructions[index][0] == "jgz")
			{
				if (std::isalpha(instructions[index][1][0], loc))
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
				else
				{
					if (std::stoll(instructions[index][1]) > 0)
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

		cpu0['p' - 'a'] = 0;
		cpu1['p' - 'a'] = 1;

		std::thread cpu0Thread(cpuWork, std::ref(instructions), std::ref(cpu0), std::ref(cpu1));
		std::thread cpu1Thread(cpuWork, std::ref(instructions), std::ref(cpu1), std::ref(cpu0));

		cpu0Thread.join();
		cpu1Thread.join();
		
		return cpu1.sendTimes();
	}
}
