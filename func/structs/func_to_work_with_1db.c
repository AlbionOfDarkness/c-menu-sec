#include "../../header.h"

struct student_info
{
	unsigned int id;
	char name[255];
	int date;
	int code;
} *data_base_1;


int count_of_fields_1bd = 0;
int id_for_arr = 0;
unsigned int id_to_write = 0;

void snif_data_base_from(unsigned int id_for_del, int count_of_field)
{
	for(int i = id_for_del; i < count_of_field; i++)
	{
		data_base_1[i] = data_base_1[i + 1];
		data_base_1[i].id = i + 1;
	}

	count_of_fields_1bd--;
	data_base_1 = (struct student_info*)realloc(data_base_1, count_of_fields_1bd * sizeof(struct student_info));
	ptr_err(data_base_1);
}

void add_student_to_1bd(void)
{
	fflush(stdin);
	count_of_fields_1bd++;
	data_base_1 = (struct student_info*)realloc(data_base_1, (count_of_fields_1bd) * sizeof(struct student_info));
	ptr_err(data_base_1);
	
	id_to_write++;
	data_base_1[id_for_arr].id = id_to_write;
	
	
	printf("\nInput name_field of student\n");
	char tmp_str[255];
	gets(tmp_str);
	strcpy(data_base_1[id_for_arr].name, tmp_str);
	printf("name:%s", data_base_1[id_for_arr].name);
	
	printf("\nInput date_of_birth of student\n");
	scanf("%d", &data_base_1[id_for_arr].date);
	printf("Date is:%d", data_base_1[id_for_arr].date);
	
	printf("\nInput code_of_group student\n");
	scanf("%d", &data_base_1[id_for_arr].code);
	printf("CodeGroup is:%d", data_base_1[id_for_arr].code);
	
	id_for_arr++;
	
	printf("\nFIELD student succesfully added to DataBase\nIDs are changed!\n");
	system("pause");
}

void delete_student_by_id(void)
{
	if(count_of_fields_1bd == 0) 
	{
		printf("\nThere is nothing to delete");
		return;
	}
	if(count_of_fields_1bd == 1)
	{
		char input_confirm;
		print_console_1db();
		printf("\nIn DataBase only 1 field, press Y to delete or another key to decline");
		input_confirm = getch();
		if(input_confirm == 'y' || input_confirm == 'Y')
		{
			count_of_fields_1bd = 0;
			id_for_arr = 0;
			id_to_write = 0;
			free(data_base_1);
			printf("\nDataBase Clear!");
			return;
		}
		return;
	}
	
	unsigned int tmp_id;
	
	
	do
	{
		print_console_1db();
		printf("\nMax id[%d]\nInput id to delete: ", id_to_write - 1);
		scanf("%d", &tmp_id);
		
		if(tmp_id > id_to_write - 1 || tmp_id <= 0)
		{
		printf("\nThere is no same id");
		printf("\nTry again");
		}
	}
	while(tmp_id > id_to_write - 1 || tmp_id <= 0);

	
	snif_data_base_from(tmp_id - 1, count_of_fields_1bd);
	id_for_arr--;
	id_to_write--;
	
	printf("\nID = [%d] SUCCESFULLY deleted from DataBase\n", tmp_id);
	
}

int find_student_by_name(char name[255], int count_of_field)
{
	for(int i = 0; i < count_of_fields_1bd; i++)
	{
		if(strcmp(name, data_base_1[i].name) == 0) return i;
	}
	return -1;
}

void delete_student_by_name(void)
{	
	if(count_of_fields_1bd == 0) 
	{
		printf("\nThere is nothing to delete");
		return;
	}
	if(count_of_fields_1bd == 1)
	{
		char input_confirm;
		print_console_1db();
		printf("\nIn DataBase only 1 field, press Y to delete or another key to decline");
		input_confirm = getch();
		if(input_confirm == 'y' || input_confirm == 'Y')
		{
			count_of_fields_1bd = 0;
			id_for_arr = 0;
			id_to_write = 0;
			free(data_base_1);
			printf("\nDataBase Clear!");
			return;
		}
		return;
	}
	char tmp_char[255];
	int tmp_id;
	print_console_1db();
	do
	{
		if(strcmp(tmp_char, "0") == 0) return;
		printf("\nInput name to delete: ");
		gets(tmp_char);
	
		tmp_id = find_student_by_name(tmp_char, count_of_fields_1bd);
		if(tmp_id == -1) printf("\nName not found try again or input 0 to close this funcion");
		
	}while(tmp_id == -1);
	
	snif_data_base_from(tmp_id, count_of_fields_1bd);
	id_for_arr--;
	id_to_write--;
	
	printf("\nID = [%s] SUCCESFULLY deleted from DataBase", tmp_char);
}

void take_data_to_fild_student_from_file(int id, char *str)
{	
	char *ptr_for_one_field =  strtok(str, "_");
	int tmp_num;
	tmp_num = atoi(ptr_for_one_field);
	data_base_1[id].id = tmp_num;
	
	ptr_for_one_field = strtok(NULL, "_");
	strcpy(data_base_1[id].name, ptr_for_one_field);
	
	ptr_for_one_field = strtok(NULL, "_");
	tmp_num = atoi(ptr_for_one_field);
	data_base_1[id].date = tmp_num;
	
	ptr_for_one_field = strtok(NULL, "_");
	tmp_num = atoi(ptr_for_one_field);
	data_base_1[id].code = tmp_num;
}



void take_1db_from_file(void)
{
	free(data_base_1);
	data_base_1 = (struct student_info*)calloc(sizeof(struct student_info), 0);
	
	count_of_fields_1bd = 0;
	id_for_arr = 0;
	id_to_write = 1;
	
	FILE *file_ptr = fopen("files/saves/database1var1.txt", "r");
	file_err(file_ptr);
	
	char buffer[511];
	while(feof(file_ptr) == 0)
	{
		fgets(buffer, 511, file_ptr);
		count_of_fields_1bd++;
		data_base_1 = (struct student_info*)realloc(data_base_1, count_of_fields_1bd * sizeof(struct student_info));
		ptr_err(data_base_1);
		
		
		take_data_to_fild_student_from_file(id_for_arr, buffer);
		id_for_arr++;
		id_to_write++;
	}

	printf("\nStruct arr succesfully taken from file!\n");
	

	
	fclose(file_ptr);
	system("pause");
}


void save_1db_to_file(void)
{
	if(count_of_fields_1bd == 0)
	{
		printf("\nNothing to save");
		return;
	}
	
	FILE *file_ptr = fopen("files/saves/database1var1.txt", "w");
	file_err(file_ptr);
	
	for(int i = 0; i < count_of_fields_1bd - 1; i++)
	{
		fprintf(file_ptr, "%d_%s_%d_%d\n", data_base_1[i].id, data_base_1[i].name, data_base_1[i].date, data_base_1[i].code);
	}
	// if in end of file will be space it broken prog, fix it
	fprintf(file_ptr, "%d_%s_%d_%d", data_base_1[count_of_fields_1bd - 1].id, data_base_1[count_of_fields_1bd - 1].name, data_base_1[count_of_fields_1bd - 1].date, data_base_1[count_of_fields_1bd - 1].code);
	printf("\nSave successfully into file!\n");
	fclose(file_ptr);
	system("pause");
}

void print_console_1db(void)
{
	for(int i = 0; i < count_of_fields_1bd; i++)
	{
		printf("ID[%3d]\tName:%30s\tDate:%4d\tCode:%4d\n", data_base_1[i].id, data_base_1[i].name, data_base_1[i].date, data_base_1[i].code);
	}
}


