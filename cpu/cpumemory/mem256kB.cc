#include "g8sr.h"
#include "mem256kB.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

MEM::MEM()
{
	cout << "Memory set." << endl;
	{	for(int i=0; i<256; i++)
	
		{
			for(int j=0; j<256; j++)
			mem[i][j].reset;
		}

	}

}

int MEM::addGet(G8SR add)
{
	bool hold;
	int val=0;
	for(int i=0; i<8; i++)
	{
		hold=add.getQ(i+1);
		if (hold == true)
			val=val+pow(2, i);
	}
return val;
}

G8SR MEM::getMem(G8SR bitAddr1, G8SR bitAddr2)
{
	int add1, add2;
	add1=addGet(bitAddr1);
	add2=addGet(bitAddr2);
return mem[add1][add2];
}

void MEM::putMem(G8SR bitAddr1, G8SR bitAddr2, G8SR data)
{
	int add1, add2;
	add1=addGet(bitAddr1);
	add2=addGet(bitAddr2);
	mem[add1][add2]=data;
}

void MEM::putMem(int add1, int add2, G8SR data)
{
	mem[add1][add2]=data;
}	

void MEM::memDump()
{
	int count=0;
	bool a, b, c, d, e, f, g, h;
	for (int t=0; t<256; t++)
	{
		for (int y=0; y<256; y++)
		{
//			cout << "t="<<t<<" y="<<y<<;//debugging
			cout << "0x";
			address(t);
			address(y);
			mem[t][y].get(a, b, c, d, f, e, g, h);
			cout << " " << a << b << c << d << e << f << g << h << " ";
			count=count+1;
			if (count==8)
			{
				cout << endl;
				count=0;
			}
		}
	}
}

void MEM::address(int addr)
{
	int temp1, tempA, tempB;
	char cnt1='0';
	char cnt2='0';
	temp1=addr;
	tempA=0;
	tempB=0;
//	cout << "temp1="<<temp1<<;//Debugging
	if ((temp1-128)>=0)
		{	temp1=temp1-128;
			tempA=8;
		}
	if ((temp1-64)>=0)
		{	temp1=temp1-64;
			tempA=tempA+4;
		}
	if ((temp1-32)>=0)
		{	temp1=temp1-32;
			tempA=tempA+2;
		}
	if ((temp1-16)>=0)
		{	temp1=temp1-16;
			tempA=tempA+1;
		}
	if ((temp1-8)>=0)
		{	temp1=temp1-8;
			tempB=8;
		}
	if ((temp1-4)>=0)
		{	temp1=temp1-4;
			tempB=tempB+4;
		}
	if ((temp1-2)>=0)
		{	temp1=temp1-2;
			tempB=tempB+2;
		}
	if (temp1==1)
			tempB=tempB+1;
	if (tempA>=10)
		{	tempA=tempA-10;
			cnt1=65+tempA;
		}
	else cnt1=48+tempA;
	if (tempB>=10)
		{	tempB=tempB-10;
			cnt2=65+tempB;
		}
	else cnt2=48+tempB;
		cout << cnt1 << cnt2;
		
}
