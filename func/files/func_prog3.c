#include "../../header.h"

int num_of_str;

char* add_num_to_str(char *str)
{
    char *ans_str;
    ans_str = (char*)calloc(255, sizeof(char));
    ptr_err(ans_str);
    
	char tmp[5];
	
	strcpy(ans_str, str);
	
	sprintf(tmp, " %d", num_of_str);
	num_of_str++;
	
	strcat(ans_str, tmp);
	
	return ans_str;
}

void prog_16_1(void)
{
	num_of_str = 1;
	FILE *file_read;
	FILE *file_write;
	char buffer[255];

	file_read = fopen("files/for_3.txt", "r");
	file_err(file_read);

	file_write = fopen("files/for_3_w.txt", "w");
	file_err(file_write);
	
	// work with file
	while(feof(file_read) == 0)
	{
		fgets(buffer, 254, file_read);
		
//		if(strcmp(buffer, "\n") == 0) continue;
		
		char *fix_ptr = strrchr(buffer, '\n'); // fix entere to end strs
		if(fix_ptr != NULL) *fix_ptr = '\0';
		
		char *ans_str;
		ans_str = add_num_to_str(buffer);
		
		ans_str[strlen(ans_str)] = '\n'; // add enter
		fputs(ans_str, file_write);
		
		free(ans_str);
	}
	
	fclose(file_write);
    fclose(file_read);
    
    printf("\nALL DONE CHECK FILESE\n");
	system("pause");
}