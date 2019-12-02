#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <assert.h>

#include "Day1.h"

using namespace std;

uint32_t Day1_CalculateFuel() {
	uint32_t total_consumption{};

	//Do a small test
	Day1_Test();

	//Read mass data	
	ifstream data_stream("data/Day1/massdata.txt");
	if (data_stream) {
		string line;
		while (getline(data_stream, line))
		{
			uint32_t module_mass = stoi(line);
			total_consumption += Day1_GetModuleFuel(module_mass);
		}
	}

	return total_consumption;
}

uint32_t Day1_GetModuleFuel(uint32_t module_mass) {
	return floor(module_mass / 3) - 2;
}

void Day1_Test() {
	assert(Day1_GetModuleFuel(12) == 2);
	assert(Day1_GetModuleFuel(14) == 2);
	assert(Day1_GetModuleFuel(1969) == 654);
	assert(Day1_GetModuleFuel(100756) == 33583);
}