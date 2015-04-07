#include"nand.h"

NAND::NAND()
{
	input1 = false;
	input2 = false;
}

void NAND::set(bool value)
{
	input1 = input2 = value;
}

void NAND::set(bool value1, bool value2)
{
	input1 = value1;
	input2 = value2;
}

bool NAND::get()
{
	bool andResult, notResult;

	myAndGate.set(input1, input2);
	andResult = myAndGate.get();
	myNotGate.set(andResult);
	notResult = myNotGate.get();

	return (notResult);
}
