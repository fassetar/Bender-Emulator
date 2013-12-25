#include <cstdio>
#include "nand.h"

int main()
{
	bool a, b;
	a = true, b = false;

	printf("--------------------\n");
	printf("TRUE is: %d\n", true);
	printf("FALSE is: %d\n", false);
	printf("--------------------\n\n");

	NAND myNandGate;

	printf(" a b | x \n");
	printf("-----+---\n");

	printf(" %d %d | %d\n", false, false, myNandGate.get());

	myNandGate.set(a, b);
	printf(" %d %d | %d\n", a, b, myNandGate.get());

	myNandGate.set(b, a);
	printf(" %d %d | %d\n", b, a, myNandGate.get());

	myNandGate.set(true, true);
	printf(" %d %d | %d\n", true, true, myNandGate.get());

	printf("---------\n");
	return(0);
}
