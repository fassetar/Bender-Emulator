#include "ffnor.h"
#include "g8sr.h"
#include "nor.h"
#include "and.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	G8SR byte;
	bool inS[8];
	bool inR[8];
	bool qr[8];
	bool q1r[8];
	bool s;
	bool r;
	bool b1,b2,b3,b4,b5,b6,b7,b8;
	s=true;
	r=false;
	for (int x=0; x<8; x++)
	{
		inS[x]=false;
		inR[x]=false;
	}
	byte.get(b1, b2, b3, b4, b5, b6, b7, b8);
	cout << "Byte status:" << b1 << b2 << b3 << b4 << b5 << b6 << b7 << b8 << endl;
	for (int i=0; i<8; i=i+2)
	{
		byte.set(s, (i+1));
		inS[i]=s;
	}
	cout << "Byte Set input:";
	for (int i=0; i<8; i++)
	{
		cout << inS[i];
	}
	byte.get(b1, b2, b3, b4, b5, b6, b7, b8);
	cout << endl << "Byte status:" << b1 << b2 << b3 << b4 << b5 << b6 << b7 << b8 << endl;
	byte.clockTick();
	cout << "After Clock Tick:" << endl << "Q:";
	for (int i=0; i<8; i++)
	{
		qr[i]=byte.getQ((i+1));
		q1r[i]=byte.getQ1((i+1));
		cout << qr[(i)];
	}
	cout << endl << "Not Q:";
	for (int i=0; i<8; i++)
	{
		cout << q1r[i];
		inR[i]=s;
		inS[i]=r;
	}
	cout << endl << "2." << endl << "Reset Input:";
	for (int x=0; x<8; x=x+2)
	{
		byte.set(r, (x+1));
		inR[x]=r;
	}
	for (int x=1; x<8; x=x+2)
	{
		byte.set(s, (x+1));
		inS[x]=s;
		
	}
	for (int i=0; i<8; i++)
	{
		cout << inR[i];
	}
	cout << endl << "Set Input:";
	for (int i=0; i<8; i++)
	{
		cout << inS[i];
	}
	cout << endl << "Byte status:";
	byte.get(b1, b2, b3, b4, b5, b6, b7, b8);
	cout << b1 << b2 << b3 << b4 << b5 << b6 << b7 << b8 << endl << "After Clock Tick:";
	byte.clockTick();
	byte.get(b1, b2, b3, b4, b5, b6, b7, b8);
	cout << b1 << b2 << b3 << b4 << b5 << b6 << b7 << b8 << endl << "Q:";
	for (int i=0; i<8; i++)
	{
		qr[i]=byte.getQ((i+1));
		q1r[i]=byte.getQ1((i+1));
		cout << qr[i];
	}
	cout << endl << "Q1:";
	for (int x=0; x<8; x++)
	{
		cout << q1r[x];
	}
	cout << endl << endl;
return (0);
}
