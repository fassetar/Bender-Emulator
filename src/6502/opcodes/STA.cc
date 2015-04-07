#include"r6502.h"
#include"memory.h"
#include"globalreg6502.h"
#include"fadder.h"

void ins0x85(int address) //Zero Page
{
	//pulls each bit from the accumulator
	//and stores that into memory
	mem.write(address, accum);
}

void ins0x8D(int address) //Absolute
{
	//Pulls each bit from the accumulator
	//and stores that into memory
	mem.write(address, accum);
}

void ins0x95(int address) //Zero Page, X
{
	FADDER f;
	bool c = 0;

	//Adds the contents of the memory address with the contents
	//of the x register and stores that into the accumulator
	for (int i = 1; i < 9; i++)
	{
		f.set(mem.read(address).getQ(i), indexx.getQ(i), c);
		accum.set(f.getSum(), i);
		c = f.getCarry();
	}
}

void ins0x9D(int address) //Absolute, X
{
	FADDER f;
	bool c = 0;
	
	//Adds the contents of the memory address with the contents
	//of the x register and stores that into the accumulator

	for (int i = 1; i < 9; i++)
	{
		f.set(mem.read(address).getQ(i), indexx.getQ(i), c);
		accum.set(f.getSum(), i);
		c = f.getCarry();
	}
}

void ins0x99(int address) //Absolute, y
{
	FADDER f;
	bool c = 0;

	//Adds the contents of the memory address with the contents
	//of the y register and stores that into the accumulator

	for (int i = 1; i < 9; i++)
	{
		f.set(mem.read(address).getQ(i), indexy.getQ(i), c);
		accum.set(f.getSum(), i);
		c = f.getCarry();
	}
}

