#include <iostream>
#include <string>
#include <map>
using namespace std;

int decompress(string formula)
{
	// Store masses of elements
	map<char, int> masses;
	masses.insert(pair<char, int>('C', 12));
	masses.insert(pair<char, int>('H', 1));
	masses.insert(pair<char, int>('O', 16));

	// initialize summed mass to 0
	int mass = 0;
	
	// iterate through every character in formula
	for (int i = 0; i < formula.length(); i++)
	{
		// If the charactter is not ( then it is number or atom
		if (formula.at(i) != '(') 
		{
			// add the atom mass to the general mass
			mass += masses[formula.at(i)];

			// if it is number(n) then add mass of the previous atom n-1 times again
			if (formula.at(i) >= '0' && formula.at(i) <= '9')
			{
				int mult = formula.at(i) - '0';
				mult -= 1;
				mass += masses[formula.at(i-1)] * mult;
			}
			
			// rest of the loop is for calculating subformulas
			continue;
		}
		

		int start = i;
		int end = start;
		int unpaired = 1;
		bool eof = false;

		while (unpaired > 0) // Find closing bracket
		{		
			end++;
			
			if (formula.at(end) == '(')
			{
				unpaired++;
			}
			else if (formula.at(end) == ')')
			{
				unpaired--;
			}
		}

		// avoid trying finding multiplier if end pointer points end of the formula
		if (end >= formula.length() - 1)
		{
			end = formula.length() - 1;
			eof = true;
		}

		// check if the group was multiplied
		int times = 1;
		if (!eof && formula.at(end+1) >= '0' && formula.at(end+1) <= '9')
		{
			times = formula.at(end + 1) - '0';
		}
		
		
		// calculate mass of subformula
		int mass_of_decompressed_part = decompress(formula.substr(start + 1, end - start-1));

		// add mas of the subformula to the general mass
		mass += mass_of_decompressed_part * times;

		// skip calculating mass of current subformula again
		if (times == 1)
		{
			i = end;
		}
		else
		{
			i = end + 1;
		}
	}
	return mass;
}


int main()
{
	string str;
	cin >> str;

	cout << decompress(str);

	return 0;
}