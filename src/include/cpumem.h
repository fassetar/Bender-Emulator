#ifndef _CPUMEM_H
#define _CPUMEM_H

class CPUMEM
{
	public:
		CPUMEM();
		unsigned char& operator[](unsigned short int address);
		unsigned char read(unsigned short int address);
		void write(unsigned short int address, unsigned char value);
		~CPUMEM();
	private:
		//unsigned short int memlngth;
		unsigned char *memadd;
};
#endif
