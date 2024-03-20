#include "../header.h"

int file_err(FILE *file)
{
	if (file == NULL) 
	{
        printf("Error opening file");
        getch();
        exit(1);
	}
	return 0;
}

int ptr_err(void *ptr)
{
	if (ptr == NULL) 
	{
        printf("Error mem!");
        getch();
        exit(1);
	}
	return 0;
} 

int check_for_space(char *str)
{
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] == ' ') return 1;
	}
	return 0;
}

