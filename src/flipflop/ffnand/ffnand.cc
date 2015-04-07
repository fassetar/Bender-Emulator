#include "ffnand.h"
#include "nand.h"
#include "not.h"

FFNAND::FFNAND()
{
	st = true;
	rset = false;
	q0 = false;
	q1 = true;
}
void FFNAND::reset()
{
        st = false;
	rset = true;
	q0 = true;
	q1 = false; 
}
void FFNAND::setSet(bool inSet)
{
	st = inSet;
	setNAND.set(st,q1);
	q0 = setNAND.get();
	rsetNAND.set(rset,q0);
	q1 = rsetNAND.get();
}
void FFNAND::setRset(bool inReset)
{
	rset = inReset;
	rsetNAND.set(rset,q0);
	q1 = rsetNAND.get();
	setNAND.set(st,q1);
	q0 = setNAND.get();
}
bool FFNAND::getQ0()
{
return(q0);
}
bool FFNAND::getQ1()
{
return(q1);
}
void FFNAND::get(bool& q0out, bool& q1out)
{
	q0out=q0;
	q1out=q1;
}
