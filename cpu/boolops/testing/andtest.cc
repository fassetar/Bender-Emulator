#include <cstdio>
#include "and.h"

int main()
{
	bool a, b;
	a = true, b = false;

	printf("--------------------\n");
	printf("TRUE is: %d\n", true);
	printf("FALSE is: %d\n", false);
	printf("--------------------\n\n");

	AND myAndGate;

	printf(" a b | x \n");
	printf("-----+---\n");

	printf(" %d %d | %d\n", false, false, myAndGate.get());

	myAndGate.set(a, b);
	printf(" %d %d | %d\n", a, b, myAndGate.get());

	myAndGate.set(b, a);
	printf(" %d %d | %d\n", b, a, myAndGate.get());

	myAndGate.set(true, true);
	printf(" %d %d | %d\n", true, true, myAndGate.get());

	printf("---------\n");
	return(0);
}
