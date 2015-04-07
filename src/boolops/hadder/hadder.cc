#include "hadder.h"

HADDER::HADDER()
{
	input1 = input2 = false;
}

void HADDER::set(bool val1, bool val2)
{
	input1 = val1;
	input2 = val2;
}

bool HADDER::getSum()
{
	//XOR myxor = new XOR;

	//bool result = input1 ^ input2;
	sum.set(input1, input2);
	bool result = sum.get();

	return (result);
}

bool HADDER::getCarry()
{
	//AND myand;

	//bool result = input1 & input2;
	carry.set(input1, input2);
	bool result = carry.get();

	return (result);
}
