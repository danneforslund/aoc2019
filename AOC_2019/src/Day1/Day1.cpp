#include <iostream>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <string>
#include <assert.h>
using namespace std;

class Day1 {
public:
	int CalculateFuel(bool includeOwnMass = false) {
		int total_consumption{};

		//Do a small test
		Test(includeOwnMass);

		//Read mass data	
		ifstream data_stream("data/Day1/massdata.txt");
		if (data_stream) {
			string line;
			while (getline(data_stream, line))
			{
				int module_mass = stoi(line);
				total_consumption += GetModuleFuel(module_mass, includeOwnMass);
			}
		}

		return total_consumption;
	}

private:
	int GetModuleFuel(int module_mass, bool includeOwnMass = false) {
		int module_fuel = (int)(floor(module_mass / 3) - 2);
		if (!includeOwnMass)
			return max(module_fuel, 0);

		int total_module_fuel{};

		int fuel_left = module_fuel; //Start with module fuel
		if (fuel_left > 0) {
			int module_fuel = GetModuleFuel(fuel_left, includeOwnMass);
			total_module_fuel += max(module_fuel, 0); //Only positive values
			fuel_left -= module_fuel;
		}

		return module_fuel + total_module_fuel;
	}

	void Test(bool includeOwnMass = false) {
		if (!includeOwnMass) {
			assert(GetModuleFuel(12) == 2);
			assert(GetModuleFuel(14) == 2);
			assert(GetModuleFuel(1969) == 654);
			assert(GetModuleFuel(100756) == 33583);
		}
		else {
			assert(GetModuleFuel(14, true) == 2);
			assert(GetModuleFuel(1969, true) == 966);
		}
	}
};