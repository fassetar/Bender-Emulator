#include "xor.h"

XOR::XOR()
{
	input1 = input2 = false;
}

void XOR::set()
{
	input1 = input2 = false;
}

void XOR::set(bool value)
{
	input1 = input2 = value;
}

void XOR::set(bool val1, bool val2)
{
	input1 = val1;
	input2 = val2;
}

bool XOR::get()
{
	bool result = false;
	if ((input1 == true && input2 == false) || (input1 == false && input2 == true))
	{
		result = true;
	}

	return (result);
}
