#include "stdafx.h"
#include "iostream" //required for console commands
#include "cstdlib" //required for generating random numbers
#include "ctime" //required to seed the random number with time

using namespace std;

int main()
{
	srand(time(0)); //seeding the random number generator

	int number = rand() % 64 + 1; //random number between 1 and 64
	int high = 64; //highest possible position 
	int low = 1; //lowest possible position
	int location = number; //variable for enemy location
	int search; //variable for what is being searched
	int count = 0; //variable for number of searches
	bool found = false; //variable for determining whether or not enemy was found

	cout << "Welcome to Skynet HK Aerial.\n";
	cout << "Prepare Search for Target.\n\n";

	while (found == false)
	{
		int search = ((high - low) / 2) + low;
		count = count + 1;
		if (search > location)
		{
			high = search - 1;
			cout << "==============================================================\n";
			cout << "Target not found at " << search << ", initiating sonar ping\n";
			cout << "Moving to new location\n\n";
		}
		else if (search < location)
		{
			low = search + 1;
			cout << "==============================================================\n";
			cout << "Target not found at " << search << ", initiating sonar ping\n";
			cout << "Moving to new location\n\n";
		}
		else if (search == location)
		{
			cout << "==============================================================\n";
			cout << "Target Located at " << location << ".  " << count << " units were searched.\n\n";
			found = true;
		}
		else
		{
			cout << "Critical error!\n";
			cout << "Recover drone for diagnostics.\n\n";
			found = true;
		}
	}
	system("pause");
	return 0;
}