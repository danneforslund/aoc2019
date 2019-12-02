#include <iostream>
#include "src/Day1/Day1.cpp"
using namespace std;

int main()
{
	/* Calculate fuel required */
	Day1 day1;
	uint32_t fuel = day1.CalculateFuel();
	cout << "Fuel required: " << fuel;
}
