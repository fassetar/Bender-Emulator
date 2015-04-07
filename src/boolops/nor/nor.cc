#include "nor.h"


NOR::NOR()
{
	a=b=false;
return;
}

void NOR::reset()
{
	a=b=false;
}

void NOR::seta(bool aIn)
{
	a=aIn;
return;
}

void NOR::setb(bool bIn)
{
	b=bIn;
return;
}

void NOR::set(bool aIn, bool bIn)
{
	a=aIn;
	b=bIn;
return;
}

bool NOR::get()
{
	bool result=false;
	if (a==false)
	{
		if(b==false)
			result=true;
	}
return (result);
}

