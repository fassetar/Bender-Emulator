#include "xnor.h"
#include "xor.h"
#include "not.h"


XNOR::XNOR()
{
 input1 = input2 = false;
}
void XNOR::set()
{
 input1 = input2 = false;
}

void XNOR::set(bool value)
{
 input1 = input2 = value;
}

void XNOR::set(bool value1, bool value2)
{
 input1 = value1;
 input2 = value2;
}
bool XNOR::get()
{
 myXORGate.set(input1, input2);
 myNotGate.set(myXORGate.get());
 return(myNotGate.get());
}
