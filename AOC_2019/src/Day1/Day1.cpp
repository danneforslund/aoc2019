#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <assert.h>
using namespace std;

class Day1 {
public:
	uint32_t CalculateFuel() {
		uint32_t total_consumption{};

		//Do a small test
		Test();

		//Read mass data	
		ifstream data_stream("data/Day1/massdata.txt");
		if (data_stream) {
			string line;
			while (getline(data_stream, line))
			{
				uint32_t module_mass = stoi(line);
				total_consumption += GetModuleFuel(module_mass);
			}
		}

		return total_consumption;
	}
private:
	uint32_t GetModuleFuel(uint32_t module_mass) {
		return floor(module_mass / 3) - 2;
	}

	void Test() {
		assert(GetModuleFuel(12) == 2);
		assert(GetModuleFuel(14) == 2);
		assert(GetModuleFuel(1969) == 654);
		assert(GetModuleFuel(100756) == 33583);
	}
};