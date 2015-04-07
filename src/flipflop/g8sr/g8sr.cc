#include "g8sr.h"
#include "ffnor.h"
#include "and.h"
#include "nor.h"
#include "not.h"

//Byte worth of clock timed SR Latches.  holds intended input to SR Latch untill a clock tick occurs.  Individual and full byte output available in overloaded get commands for Q and Not Q.  Bit values for setR, setS, getQ, and getQ1 are based on a 1-8 value.

G8SR::G8SR()
{
	for (int i=0; i<=7; i++)
	{
		s[i]=false;
		q[i]=false;
		q1[i]=false;
	}
}

void G8SR::reset()
{
	for (int i=0; i<=7; i++)
	{
		s[i]=false;
		q[i]=false;
		q1[i]=false;
	}
}

void G8SR::set(bool inS, int bit)
{
	NOT in;
	in.set(inS);
	s[(bit-1)]=inS;
}

void G8SR::clockTick()
{
	tock=true;
	tick();
	tock=false;
}

void G8SR::get(bool& bit1, bool& bit2, bool& bit3, bool& bit4, bool& bit5, bool& bit6, bool& bit7, bool& bit8)
{
//assigns/returns recursively only the q values for useage.
	bit1=q[0];
	bit2=q[1];
	bit3=q[2];
	bit4=q[3];
	bit5=q[4];
	bit6=q[5];
	bit7=q[6];
	bit8=q[7];
}

bool G8SR::getQ(int bit)
{
return(q[(bit-1)]);
}

bool G8SR::getQ1(int bit)
{
return(q1[(bit-1)]);
}

void G8SR::tick()
{
	bool and1out, and2out;
	AND and1;
	AND and2;
	NOT in;
	bool r;
	for (int i=0; i<=7; i++)
	{
		in.set(s[i]);
		r=in.get();
		and1.set(r, tock);
		and2.set(s[i], tock);
		and1out=and1.get();
		and2out=and2.get();
		flip[i].setR(and1out);
		flip[i].setS(and2out);
	}
	for (int j=0; j<=7; j++)
	{
		flip[j].get(q[j], q1[j]);
	}
}
