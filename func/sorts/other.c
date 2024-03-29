#include "../../header.h"
FILE* array_choice_file(void)
{
	FILE *ptr;
	char choice;
	printf("\nInput num fo file to open(1-3): ");
	choice = getch();
	switch(choice)
	{
		case '1':
			ptr = fopen("files/array/array_1.txt", "r");
			break;
		case '2':
			ptr = fopen("files/array/array_2.txt", "r");		
			break;
		case '3':
			ptr = fopen("files/array/array_3.txt", "r");	
			break;
		default:
			printf("\nNot valid option");
			fflush(stdin);
			menu_sorts();
	}
	fflush(stdin);
	file_err(ptr);
	return ptr;
}
int global_n;
int *take_array_from_file(void)
{
	FILE *file_read;
	file_read = array_choice_file();
	file_err(file_read);
	
	int num_elements;
	char buffer[5];
	fgets(buffer, 5, file_read);
	num_elements = atoi(buffer);
	printf("\nNum of elemen: %d", num_elements);
	global_n = num_elements;
	
	int* arr = (int*)calloc(num_elements+1, sizeof(int));
	ptr_err_adv(arr, "take_array_from_file");
	
	int i = 0;
	while(feof(file_read) == 0)
	{
		fgets(buffer, 30, file_read);
		arr[i] = atoi(buffer);
		i++;
	}
	printf("\nArray succesfully taken from file");
	return arr;
}




void shell_sort_menu(void)
{
	printf("\nShell sort:\n");
	int *arr = take_array_from_file();
	print_array(arr, global_n, "Tkn arr:");
//	printf("\n\t%d / %d = %d", sizeof(arr), sizeof(int), sizeof(arr) / sizeof(int));
	arr = shell_sort(arr, global_n);
	print_array(arr, global_n, "Srt arr:");
	free(arr);
	printf("\n");
	system("pause");
}
void quick_sort_menu(void)
{
	printf("\nQuick sort:\n");
	int *arr = take_array_from_file();
	print_array(arr, global_n, "Tkn arr:");
	quick_sort(arr, 0, global_n);
	print_array(arr, global_n, "Srt arr:");
	free(arr);
	printf("\n");
	system("pause");
}
void count_sort_menu(void)
{
	printf("\nCount sort:\n");
	int *arr = take_array_from_file();
	print_array(arr, global_n, "Tkn arr:");
	arr = count_sort(arr, global_n);
//	print_array(arr, global_n, "Srt arr:");
	free(arr);
	printf("\n");
	system("pause");
}