#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <assert.h>

#include "Day1.h"

std::uint32_t Day1_CalculateFuel() {
	std::uint32_t total_consumption{};

	//Do a small test
	Day1_Test();

	//Read mass data
	std::string file_path("data/Day1/massdata.txt");
	std::ifstream data_stream(file_path);
	if (data_stream) {
		std::string line;
		while (getline(data_stream, line))
		{
			std::uint32_t module_mass = std::stoi(line);
			total_consumption += Day1_GetModuleFuel(module_mass);
		}
	}

	return total_consumption;
}

std::uint32_t Day1_GetModuleFuel(std::uint32_t module_mass) {
	return floor(module_mass / 3) - 2;
}

void Day1_Test() {
	assert(Day1_GetModuleFuel(12) == 2);
	assert(Day1_GetModuleFuel(14) == 2);
	assert(Day1_GetModuleFuel(1969) == 654);
	assert(Day1_GetModuleFuel(100756) == 33583);
}