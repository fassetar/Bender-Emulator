#include <cstdio>
#include <ctype.h>
#include <stdlib.h>
#include "alu.h"
#include<string.h>
unsigned char convert2CharStringTo2DigitHex(char * string);
void getAndPrintVal(char *printString, char *valString);
void prompt(char *);

int main()
{
	char *message;
	char message1[18] = "Enter instruction";
	char message2[24] = "Enter Accumulator value";
	char message3[31] = "Enter Temporary Register value";
	char hex2DigitString[3];
	char quit;
	char *pQuit;
	pQuit = &quit;

	ALU alu8085;
	printf("Welcome to the 8085 alu simulator\n");
	prompt(pQuit);
	while(toupper(quit)!= 'Q')
	{
		message = message1;
		for (int i = 1; i <= 3; i++)	
		{
			getAndPrintVal(message,  hex2DigitString);
			switch(i)
			{
				case 1:
					alu8085.setInstruction(convert2CharStringTo2DigitHex(hex2DigitString));
					message = message2;
					break;
				case 2:
					alu8085.setAccumu(convert2CharStringTo2DigitHex(hex2DigitString));				
					message = message3;
					break;
				case 3:
					alu8085.setTempReg(convert2CharStringTo2DigitHex(hex2DigitString));
					break;
			}
		}
	        alu8085.doOp();
        	printf("Result is 0x%02x\n",  alu8085.getAccumulator());
                printf("Flag Register = 0x%02x\n",alu8085.getFlags());
        	printf("Sign flag is %x\n", alu8085.getSignFlag());
		printf("Carry flag is %x\n", alu8085.getCarryFlag());
		printf("Zero flag is %x\n", alu8085.getZeroFlag());
		printf("Parity flag is %x\n", alu8085.getParityFlag());
		printf("Aux carry flag is %x\n", alu8085.getAuxCarryFlag());
		printf("\n");
		prompt(pQuit);
	}
	return(0);
}

unsigned char convert2CharStringTo2DigitHex(char * string)
{
	for (int i = 0; i < 2; i++)
	{
		if(*(string + i) >= '0' && *(string + i) <= '9') *(string + i) = 0x0f & *(string + i);
		else if (*(string + i) >= 'a' && *(string + i) <= 'f') *(string + i) = *(string + i) - 87;
       }
        *string = *string << 4;
        *string = *(string + 1)|*string;
	return(*string);
}

void getAndPrintVal(char *printString, char *valString)
{
	bool doneFlag = false;
	while (!doneFlag)
	{
        	printf(printString);
        	printf("\n");
        	printf("0x");
		scanf("%s", valString);
        	int check = (int) strnlen(valString, 10);
        	if(check > 2)
		{
			printf("Fatal error-hex value is greater than 2 digits\n");
			exit(0);
        	}
		else if (check < 2)
		{
                	printf("Error-hex value is must be at least 2 digits\n");
                	doneFlag = false;
		}
		else
		{
			for (int i = 0; i < 2; i++)
			{
				 *(valString + i) = tolower(*(valString + i));
        			if((*(valString + i) >= '0' && *(valString + i) <= '9') || (*(valString + i) >= 'a' && *(valString + i) <= 'f'))
				{
					doneFlag = true;
				} 
				else
				{
					doneFlag = false;
                			printf("Error, digits must be 0-9 or a-f\n");
					break;
				} 
			}
		}
	}
}


void prompt(char *quit)
{
        printf("Press c to continue, or q to quit\n");
        scanf("%s", quit);
}
