#include <iostream>
#include "src/Day1/Day1.cpp"
using namespace std;

int main()
{
	/* Calculate fuel required */
	Day1 day1;
	int fuel = day1.CalculateFuel();
	cout << "Fuel required: " << fuel << endl;
	 	
	int fuelWithOwnMass = day1.CalculateFuel(true); 
	cout << "Fuel required including own mass: " << fuelWithOwnMass << endl;

}
