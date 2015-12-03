#include<cstdio>

int main()
{
	bool quit = false;
	char input;
	char location[12];

	printf("----------------------------------------------------------------\n");
	printf("- Bender Emulator by Anthony Fassett						    \n");
	printf("----------------------------------------------------------------\n");
	printf("- URL: https://github.com/fassetar/Bender-Emulator             -\n");
	printf("----------------------------------------------------------------\n");
	printf("- Press '?' for command help menu.                             -\n");
	printf("----------------------------------------------------------------\n");

	sprintf_s(location, "simulator");

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
			sprintf_s(location, "cpu");

		if ((input == 'M') || (input == 'm'))
			sprintf_s(location, "memory");

		if ((input == 'Q') || (input == 'q'))
			quit = true;

		input = getchar();
	}
	return(0);
}
