#include "../../header.h"

const short int day_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//const short int day_in_month[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

struct history_event
{
	unsigned int id;
	int global_date_days; // b.e. year * 365 + month(id) * day_in_month + day
	
	char name[127];
	int year;
	int month;
	int day;
	
} *data_base_2;


int count_of_fields_2bd = 0;
int id_for_2bd = 0;

void snif_data_base_from_for2bd(unsigned int id_for_del, int count_of_field)
{
	for(int i = id_for_del; i < count_of_field; i++)
	{
		data_base_2[i] = data_base_2[i + 1];
		data_base_2[i].id = i + 1;
	}

	count_of_fields_2bd--;
	data_base_2 = (struct history_event*)realloc(data_base_2, count_of_fields_2bd * sizeof(struct history_event));
	ptr_err(data_base_2);
}

void input_name_2bd(int id)
{
	printf("\nInput name_field of h_event\n");
	char tmp_str[127];
	gets(tmp_str);
	strcpy(data_base_2[id].name, tmp_str);
	printf("H_event:%s", data_base_2[id].name);
}

void input_year_2bd(int id)
{
	do
	{
		printf("\nInput YEAR of h_event\n");
		scanf("%d", &data_base_2[id].year);
		if (data_base_2[id].year < 0)
		{
			printf("\nSorry, but my DataBase not alowed date befor Crist was born try again!\n");
		}
	}while(data_base_2[id].year < 0);
}

void input_month_2bd(int id)
{
	do
	{
		printf("\nInput MONTH of h_event\n");
		scanf("%d", &data_base_2[id].month);
		if (data_base_2[id].month <= 0 || data_base_2[id].month > 12)
		{
			printf("\nSorry, but my DataBase not alowed more then 12 month or less then 1. Try again!\n");
		}
	}while(data_base_2[id].month <= 0 || data_base_2[id].month > 12);
	data_base_2[id].month--;
}

void input_day_2bd(int id)
{
	do
	{
		printf("\nInput DAY of h_event in this month [%d days]", day_in_month[data_base_2[id].month]);
		scanf("%d", &data_base_2[id].day);
		if ((data_base_2[id].day <= 0 || data_base_2[id].day > day_in_month[data_base_2[id].month]))
		{
			printf("\nSorry, no such day. Try again!\n");
		}
	}while(data_base_2[id].day <= 0 || data_base_2[id].day > day_in_month[data_base_2[id].month]);
}

void fast_input_2bd(int id)
{
	printf("\nInput date by formate [DD MM YYYY] of h_event\n");
	scanf("%d %d %d", &data_base_2[id].day, &data_base_2[id].month, &data_base_2[id].year);
}

int calculate_universal_date(int id)
{
	int how_much_days_to_this_month = 0;
	for(int i = 0; i < data_base_2[id].month; i++)
	{
		how_much_days_to_this_month += day_in_month[i];
	}
	return data_base_2[id].year * 365 + how_much_days_to_this_month + data_base_2[id].day;	
}

void add_history_to_2bd(void)
{
	fflush(stdin);
	count_of_fields_2bd++;
	data_base_2 = (struct history_event*)realloc(data_base_2, count_of_fields_2bd * sizeof(struct history_event));
	ptr_err(data_base_2);
	
	
	printf("\nChoose type of input\nINPUT 1 to fast input(NOT SAFE)\nINPUT any button[NOT 1] to use safe adder\n");
	char fast_choice[1];
	gets(fast_choice);
	
	data_base_2[id_for_2bd].id = id_for_2bd + 1;
	
	if(strcmp(fast_choice, "1") != 0)
	{
		input_name_2bd(id_for_2bd);
		input_year_2bd(id_for_2bd);
		input_month_2bd(id_for_2bd);
		input_day_2bd(id_for_2bd);
		data_base_2[id_for_2bd].global_date_days = calculate_universal_date(id_for_2bd);
	}
	else
	{
		input_name_2bd(id_for_2bd);
		fast_input_2bd(id_for_2bd);
		data_base_2[id_for_2bd].global_date_days = calculate_universal_date(id_for_2bd);
	}
	
	printf("Name[%s]Date is: %d %d %d \t Udata: %d", data_base_2[id_for_2bd].name, data_base_2[id_for_2bd].day, data_base_2[id_for_2bd].month, data_base_2[id_for_2bd].year, data_base_2[id_for_2bd].global_date_days);
	
	id_for_2bd++;
	
	printf("\nFIELD history event succesfully added to DataBase\nIDs are changed!\n");
	system("pause");
}

