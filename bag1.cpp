// FILE: bag1.cpp
// From Chapter 3 of Data Structures and Other Objects (Second Edition)
// ________________________________________________________________________
//
// This file has been modified to work with Microsoft Visual C++ 6.0,
// as described in www.cs.colorado.edu/~main/vc6.html
// ________________________________________________________________________
//
// CLASS IMPLEMENTED: bag (see bag1.h for documentation)
// INVARIANT for the bag class:
//   1. The number of items in the bag is in the member variable used;
//   2. For an empty bag, we do not care what is stored in any of data; for a
//      non-empty bag the items in the bag are stored in data[0] through
//      data[used-1], and we don't care what's in the rest of data.
#include <iostream>
#include <algorithm> // Provides copy function
#include <cassert>   // Provides assert function
#include <fstream>
#include <sstream>
#include <string>
#include "bag1.h"
using namespace std;

namespace main_savitch_3
{
	// (Omitted for VC++ 6.0) const bag::size_type bag::CAPACITY;

	bag::size_type bag::erase(const value_type& target)
	{
		size_type index = 0;
		size_type many_removed = 0;

		while (index < used)
		{
			if (data[index] == target)
			{
				--used;
				data[index] = data[used];
				++many_removed;
			}
			else
				++index;
		}

		return many_removed;
	}

	bool bag::erase_one(const value_type& target)
	{
		size_type index; // The location of target in the data array    

		// First, set index to the location of target in the data array,
		// which could be as small as 0 or as large as used-1. If target is not
		// in the array, then index will be set equal to used.
		index = 0;
		while ((index < used) && (data[index] != target))
			++index;

		if (index == used)
			return false; // target isn’t in the bag, so no work to do.

		// When execution reaches here, target is in the bag at data[index].
		// So, reduce used by 1 and copy the last item onto data[index].
		--used;
		data[index] = data[used];
		return true;
	}

	void bag::insert(const value_type& entry)
		// Library facilities used: cassert
	{
		assert(size() < CAPACITY);

		data[used] = entry;
		++used;
	}

	void bag::operator +=(const bag& addend)
		// Library facilities used: algorithm, cassert
	{
		assert(size() + addend.size() <= CAPACITY);

		copy(addend.data, addend.data + addend.used, data + used);
		used += addend.used;
	}

	bag::size_type bag::count(const value_type& target) const
	{
		size_type answer;
		size_type i;

		answer = 0;
		for (i = 0; i < used; ++i)
			if (target == data[i])
				++answer;
		return answer;
	}

	bag operator +(const bag& b1, const bag& b2)
		// Library facilities used: cassert
	{
		bag answer;

		assert(b1.size() + b2.size() <= bag::CAPACITY);

		answer += b1;
		answer += b2;
		return answer;
	}

	void Set::readFile(std::fstream & file)
	{
		std::string string1;				//will hold the first set of intergers
		std::string string2;				//will hold the second set of intergers

		while (!file.eof())
		{
			getline(file, string1);				//set 1 of intergers
			file.ignore();
			getline(file, string2);				//set 2 of intergers 
		}
		std::stringstream Set1;
		std::stringstream Set2;

		Set1 >> string1;					//will place string 1 in set1 
		Set2 >> string2;					//will place string 2 in set2

		for (int i = 0; i < CAPACITY; i++)
		{
			Set1 >> set1[i];				//will copy the buffer from Set1 and will place each interger into array of set1 from class set
			Set2 >> set2[i];				//will copy the buffer from Set2 and will place each interger into array of set2 from class set

		}
		//checks if theres intergers in the set1 array

		for (int i = 0; i < CAPACITY; i++)
		{
			int number1;						//holds the value of the i index for set2
			int number2;						//hold the value of the i index for set1
			number1 = set1[i];
			number2 = set2[i];
			if (!isdigit(number1))				//if the variable number 1 is not a int in a iteration it will exit the program
			{
				std::cout << "Not a int value in set1 Exitting program" << std::endl;
				exit(1);						//will terminate the program
			}
			else if (!isdigit(number2))			//if the variable number 2 is not a int in a iteration it will exit the program
			{
				std::cout << "Not a int value in set2 Exitting program" << std::endl;
				exit(1);						//will terminate the program
			}
			else
				std::cout << "All numbers read in were int types both sets are good to go" << std::endl;

		}
		file.close();							//closes the input file
	}


	void Set::operator+(const value_type & target)
	{
		for (int j = 0; j < CAPACITY; j++)
		{
			for (int i = 0; i < CAPACITY; i++)
			{
				int number1;
				int number2;
				number1 = set1[j];
				number2 = set2[i];
				//if number 1 is equal to number 2
				//index i for set 2 will be overwritten by the next elements shifting it to the left
				if (number2 == number1)
				{
					set2[i] = set2[i + 1];
				}
				i--;
			}
		}
		//after all the iterations from deleting duplicates the set2 array will be added to set1 array
		int numElem = sizeof(set1);					//determines the size of the array 
		for (int i = numElem; i < CAPACITY; i++)
		{
			int j = 0;
			int number1;							//will temp hold the values for set2 to transfer over to set1 array
			number1 = set2[j];
			set1[i] = number1;
			j++;
		}

	}

}