#include"r6502.h"

void ins0x0A(reg6502& A, reg6502& status)
{
	bool isNonZero = false;

	//status.set(A.getQ(7), CARRY);

	for (int x = 6; x >= 0; x--)
	{
		A.set(A.getQ(x), x + 1);
		//isNonZero = isNonZero | A.getQ(x);
	}
	
	if (isNonZero == true)
		status.set(false, ZERO);
	else
		status.set(true, ZERO);
	
	if (A.getQ(NEGATIVE) == true)
		status.set(true, NEGATIVE);
	else
		status.set(false, NEGATIVE);
	
}	
