#include <iostream>
#include <iomanip>
#include "nor.h"

using namespace std;

int main()
{
	bool a, b, r;
	NOR gate;
	a=b=false;

	cout <<setfill('-')<<setw(19)<<""<<endl;
	cout <<"| Input | Output  |"<<endl;
	cout <<"|"<<setw(4)<<"+"<<setw(4)<<"+"<<setw(10)<<"|"<<endl;
	cout <<"| A | B | A NOR B |"<<endl;
	cout <<"|---+---+---------|"<<endl;
	for (int i=0; i<2; i++)
	{
		gate.seta(i);
		for (int j=0; j<2; j++)
		{
			gate.setb(j);
			r=gate.get();
			cout<<"| "<<i<<" | "<<j<<" |    "<<r<<"    |"<<endl;
		}
	}
	cout <<setw(19)<<""<<endl;
	return(0);
}
