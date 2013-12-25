#include"r6502.h"
#include<cstdio>

memory::memory()
{
	//For loop that initializes every bit in the 64Kb of memory to 0.
	for (int address = 0; address < 65536; address++)
	{
		for (int bit = 1; bit < 9; bit++)
			mem[address].set(0, bit);
	}
}

void memory::write(int address, reg6502 value)
{
	//For loop that sets the values in a certain memory address
	//to the values of a reg6502 object
	for (bit = 1; bit < 9; bit++)
		mem[address].set(value.getQ(bit), bit);
}

reg6502 memory::read(int address)
{
	//Returns the reg6502 object at a certain memory address passed
	//as a parameter.

	//Note: I'm fairly certain this won't work but it's a start.
	//I'm thinking of trying to create a temp reg6502 object, 
	//set the two equal to each other and return the tempory
	//object.
	return mem[address];
}

void memory::dump()
{
	//Outer loop cycles through each address in memory as
	//the second address prints out each bit stored at that
	//address.
	for (int address = 0; address < 65536; address++)
	{
		for (int bit = 1; bit < 9; bit++)
			printf("%d", mem[address].getQ(bit));

		printf("\n");
	}
}
