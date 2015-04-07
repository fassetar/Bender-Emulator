#include "ffnor.h"
#include "nor.h"
#include "not.h"

FFNOR::FFNOR()
{
	s=r=q=q1=false;
}

void FFNOR::reset()
{
	s=r=q=q1=false;
}

void FFNOR::setS(bool inS)
{
	NOT gate;
	s=inS;
	gate.set(s);
	r=gate.get();
	sNOR.set(s,q);
	q1=sNOR.get();
	rNOR.set(r,q1);
	q=rNOR.get();
}

void FFNOR::setR(bool inR)
{
	NOT gate;
	r=inR;
	gate.set(r);
	s=gate.get();
	rNOR.set(r,q1);
	q=rNOR.get();
	sNOR.set(s,q);
	q1=sNOR.get();
}

bool FFNOR::getQ()
{
return(q);
}

bool FFNOR::getQ1()
{
return(q1);
}

void FFNOR::get(bool& qOut, bool& q1Out)
{
	qOut=q;
	q1Out=q1;
}