void delete_history_by_id(void)
{
	if(count_of_fields_2bd == 0) 
	{
		printf("\nThere is nothing to delete");
		return;
	}
	if(count_of_fields_2bd == 1)
	{
		char input_confirm;
		print_console_1db();
		printf("\nIn DataBase only 1 field, press Y to delete or another key to decline");
		input_confirm = getch();
		if(input_confirm == 'y' || input_confirm == 'Y')
		{
			count_of_fields_2bd = 0;
			id_for_2bd = 0;
			free(data_base_2);
			printf("\nDataBase Clear!");
			fflush(stdin);
			return;
		}
		fflush(stdin);
		return;
	}
	
	unsigned int tmp_id;
	
	do
	{
		print_console_2db();
		printf("\nMax id[%d]\nInput id to delete: ", id_for_2bd);
		scanf("%d", &tmp_id);
		
		if(tmp_id > id_for_2bd || tmp_id <= 0)
		{
		printf("\nThere is no same id");
		printf("\nTry again\n");
		}
	}
	while(tmp_id > id_for_2bd || tmp_id <= 0);

	
	snif_data_base_from_for2bd(tmp_id - 1, count_of_fields_2bd);
	id_for_2bd--;
	print_console_2db();
	
	printf("\nID = [%d] SUCCESFULLY deleted from DataBase\n", tmp_id);
}

void difference_history_by_id(void)
{
	if(count_of_fields_2bd < 2) 
	{
		printf("\nThere is nothing to calculate");
		return;
	}
	
	print_console_2db();
	int first_id, sec_id;
	do
	{
		printf("\n\nInput first and second id, firstly than go latest");
		scanf("%d %d", &first_id, &sec_id);
		
		if(first_id <= 0 || sec_id <= 0 || first_id > id_for_2bd || sec_id > id_for_2bd)
		{
		char input_confirm;
		printf("\nNo such ID in DataBase try again or INPUT [-] in cosole to leave\n");
		input_confirm = getch();
		
		if(input_confirm == '-')
			{
				fflush(stdin);
				return;
			}
		fflush(stdin);
		}
	}while(first_id <= 0 || sec_id <= 0 || first_id > id_for_2bd || sec_id > id_for_2bd);
	
	
	printf("\n\nDifference in day with this event is: %d days\n", (data_base_2[sec_id - 1].global_date_days - data_base_2[first_id - 1].global_date_days));
}

void take_data_to_fild_history_from_file(int id, char *str)
{	
	char *ptr_for_one_field =  strtok(str, "_");
	int tmp_num;
	tmp_num = atoi(ptr_for_one_field);
	data_base_2[id].id = tmp_num;
	
	ptr_for_one_field = strtok(NULL, "_");
	strcpy(data_base_2[id].name, ptr_for_one_field);
	
	ptr_for_one_field = strtok(NULL, "_");
	tmp_num = atoi(ptr_for_one_field);
	data_base_2[id].year = tmp_num;
	
	ptr_for_one_field = strtok(NULL, "_");
	tmp_num = atoi(ptr_for_one_field);
	data_base_2[id].month = tmp_num;
	
	ptr_for_one_field = strtok(NULL, "_");
	tmp_num = atoi(ptr_for_one_field);
	data_base_2[id].day = tmp_num;
	
	data_base_2[id].global_date_days = calculate_universal_date(id);
}



void take_2db_from_file(void)
{
	count_of_fields_2bd = 0;
	id_for_2bd = 0;
	data_base_2 = (struct history_event*)calloc(sizeof(struct history_event), 0);

	ptr_err(data_base_2);
	
	
	
	FILE *file_ptr = fopen("files/saves/database2w.txt", "r");
	file_err(file_ptr);
	
	char buffer[127];
	while(feof(file_ptr) == 0)
	{
		fgets(buffer, 127, file_ptr);
		count_of_fields_2bd++;
		data_base_2 = (struct history_event*)realloc(data_base_2, count_of_fields_2bd * sizeof(struct history_event));
		ptr_err(data_base_2);
		
		
		take_data_to_fild_history_from_file(id_for_2bd, buffer);
		id_for_2bd++;
	}

	printf("\nStruct arr succesfully taken from file!\n");
	
	fclose(file_ptr);
	system("pause");
}


void save_2db_to_file(void)
{
	if(count_of_fields_2bd == 0)
	{
		printf("\nNothing to save");
		return;
	}
	
	FILE *file_ptr = fopen("files/saves/database2w.txt", "w");
	file_err(file_ptr);
	
	for(int i = 0; i < count_of_fields_2bd - 1; i++)
	{
		fprintf(file_ptr, "%d_%s_%d_%d_%d\n", data_base_2[i].id, data_base_2[i].name, data_base_2[i].year, data_base_2[i].month, data_base_2[i].day);
	}
	// if in end of file will be space it broken prog, fix it
	fprintf(file_ptr, "%d_%s_%d_%d_%d", data_base_2[count_of_fields_2bd - 1].id, data_base_2[count_of_fields_2bd - 1].name, data_base_2[count_of_fields_2bd - 1].year, data_base_2[count_of_fields_2bd - 1].month, data_base_2[count_of_fields_2bd - 1].day);
	printf("\nSave successfully into file!\n");
	fclose(file_ptr);
	system("pause");
}

void print_console_2db(void)
{
	for(int i = 0; i < count_of_fields_2bd; i++)
	{
		printf("ID[%3d]\tName:%30s\tDate:%4d %2d %3d\tUdata:%d\n", data_base_2[i].id, data_base_2[i].name, data_base_2[i].year, data_base_2[i].month + 1, data_base_2[i].day, data_base_2[i].global_date_days);
	}
}


