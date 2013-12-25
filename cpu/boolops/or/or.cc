#include "or.h"

OR::OR()
{
	input1 = input2 = false;
}

void OR::set()
{
	input1 = input2 = false;
}

void OR::set(bool value)
{
	input1 = input2 = value;
}

void OR::set(bool val1, bool val2)
{
	input1 = val1;
	input2 = val2;
}

bool OR::get()
{
	bool result = false;
	if ((input1 == true) || (input2 == true))
	{
		result = true;
	}

	return (result);
}
