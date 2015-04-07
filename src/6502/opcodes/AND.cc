#include"r6502.h"
#include"globalreg6502.h"
#include"fadder.h"
#include"memory.h"

//6502 instruction 0x29 AND With Accumulator - Immediate
//AND - And with Accumulator - Flags Affected: N Z
void ins0x29(int address)
{
	bool isNonZero = false;
//	bool immediate[8];
	
	for (int x = 0; x < 8; x++)
	{
		accum.set(accum.getQ(x) & mem.read(address), x);
		isNonZero = isNonZero | accum.getQ(x);
	}

	if (isNonZero == false)
		status.set(true, ZERO);
	else 
		status.set(false, ZERO);
	
	if (accum.getQ(NEGATIVE) == true)
		status.set(true, NEGATIVE);
	else
		status.set(false, NEGATIVE);

}
