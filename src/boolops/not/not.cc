#include"not.h"

NOT::NOT()
{
	input = false;
}

void NOT::set(bool value)
{
	input = value;
}

bool NOT::get()
{
	bool result = false;

	if (input == true)
	{
		result = false;
	}
	else
	{
		result = true;
	}

	return (result);
}
