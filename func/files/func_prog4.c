#include "../../header.h"

int index_srs;

char** take_strs_file_to_2d_arr(FILE *fp)
{
	char** strs_of_files;
	strs_of_files = (char**)calloc(0, sizeof(char*));
	ptr_err(strs_of_files);
	
	char* buffer;
	buffer = (char*)calloc(255, sizeof(char));
	ptr_err(buffer);

	while(feof(fp) == 0)
	{
		fgets(buffer, 255, fp);
		
		strs_of_files = (char**)realloc(strs_of_files, (index_srs + 1) * sizeof(char*));
		
		char *fix_ptr = strrchr(buffer, '\n'); // fix entere to end str
		if(fix_ptr != NULL) *fix_ptr = '\0';

		strs_of_files[index_srs] = (char*)calloc(255, sizeof(char));
		ptr_err(strs_of_files[index_srs]);
		
		strcpy(strs_of_files[index_srs], buffer);
		
		index_srs++;
	}
	
	free(buffer);
	return strs_of_files;
}

void write_strs_to_file(FILE *fp, char** arr_2d)
{
	for(int i = 0; i < index_srs; i++)
	{
		char *fix_ptr = strrchr(arr_2d[i], '\0'); // fix entere to end str
		if(fix_ptr != NULL) *fix_ptr = '\n';
		
		fputs(arr_2d[i], fp);
	}
}

void printf_2d_arr(char** arr, int n)
{
	printf("\n[index %d]", index_srs);
	for(int j = 0; j < n; j++)
	{
		printf("\nStr[%d]:%s", j, arr[j]);
	}
}

char** edit_2d_mas(char **arr_2d)
{
	printf("\nStart editing\n");
	for(int i = index_srs - 1; i >= 0; i--)
	{
		if(check_for_space(arr_2d[i]) == 0)
		{
			printf("\nTake 1 if\n");
			strcat(arr_2d[i], "\nHello World!");
			return arr_2d;
		}
	}
	
	printf("\nTake 2 if\n");
	strcat(arr_2d[index_srs-1], "\nHello World!");
	return arr_2d;
}

void free_2d_arr(char **arr_2d)
{
	for(int i = 0; i < index_srs; i++)
	{
		free(arr_2d[i]);
	}
	free(arr_2d);
	printf("\nMem succesfully clear!");
}

void prog_16_2(void)
{
	index_srs = 0;
	FILE *file;	
	file = fopen("files/for_4_1.txt", "r");
	file_err(file);
	
	// take file into 2d arr
	char** strs_2d = take_strs_file_to_2d_arr(file);

	printf_2d_arr(strs_2d, index_srs);
	
    fclose(file);
    printf("\nFile close for read");
    
    strs_2d = edit_2d_mas(strs_2d);
    
    file = fopen("files/for_4_1_w.txt", "w");
    file_err(file);
    
    write_strs_to_file(file, strs_2d);
    
    fclose(file);
    
    free_2d_arr(strs_2d);
    
    printf("\n\nALL DONE CHECK FILESE\n");
	system("pause");
}