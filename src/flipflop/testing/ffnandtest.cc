#include <iostream>
#include "nand.h"
#include "ffnand.h"
#include <iomanip>
using namespace std;
int main()
{
	bool q0,q1,rset,set;
	FFNAND flop;
	flop.reset();
	
	cout << "|Input|Output|" << endl;
	//cout << "|" <<setw(2) << "+" << setw(2) << "|" << setw(2) << "+" << setw() <<endl;
	cout << "|S |R |Q0|Q1|" << endl;
	cout << "|--|--|--|--|" << endl;
	//cout << "| - | - | 00 |00|" << endl;
		
		for(int i = 0; i < 2; i++)
		{
			for(int j = 0; j < 2; j++)
			{
				if( i!= 0 || j!= 0 )
				{
					flop.setSet(i);
					flop.setRset(j);
					flop.get(q0,rset);
				//	flop.get(q1,set);
					cout << "| " << i << "| " <<j<< "| " <<q0<<  "| " << q1 <<"|"<< endl; 
				}
				else
				{
					flop.setSet(0);
					flop.setRset(0);
					flop.get(q1,set);
					cout << "| 0| 0| " <<q1<< "| " <<set<<"|"<<endl;
				}
			}
		}
return(0);
}
