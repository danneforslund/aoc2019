#include <iostream>
#include <algorithm>
#include <fstream>
#include <math.h>
#include <string>
#include <assert.h>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

class Day2 {
public:
	string CalculateIntCode() {		

		//Do a small test
		Test();

		//Read string to run
		ifstream data_stream("data/Day2/intcodes.txt");
		string line;
		if (data_stream) {			
			getline(data_stream, line);
		}
		
		//Part 1
		return RunPart1(line, true, false);
	}

	string FindIntCode(int desiredOutcome) {
		//Read string to run
		ifstream data_stream("data/Day2/intcodes.txt");
		string line;
		if (data_stream) {
			getline(data_stream, line);
		}

		//Part2
		return RunPart2(line, desiredOutcome);
	}

private:	
	void Test() {
		assert(RunPart1("1,0,0,0,99") == "2,0,0,0,99");
		assert(RunPart1("2,3,0,3,99") == "2,3,0,6,99");
		assert(RunPart1("2,4,4,5,99,0") == "2,4,4,5,99,9801");
		assert(RunPart1("1,1,1,4,99,5,6,0,99") == "30,1,1,4,2,5,6,0,99");
		assert(RunPart1("1,9,10,3,2,3,11,0,99,30,40,50") == "3500,9,10,70,2,3,11,0,99,30,40,50");		
	}

	string RunPart1(string codes, bool use1202 = false, bool returnArray = true) {		
		//Read codes to vector
		vector<int> v_codes = SplitArray(codes);		
		if (use1202) {
			v_codes[1] = 12;
			v_codes[2] = 2;
		}		

		vector<int> transformedVector = TransformVector(v_codes);

		if (returnArray)
			return JoinArray(transformedVector);

		stringstream result;
		result << "(Part 1) Position 0 - Answer: " << transformedVector[0];
		return result.str();
	}

	string RunPart2(string codes, int desiredOutcome) {
		vector<int> v_codes = SplitArray(codes);		
		for (int noun = 0; noun <= 99; noun++) {			
			for (int verb = 0; verb <= 99; verb++) {
				vector<int> output(v_codes); //Clone input vector
				output[1] = noun;
				output[2] = verb;				
				if (TransformVector(output)[0] == desiredOutcome) {
					stringstream result;
					result << "(Part 2) Noun: " << noun << ", Verb: " << verb << " - Answer: " << 100 * noun + verb;
					return result.str();
				}
			}
		}
		return "Verb and Noun not found...";
	}
	
	vector<int> TransformVector(vector<int> vector) {
		//Transform vector as defined by the task
		for (std::size_t i = 0; i < vector.size(); i += 4) {
			if ((vector.size() - i) < 4) { //if we're possibly out of bounds, assume it's time to return.
				break;
			}

			int opCode = vector[i];
			int param1 = vector[i+1];
			int param2 = vector[i+2];
			int pos = vector[i+3];

			switch (opCode)
			{
			case 1:
				vector[pos] = (vector[param1] + vector[param2]);
				break;
			case 2:
				vector[pos] = (vector[param1] * vector[param2]);
				break;
			case 99:
				return vector;
			default:
				throw "Invalid opcode";
			}
		}
		return vector;
	}

	string JoinArray(vector<int> vec) {
		stringstream result;
		auto it = vec.begin();
		result << (int)*it++;
		for (; it != vec.end(); it++) {
			result << ",";
			result << (int)*it;
		}
		return result.str();
	}

	vector<int> SplitArray(string arr) {
		vector<int> result;
		stringstream ss(arr);
		for (int i; ss >> i;) {
			result.push_back(i);
			if (ss.peek() == ',')
				ss.ignore();
		}

		return result;
	}
};