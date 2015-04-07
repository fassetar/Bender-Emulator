#include<iostream>
#include<iomanip>
#include "hadder.h"
#include "fadder.h"

using namespace std;

int main()
{
	FADDER test;
	bool t=true;
	bool f=false;
	bool a, b, cIn, s, cOut;

	for (int i=0; i<2; i++)
	{
		if (i==0)
			cIn=f;
		else cIn=t;
		for (int j=0; j<2; j++)
		{
			if (j==0)
				b=f;
			else b=t;
			for (int k=0; k<2; k++)
			{
				if (k==0)
					a=f;
				else a=t;
				cout << a << " " << b << " " << cIn << " ";
				test.set(a, b, cIn);
				s=test.getSum();
				cOut=test.getCarry();
				cout << s << " " << cOut << endl;
			}
		}
	}
return(0);
}
