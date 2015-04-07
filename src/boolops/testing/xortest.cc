#include <cstdio>
#include "xor.h"

int main()
{
	bool a, b;
	a = true, b = false;

	printf("--------------------\n");
	printf("TRUE is: %d\n", true);
	printf("FALSE is: %d\n", false);
	printf("--------------------\n\n");

	XOR myXorGate;

	printf(" a b | x \n");
	printf("-----+---\n");

	for(int temp = 0; temp <=3; temp++)
	{
		a = temp & 0x02;
		b = temp & 0x01;
		//if (temp & 0x2)	a = true;
		//else a = false;
		//if (temp & 0x01) b = true;
		//else b = false;
		////switch(temp)
		////{
		////	case 0:
		////		a = false;
		////		b = false;
		////		break;
		////	case 1:
		////		a = false;
		////		b = true;
		////		break;
		////	case 2:
		////		a = true;
		////		b = false;
		////		break;
		////	case 3:
		////		a = true;
		////		b = true;
		////		break;
		////}
		myXorGate.set(a, b);
		printf(" %d %d | %d\n", a, b, myXorGate.get());
	}
	printf("---------\n");
	return(0);
}
