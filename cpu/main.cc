#include<cstdio>

int main()
{
	bool quit = false;
	char input;
	char location[12];

	printf("----------------------------------------------------------------\n");
	printf("- CSCS2650 Computer Organization - Spring 2011 - CPU Simulator -\n");
	printf("----------------------------------------------------------------\n");
	printf("- URL: http://lab46.corning-cc.edu/notes/asm                   -\n");
	printf("----------------------------------------------------------------\n");
	printf("- Press '?' for command help menu.                             -\n");
	printf("----------------------------------------------------------------\n");

	sprintf(location, "simulator");

	while (quit != true)
	{
		printf("%s> ", location);
		input = getchar();

		if (input == '?')
		{
			switch(location[0])
			{
				case 's':
					printf(" 'L'oad\n");
					printf(" 'C'PU Mode\n");
					printf(" 'Q'uit Simulator\n");
					break;

				case 'c':
					printf(" 'M'emory\n");
					printf(" 'R'egisters\n");
					printf(" 'E'dit Program\n");
					printf(" 'D'ebug Program Execution\n");
					printf(" e'X'ecute Program in Memory\n");
					printf(" 'Q'uit Simulator\n");
					break;

				case 'm':
					printf(" 'D'isplay Memory Contents\n");
					printf(" 'C'lear Memory\n");
					printf(" 'Q'uit Simulator\n");
					break;
			}
		}

		if ((input == 'C') || (input == 'c'))
			sprintf(location, "cpu");

		if ((input == 'M') || (input == 'm'))
			sprintf(location, "memory");

		if ((input == 'Q') || (input == 'q'))
			quit = true;

		input = getchar();
	}
	return(0);
}
