//ORA - Bitwise Or with the Accumulator
#include"r6502.h"
#include"globalreg6502.h"
#include"memory.h"
#include"or.h"

void ins0x09(reg6502 value) //ORA Immediate
{
	//Sets ZERO flag to true. If a nonzero value
	//is found, which it most likely will, it will
	//get changed later.
	status.set(true, ZERO);

	//Or the contents of the accumulator with the
	//immediate value and store that back into the
	//accumulator.
	for (int i = 1; i < 9; i++)
		accum.set(accum.getQ(i) | value.getQ(i), i);

	//Check the NEGATIVE bit in the accumulator and if
	//it's true set the NEGATIVE flag in the status
	//register. Otherwise set it to false.
	if (accum.getQ(NEGATIVE) == true)
		status.set(true, NEGATIVE);
	else
		status.set(false, NEGATIVE);

	//Check each bit in the accumulator for a value
	//of 1. If 1 is found, reset the ZERO flag to false
	//and set i to 9, jumping out of the for loop.
	for (int i = 1; i < 9; i++)
	{
		if (accum.getQ(i) == true)
		{
			status.set(false, ZERO);
			i = 9;
		}
	}
}

void in0x05(int address) //ORA Zero Page
{
	status.set(true, ZERO);
	
	for (int i = 1; i < 9; i++)
		accum.set(accum.getQ(i) | mem.read(address).getQ(i), i);

	if (accum.getQ(NEGATIVE) == true)
		status.set(true, NEGATIVE);
	else
		status.set(false, NEGATIVE);

	for (int i = 1; i < 9; i++)
	{
		if (accum.getQ(i) == true)
		{
			status.set(false, ZERO);
			i = 9;
		}
	}
}
