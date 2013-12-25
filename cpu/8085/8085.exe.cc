#include <iostream>
#include <fstream>
#include <string>
#include "terp.h"

using namespace std;

int main()
{
	string progName;
	TERP i8085;
	cout << endl << endl << "Enter name of file for simulator execuation:";
	cin >> progName;
	i8085.run(progName);
return 0;
}	
