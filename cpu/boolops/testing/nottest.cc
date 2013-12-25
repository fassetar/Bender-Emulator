#include<cstdio>
#include"not.h"

int main()
{
	bool a = true;

	printf("--------------------\n");
	printf("TRUE is: %d\n", true);
	printf("FALSE is: %d\n", false);
	printf("--------------------\n\n");

	NOT myNotGate;

	printf(" a | x \n");
	printf("---+---\n");

	printf(" %d | %d\n", false, myNotGate.get());

	myNotGate.set(a);
	printf(" %d | %d\n", true, myNotGate.get());

	printf("---------\n");

	return(0);
}
