#ifndef _HADDER_H
#define _HADDER_H

#include "xor.h"
#include "and.h"

class HADDER 
{
	public:
	 	HADDER();

	 	void set(bool, bool);
	 	bool getSum();
		bool getCarry();
		
	private:
		bool input1;
		bool input2;
		XOR sum;
		AND carry;
};

#endif
