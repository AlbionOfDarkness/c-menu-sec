#include "../../header.h"

FILE* matrix_choice_file(void)
{
	FILE *ptr;
	char choice;
	printf("\nInput num fo file to open(1-3): ");
	choice = getch();
	switch(choice)
	{
		case '1':
			ptr = fopen("files/matrix/matrix_1.txt", "r");
			break;
		case '2':
			ptr = fopen("files/matrix/matrix_2.txt", "r");		
			break;
		case '3':
			ptr = fopen("files/matrix/matrix_3.txt", "r");	
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

int** create_matrix(int col, int size)
{
	int **matrix = (int**)calloc(col, sizeof(int*));
	ptr_err(matrix);
	for(int i = 0; i < col; i++)
	{
		matrix[i] = (int*)calloc(size, sizeof(int));
		ptr_err(matrix[i]);
	}
	return matrix;
}

void print_matrix(int **matrix, int col, int size, char* str)
{
	printf("\n%s\n", str);
	for(int i = 0; i < col; i++)
	{
		printf("\n");
		for(int j = 0; j < size; j++)
		{
			printf("%3d ", matrix[i][j]);
		}
	}
}

int** sort_matrix_1(int** matrix, int col, int size)
{
	int* temp_arr = (int*)malloc(0 * sizeof(int));
	ptr_err(temp_arr);
	
	for(int col_now = 1; col_now < col; col_now++)
	{
		int acces_col = col_now;
		int j = 0;
		int acces_to_tmp = 1;
		while(j <= col_now)
		{
			temp_arr = (int*)realloc(temp_arr, acces_to_tmp * sizeof(int));
			ptr_err(temp_arr);
			temp_arr[acces_to_tmp - 1] = matrix[acces_col][j];
			acces_to_tmp++;
			acces_col--;
			j++;
		}
		
		temp_arr = selection_sort_lowToup(temp_arr, j + 1);

		acces_col = col_now;
		j = 0;
		acces_to_tmp = 0;
		while(j <= col_now)
		{
			matrix[acces_col][j] = temp_arr[acces_to_tmp];
			acces_to_tmp++;
			acces_col--;
			j++;
		}
	}
	free(temp_arr);
	
	int* temp_arr_2 = (int*)malloc(0 * sizeof(int));
	ptr_err_adv(temp_arr_2, "malloc");
	
	for(int row_now = 1; row_now < size - 1; row_now++)
	{	
		int acces_row = row_now;
		int acces_col = col - 1;
		int count_in_tmp = 0;
		
		while(acces_row < size)
		{
			count_in_tmp++;
			temp_arr_2 = (int*)realloc(temp_arr_2, count_in_tmp * sizeof(int));
			ptr_err_adv(temp_arr_2, "realloc");
			temp_arr_2[count_in_tmp - 1] = matrix[acces_col][acces_row];
			acces_col--;
			acces_row++;
		}

		temp_arr_2 = selection_sort_lowToup(temp_arr_2, count_in_tmp + 1);
		
		acces_row = row_now;
		acces_col = col - 1;
		count_in_tmp = 0;
		while(acces_row < size)
		{
			matrix[acces_col][acces_row] = temp_arr_2[count_in_tmp];
			count_in_tmp++;
			acces_col--;
			acces_row++;
		}
	}
	free(temp_arr_2);
	return matrix;
}

void matrix_sort_1(void)
{
	FILE *file_read;
	file_read = matrix_choice_file();
	file_err(file_read);
	
	char buffer[30];
	fgets(buffer, 30, file_read);
	
	int col, size;
	
	char *ptr_for_one_field =  strtok(buffer, " ");
	col = atoi(ptr_for_one_field);
	
	ptr_for_one_field = strtok(NULL, " ");
	size = atoi(ptr_for_one_field);
	
	
	int **matrix = create_matrix(col, size);
	ptr_err(matrix);
	
	int i = 0, j = 0;
	while(feof(file_read) == 0)
	{
		fgets(buffer, 30, file_read);
		matrix[i][j] = atoi(buffer);
		j++;
		if(j >= size)
		{
			i++;
			j = 0;
		}
		if(i >= col) break;
	}
	
	print_matrix(matrix, col, size, "Taken matrix is:");
	
	matrix = sort_matrix_1(matrix, col, size);
	
	print_matrix(matrix, col, size, "Sorted matrix is:");
	printf("\n");
	system("pause");
}

void choose_option_matrix_2(int** matrix, int col, int size)
{
	printf("\nInput what dioganale sort firs \n1 - main\n2- side\n");
	int choice_opt_m_2;
	scanf("%d", &choice_opt_m_2);
	switch(choice_opt_m_2)
	{
		case 1:
			sort_matrix_2_main(matrix, col, size);
			break;
		case 2:
			sort_matrix_2_side(matrix, col, size);
			break;
		default:
			printf("\nNo such option");
			system("pause");
			system("cls");
			matrix_sort_2();
	}
}

void sort_matrix_2_main(int** matrix, int col, int size)
{
	print_matrix(matrix, col, size, "Taken matrix is:");
	
	matrix = sort_main_upTolow(matrix, col, size);
	matrix = sort_side_upTolow(matrix, col, size);
	
	print_matrix(matrix, col, size, "Sorted matrix is:");
	printf("\n");
	system("pause");
}

void sort_matrix_2_side(int** matrix, int col, int size)
{
	print_matrix(matrix, col, size, "Taken matrix is:");
	
	matrix = sort_side_upTolow(matrix, col, size);
	matrix = sort_main_upTolow(matrix, col, size);
	
	print_matrix(matrix, col, size, "Sorted matrix is:");
	printf("\n");
	system("pause");
}

int **sort_main_upTolow(int** matrix, int col, int size)
{
	int* temp_arr = (int*)malloc(0 * sizeof(int));
	ptr_err(temp_arr);
	
	int count_in_tmp = 0;
	int i = 0;
	int j = 0;
	
	while(i < col)
	{
		count_in_tmp++;
		temp_arr = (int*)realloc(temp_arr, count_in_tmp * sizeof(int));
		ptr_err_adv(temp_arr, "realloc2");
		
		temp_arr[count_in_tmp - 1] = matrix[i][j];
		i++;
		j++;
	}
	
	temp_arr = bubble_sort_lowToup(temp_arr, count_in_tmp);
	
	i = size - 1;
	j = col - 1;
	count_in_tmp = 0;
	while(i >= 0)
	{
		matrix[i][j] = temp_arr[count_in_tmp] ;
		count_in_tmp++;
		i--;
		j--;
	}
	
	return matrix;
}

int **sort_side_upTolow(int** matrix, int col, int size)
{
	int* temp_arr = (int*)malloc(0 * sizeof(int));
	ptr_err(temp_arr);
	
	int count_in_tmp = 0;
	int i = col - 1;
	int j = 0;
	
	while(i >= 0)
	{
		count_in_tmp++;
		temp_arr = (int*)realloc(temp_arr, count_in_tmp * sizeof(int));
		ptr_err_adv(temp_arr, "realloc2");
		
		temp_arr[count_in_tmp - 1] = matrix[i][j];
		i--;
		j++;
	}
	
	temp_arr = bubble_sort_lowToup(temp_arr, count_in_tmp);
	
	i = col - 1;
	j = 0;
	count_in_tmp = 0;
	while(i >= 0)
	{
		matrix[i][j] = temp_arr[count_in_tmp] ;
		count_in_tmp++;
		i--;
		j++;
	}
	
	return matrix;
}

void matrix_sort_2(void)
{
	FILE *file_read;
	file_read = matrix_choice_file();
	file_err(file_read);
	
	char buffer[30];
	fgets(buffer, 30, file_read);
	
	int col, size;
	
	char *ptr_for_one_field =  strtok(buffer, " ");
	col = atoi(ptr_for_one_field);
	
	ptr_for_one_field = strtok(NULL, " ");
	size = atoi(ptr_for_one_field);
	
	
	int **matrix = create_matrix(col, size);
	ptr_err(matrix);
	
	int i = 0, j = 0;
	while(feof(file_read) == 0)
	{
		fgets(buffer, 30, file_read);
		matrix[i][j] = atoi(buffer);
		j++;
		if(j >= size)
		{
			i++;
			j = 0;
		}
		if(i >= col) break;
	}
	
	choose_option_matrix_2(matrix, col, size);
}