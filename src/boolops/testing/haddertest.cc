#include <cstdio>
#include "hadder.h"
#include "and.h"
#include "xor.h"

int main()
{
	bool a, b;
	a = true, b = false;

	printf("--------------------\n");
	printf("TRUE is: %d\n", true);
	printf("FALSE is: %d\n", false);
	printf("--------------------\n\n");

	HADDER myhadder;

	printf(" a b | s c\n");
	printf("-----+-----\n");

	printf(" %d %d | %d %d\n", false, false, myhadder.getSum(), myhadder.getCarry());

	myhadder.set(a, b);
	printf(" %d %d | %d %d\n", a, b, myhadder.getSum(), myhadder.getCarry());

	myhadder.set(b, a);
	printf(" %d %d | %d %d\n", b, a, myhadder.getSum(), myhadder.getCarry());

	myhadder.set(true, true);
	printf(" %d %d | %d %d\n", true, true, myhadder.getSum(), myhadder.getCarry());

	printf("-----------\n");
	return(0);
}
