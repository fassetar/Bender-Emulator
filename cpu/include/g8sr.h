#ifndef _G8SR_H
#define _G8SR_H
#include "ffnor.h"
#include "and.h"

//Clock times flip flop S/R Latch in byte size groups per object.  Individual bit setting and getting allowed in a range of 1-8.  Will not allow a 1-1 submission to the gates.  use reset function to clear and reset all states to 0.
class G8SR
{
	private:
		bool s[8];
		bool q[8];
		bool q1[8];
		bool tock;
		FFNOR flip[8];
		void tick();
	public:
		G8SR();
		void reset();
		void set(bool s, int bit);
		void clockTick();
		void get(bool& bit1, bool& bit2, bool& bit3, bool& bit4, bool& bit5, bool& bit6, bool& bit7, bool& bit8);
		bool getQ(int bit);
		bool getQ1(int bit);
};
#endif
