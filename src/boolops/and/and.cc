#include "and.h"

AND::AND()
{
	input2 = input2 = false;
}

void AND::reset()
{
	input1 = input2 = false;
}

void AND::set(bool value)
{
	input1 = input2 = value;
}

void AND::set(bool val1, bool val2)
{
	input1 = val1;
	input2 = val2;
}

bool AND::get()
{
	bool result = false;
	if ((input1 == true) && (input2 == true))
	{
		result = true;
	}

	return (result);
}
