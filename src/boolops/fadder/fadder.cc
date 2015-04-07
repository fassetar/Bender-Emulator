#include "hadder.h" 
#include "fadder.h"
#include "or.h" 

FADDER::FADDER() 
{
	sOut = cOut = false;
} 

void FADDER::set(bool inputA, bool inputB, bool inputC) 
{	
	bool s1;
	bool c1, c2;
	ab.set(inputA, inputB);
	s1=ab.getSum();
	sc.set(s1, inputC);
	c1=ab.getCarry();
	c2=sc.getCarry();
	cAdd.set(c1, c2);
	sOut=sc.getSum();
	cOut=cAdd.get();
}	

bool FADDER::getSum() 
{ 
return (sOut);
}

bool FADDER::getCarry() 
{
return (cOut);
}
