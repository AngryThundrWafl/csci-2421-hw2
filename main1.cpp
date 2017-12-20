#include "bag1.h"
#include <fstream>
#include <iostream>
using namespace std;


namespace main_savitch_3
{
	Set s;
	//opens a fstream object called inut File and wil open input.dat
	std::fstream inputFile;
	inputFile.open("input.dat");
	//error message and terminates if input file not found 
	if (!inputFile.fail())
	{
		cout << "Could not open File" << endl;
		exit(1);
	}
	//continues here if theres no errors
	s.readFile(inputFile);					//will read in data from input file that will be passed as a parameter
	s.operator+();

	return 0;
}
