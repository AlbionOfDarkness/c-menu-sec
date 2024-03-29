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
        printf("\nError mem!");
        getch();
        exit(1);
	}
	return 0;
} 

int ptr_err_adv(void *ptr, char *str)
{
	if (ptr == NULL) 
	{
        printf("\nError mem!");
        printf(" %s", str);
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

void log_p(char *str)
{
//	printf("\n%s\n", str);
return ;
}

void print_array(int *arr, int n, char *str)
{
	printf("\n%s", str);
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}

int find_max_arr(int *arr, int n)
{
	int ans = arr[0];
	for(int i = 1; i < n; i++)
	{
		if(ans < arr[i]) ans = arr[i];
	}
	return ans;
}

void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}

int find_mediana(int *arr, int n)
{
	return (arr[0] + arr[n/2] + arr[n-1]) / 3;
}


