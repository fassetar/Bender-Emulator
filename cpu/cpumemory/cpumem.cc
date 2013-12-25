#include "cpumem.h"

CPUMEM::CPUMEM()
{
        memadd = new unsigned char[65536];
}

CPUMEM::~CPUMEM()
{
	delete[] memadd;
}

unsigned char& CPUMEM::operator[](unsigned short int address)
{
	return memadd[address];
}

unsigned char CPUMEM::read(unsigned short int address)
{
	return *(memadd + address);
}

void CPUMEM::write(unsigned short int address, unsigned char value)
{
	*(memadd + address) = value;
}
