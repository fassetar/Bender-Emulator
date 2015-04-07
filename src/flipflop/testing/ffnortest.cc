#include <iostream>
#include <iomanip>
#include "nor.h"
#include "ffnor.h"

using namespace std;

int main()
{
	bool q,r;
	FFNOR flop;
	flop.reset();
	int h = 1;
	cout <<setfill('-')<<setw(19)<<""<<endl;
	cout <<"| Input | Output  |"<<endl;
	cout <<"|"<<setw(4)<<"+"<<setw(4)<<"+"<<setw(10)<<"|"<<endl;
	cout <<"| S | R | Q  | Q1 |"<<endl;
	cout <<"|---+---+----+----|"<<endl;
	cout <<"| - | - | 0  | 0  |"<<endl;
		flop.setS(h);
		flop.get(q,r);
		cout<<"| "<<h<<" | 0 | "<<q<<"  | "<<r<<"  |"<<endl;
		for (int i=0; i<2; i++)
		{
			for (int j=0; j<2; j++)
			{
				if (i!=1 || j!=0)
				{
					flop.setS(i);
					flop.setR(j);
					flop.get(q,r);
					cout<<"| "<<i<<" | "<<j<<" | "<<q<<"  | "<<r<<"  |"<<endl;
				} else
				{
					flop.setS(0);
					flop.setR(0);
					flop.get(q,r);
					cout<<"| 0 | 0 | "<<q<<"  | "<<r<<"  |"<<endl;
				}
			}
			
		}
	cout <<setw(19)<<""<<endl;
	return(0);
}
