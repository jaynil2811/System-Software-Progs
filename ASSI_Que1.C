#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

char kw[32][10] = {"int","float","while","for","char","do","break","auto",
		    "continue","default","double","if","else","enum","union",
		    "goto","long","switch","typedef","unsigned","void","case",
		    "volatile","extern","const","return","sizeof","static",
		    "struct","register","signed" };

char op[15][10] = {"+","/","*","%","-","=",":",",",";","<",">","."};

char identifiers[20][10];
char constants[20][10];
int ic = 0 , cc = 0;                   	 // 3059 - Jaynil Prajapati
char str[100];
void analyzeString(char str[]);

int main()
{
    FILE *file;
    char input[500];
    char filename[100];

    clrscr();
    printf("Jaynil Prajapati \n3059 :- A\n\n");

    printf("Enter your code:\n");
    fgets(input, sizeof(input), stdin);        // 3059 - Jaynil Prajapati

    printf("Enter the filename to save the code: ");
    fgets(filename, sizeof(filename), stdin);
    strtok(filename, "\n");

    file = fopen(filename, "w");

    if(file == NULL)
    {
	printf("Error creating/opening the file.\n");
	return 1 ;
    }
    fprintf(file, "%s", input);

    fclose(file);
    file = fopen(filename, "r");

    if(file == NULL)                  // 3059 - Jaynil Prajapati
    {
	printf("Error opening the file for reading.\n");
	return 1;
    }

    while(fgets(str,sizeof(str),file) != NULL)
    {
	analyzeString(str);
    }

    fclose(file);
    getch();
    return 0;
}

void analyzeString(char str[])
{
    char *ptr;
    int i , j ;            // 3059 - Jaynil Prajapati

    ptr = strtok(str," \n\t");

    while(ptr != NULL)
    {
	int flag = 0 ;

	for(i=0;i<32;i++)
	{
	    if(strcmp(ptr,kw[i])==0)
	    {
		printf("[KW #%d] ",i+1);
		flag = 1;
		break;
	    }
	}

	if(flag==0)
	{
	    for(j=0;j<10;j++)
	    {
		if(ptr[0] == op[j][0])
		{
		    printf("[OP #%d] ",j+1);
		    flag = 1;
		    break;                      // 3059 - Jaynil Prajapati
		}
	    }
	}

	if(flag==0)
	{
	    if(isalpha(ptr[0]))
	    {
		int isRepeated = 0;
		for(i=0;i<ic;i++)
		{
		    if(strcmp(ptr,identifiers[i])==0)
		    {
			printf("[ID #%d] ",i+1);
			isRepeated = 1;
			break;
		    }
		}                        // 3059 - Jaynil Prajapati
		if(!isRepeated)
		{
		    strcpy(identifiers[ic++],ptr);
		    printf("[ID #%d] ",ic);
		}
	    }
	    else if(isdigit(ptr[0]))
	    {
		int isRepeated = 0;
		for(i=0;i<cc;i++)
		{
		    if(strcmp(ptr,constants[i])==0)
		    {
			printf("[CO #%d] ",i+1);
			isRepeated = 1;
			break;
		    }
		}                          // 3059 - Jaynil Prajapati
		if(!isRepeated)
		{
		    strcpy(constants[cc++],ptr);
		    printf("[CO #%d] ",cc);
		}
	    }
	}
	ptr = strtok(NULL," \n\t");
    }
}
