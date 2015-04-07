#include "fadder.h"
#include "r6502.h"
#include "opcode.h"
#include "globalreg6502.h"
void ins0x69()
{
	bool isNonZero = false;
	bool accumsign = accum.getQ(NEGATIVE);
	reg6502 value;
	int carry = 0;
	FADDER adder;

	for (int x = 0; x < 8; x++)
	{
		adder.set(accum.getQ(x), value.getQ(x), carry);
		//accum.set(adder.getSum());
		//carry = adder.getCarryOut();
		isNonZero = isNonZero | accum.getQ(x);
	}

	if (isNonZero == true)
		status.set(false, ZERO);
	else
		status.set(true, ZERO);

	if (accum.getQ(NEGATIVE) == true)
		status.set(true, NEGATIVE);
	else
		status.set(false, NEGATIVE);

	if (carry == true)
		status.set(true, CARRY);
	else
		status.set(false, CARRY);

	if (accumsign == true && value.getQ(NEGATIVE) == true)
	{
		if (accum.getQ(NEGATIVE) == true)
			status.set(false, OVERFLOW);
	}
	else if (accumsign == false && value.getQ(NEGATIVE) == false)
	{
		if (accum.getQ(NEGATIVE) == false)
			status.set(false, OVERFLOW);
	}
	else
		status.set(true, OVERFLOW);
}
