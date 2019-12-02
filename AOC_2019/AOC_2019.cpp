#include <iostream>
#include "src/Day1/Day1.cpp"
#include "src/Day2/Day2.cpp"
using namespace std;

void RunDay1() {
	/* Calculate fuel required */
	Day1 day1;
	int fuel = day1.CalculateFuel();
	cout << "Fuel required: " << fuel << endl;

	int fuelWithOwnMass = day1.CalculateFuel(true);
	cout << "Fuel required including own mass: " << fuelWithOwnMass << endl;
}

void RunDay2() {
	Day2 day2;
	string finalString = day2.CalculateIntCode();
	cout << finalString << endl;

	string nounVerb = day2.FindIntCode(19690720);
	cout << nounVerb << endl; 
}


int main()
{
	RunDay2(); 
}
