//NEGATION CIRCUIT
#include <iostream>
using namespace std;
#include "AND.h"
#include "OR.h"
// show truth tables for each digital logic gate
int main()
{
Gate  inv = new Inverter();
GateTester::Test(inv);
return 0;
}
