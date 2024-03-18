#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stat_table[6][4][10] = {
    {"stat", "letter", "digit", "."},
    {"start", "id", "int", "error"},
    {"id", "id", "id", "error"},
    {"int", "error", "int", "s"},      // 3059 - Jaynil Prajapati
    {"s", "error", "real", "error"},
    {"real", "error", "real", "error"},
};

int main()
{
    char input[20], column_stat[10],prev_stat[10], current_stat[10], next_stat[10];
    char ch, choice;
    int flag, error, i, c, r, len;
    clrscr();
    printf("Jaynil Prajapati\n3059 :- A\n");
    do
    {
	printf("Enter identifier: ");
	scanf("%s", &input);

	len = strlen(input);

	strcpy(current_stat, "start");

	flag = 0;                 // 3059 - Jaynil Prajapati
	error = 0;

	for (i = 0; i < len && !error; i++)
	{
	    ch = input[i];

	    if (isalpha(ch))
	    {
		strcpy(column_stat, "letter");
	    }
	    else if (isdigit(ch))
	    {
		strcpy(column_stat, "digit");
	    }
	    else if (ch == '.')
	    {
		strcpy(column_stat, "."); // 3059 - Jaynil Prajapati
	    }
	    else
	    {
		strcpy(next_stat, "error");
		error = 1;
		break;
	    }

	    for (r = 1; r < 6; r++)

	    {
		if (strcmp(stat_table[r][0], current_stat) == 0)
		{
		    for (c = 1; c < 4; c++)
		    {
			if (strcmp(stat_table[0][c], column_stat) == 0)
			{
			    strcpy(next_stat, stat_table[r][c]);
			    break;
			}
		    }                  // 3059 - Jaynil Prajapati

		    if (strcmp(next_stat, "error") == 0)
		    {
			flag = 1;
			error = 1;
			break;
		    }

		    if ((i == len - 1) && (strcmp(next_stat, "s") == 0))
		    {
			flag = 1;
			break;
		    }           // 3059 - Jaynil Prajapati

		    strcpy(prev_stat,current_stat);
		    strcpy(current_stat, next_stat);
		    break;
		}
	    }
	    printf("%s\t%c\t%s\n",prev_stat,input[i],current_stat);
	}

	if (flag > 0)
	{
	    printf("\nInvalid Token");
	}
	else
	{
	    printf("\nValid Token");

	    if (strcmp(current_stat, "id") == 0)
	    {
		printf("\nIt is an identifier");   // 3059 - Jaynil Prajapati
	    }
	    else if (strcmp(current_stat, "int") == 0)
	    {
		printf("\nIt is an integer");
	    }
	    else if (strcmp(current_stat, "real") == 0)
	    {
		printf("\nIt is a real");
	    }
	}

	printf("\n\nDo you want to continue? (enter 'y' for yes and 'n' for no): ");
	scanf(" %c", &choice);

    } while (choice != 'n');

    return 0;
}