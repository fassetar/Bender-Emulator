#include <cstdio>
#include "and.h"
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

        printf(" %d %d | %d | 1 | %d \n", false, false, myAndGate.get()), b, true;

        myAndGate.set(a, b);
        printf(" %d %d  | %d | 1 | %d \n", a, b, myAndGate.get()), b, true;

        myAndGate.set(b, a);
        printf(" %d %d  | %d | 1 | %d \n", b, a, myAndGate.get()), b, true;

        myAndGate.set(true, true);
        printf(" %d %d  | %d | 1 | %d \n", true, true, myAndGate.get()), b, true;

        printf("-----------------\n");
        return(0);
}

