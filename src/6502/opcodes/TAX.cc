#include"r6502.h"
#include"gloablreg6502.h"
//Transfer the Accumulator to the X Register

void ins0xAA()
{
	bool isNonZero = false;

	//Copy Accumulator to the X Register
	for (int x = 1; x < 9; x++)
		indexX.set(accum.getQ(x), x);
	
	//Set Negative flag if necessary
	if (indexX.getQ(NEGATIVE) == true)
		status.set(true, NEGATIVE);
	
	//Set Zero flag if necessary
	for (int x = 1; x < 8; x++)
		isNonZero = indexX.getQ(x) & indexX.getQ(x + 1);
}
