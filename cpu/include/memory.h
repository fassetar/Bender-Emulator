#ifndef _memory
#define _memory

#include"r6502.h"

class memory
{
   public
		reg6502 mem[655536];
		memory();
		void write(int, reg6502);
		reg6502 read(int);
		void dump();
};

#endif

