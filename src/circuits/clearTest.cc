#include <cstdio>
#include "and.h"
#include "clear.h"
//testb
int main()
{
	bool a, b;
	a = true, b = false;

	printf("--------------------\n");
	printf("TRUE is: %d\n", true);
	printf("FALSE is: %d\n", false);
	printf("--------------------\n\n");

	AND myAndGate;

	printf(" a b | x | A | c \n");
	printf("-----+---+---+---\n");

	printf(" %d %d | %d | %d | %d \n", false, false, myAndGate.get()), b, false;

	myAndGate.set(a, b);
	printf(" %d %d  | %d | %d | %d \n", a, b, myAndGate.get()), b, false;

	myAndGate.set(b, a);
	printf(" %d %d  | %d | %d | %d \n", b, a, myAndGate.get()), b, false;

	myAndGate.set(true, true);
	printf(" %d %d  | %d | %d | %d \n", true, true, myAndGate.get()), b, false;

	printf("-----------------\n");
	return(0);
nclude <cstdio>
#include "and.h"
#include "clear.h"
//testb
int main()
{
        bool a, b;
        a = true, b = false;

        printf("--------------------\n");
        printf("TRUE is: %d\n", true);
        printf("FALSE is: %d\n", false);
        printf("--------------------\n\n");

        AND myAndGate;

        printf(" a b | x | A | c \n");
        printf("-----+---+---+---\n");

        printf(" %d %d | %d | %d | %d \n", false, false, myAndGate.get()), b, false;

        myAndGate.set(a, b);
        printf(" %d %d  | %d | %d | %d \n", a, b, myAndGate.get()), b, false;

        myAndGate.set(b, a);
        printf(" %d %d  | %d | %d | %d \n", b, a, myAndGate.get()), b, false;

        myAndGate.set(true, true);
        printf(" %d %d  | %d | %d | %d \n", true, true, myAndGate.get()), b, false;

        printf("-----------------\n");
        return(0);
}}
