#include "../../header.h"

char* reverse_words_str(char* str)
{
    char *ans_str;
    ans_str = (char*)calloc(255, sizeof(char));
    ptr_err(ans_str);
	char *tmp;
	tmp = (char*)malloc(255 * sizeof(char));
	ptr_err(tmp);
	
	int index_ans_str = 0;

	char *start_word, *end_word;
	
	strcpy(tmp, str);
	

	int first_len = strlen(tmp);
	int check_len = strlen(tmp);

	
	while(check_len != 0)
	{
		// Option for ptr
		start_word = strrchr(tmp, ' ');
		end_word = &tmp[strlen(tmp)];
		
		if(start_word == NULL)
		{
			start_word = &tmp[0];
			while(start_word != end_word)
			{
				ans_str[index_ans_str] = *start_word;
				start_word++;
				index_ans_str++;
			} 
			ans_str[index_ans_str + 1] = '\0';
			index_ans_str++;			
			break;
		}
		
		// One word to first
		while(start_word != end_word - 1)
		{
			start_word++;
			ans_str[index_ans_str] = *start_word;
			index_ans_str++;
		} 
		index_ans_str++;
//		ans_str[index_ans_str] = ' '; // C good?
		strcat(ans_str, " ");
		
		check_len = first_len - index_ans_str;
		tmp[check_len] = '\0';
	}
	
	free(tmp);
	
	return ans_str;
}

void prog_10_2(void)
{
	FILE *file_read;
	FILE *file_write;
	char buffer[255];

	file_read = fopen("files/for_2.txt", "r");
	file_err(file_read);

	file_write = fopen("files/for_2_w.txt", "w");
	file_err(file_write);
	
	// work with file
	while(feof(file_read) == 0)
	{
		fgets(buffer, 254, file_read);
		
		char *fix_ptr = strrchr(buffer, '\n'); // fix entere to end strs
		if(fix_ptr != NULL) *fix_ptr = '\0';
		
		char *rev_str;
		rev_str = reverse_words_str(buffer);
		rev_str[strlen(rev_str)] = '\n'; // add enter
		fputs(rev_str, file_write);
		
		free(rev_str);
	}
	
	
	fclose(file_write);
    fclose(file_read);
    
    printf("\nALL DONE CHECK FILESE\n");
	system("pause");
}