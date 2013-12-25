#include "ffxnor.h"
#include "xnor.h"

FFXNOR::FFXNOR()
{
	s=r=q=q1=false;
}

void FFXNOR::reset()
{
	s=r=q=q1=false;
}

void FFXNOR::setS(bool inS)
{
	s=inS;
	//s = XNOR.set(s,q);
	//q1 = s = XNOR.get();
	//r = XNOR.set(r,q1);
	// q= rXNOR.get();
}

void FFXNOR::setR(bool inR)
{
	//r=inR;
	//rXNOR.set(r,q1);
	//q=rXNOR.get();
	//sXNOR.set(s,q);
	//q1=sXNOR.get();
}

bool FFXNOR::getQ()
{
return(q);
}

bool FFXNOR::getQ1()
{
return(q1);
}

void FFXNOR::get(bool qOut, bool q1Out)
{
	qOut=q;
	q1Out=q1;
}
