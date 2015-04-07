#include <cstdio>
#include "cpumem.h"
const int MEM_MAX = 65535;
int main()
{
	CPUMEM datamemory;
	for (int temp = 0x00; temp <= MEM_MAX; temp++) datamemory.write(temp, 255);
	for(int temp = 0x00; temp <= MEM_MAX; temp++) printf("Memory address %x contains the value %x\n", temp, datamemory.read(temp));
	return(0);
}
