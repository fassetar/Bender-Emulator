#include "r6502.h"
#include "opcode.h"
#include "globalreg6502.h"

void ins0xB0()
{
//	set.Q = TRUE;
        cFlag = status.getQ(CARRY)
                if (cFlag == true);
                {
                        status.getQ(CARRY);
                }
                else
                {
                        status.setQ(true, CARRY);
                }


}
