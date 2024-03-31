#include "../../header.h"

//struct MyStudents
//{
//	int group;
//	char s_name[30];
//	char f_name[30];
//	char t_name[30];
//	int date;
//	int* marks;
//	int count_marks;
//} *data;

int count_of_fields = 0;
int id_for_std = 0;


void take_data_sort_from_file(void)
{
	count_of_fields = 0;
	id_for_std = 0;
	data = (struct MyStudents*)calloc(0, sizeof(struct MyStudents));
	ptr_err_adv(data, "calloc_data_1");
			
	FILE *file_ptr = fopen("files/sort_data/datasort.txt", "r");
	file_err(file_ptr);
	log_p("Succesfuly_open_f");
	
	char buffer[127];
	while(feof(file_ptr) == 0)
	{
		fgets(buffer, 127, file_ptr);
		count_of_fields++;
		log_p("Succ: fgets(buffer, 127, file_ptr);");
		data = (struct MyStudents*)realloc(data, count_of_fields * sizeof(struct MyStudents));
		ptr_err_adv(data, "rcl_data_1");
		log_p("Succ: data = (struct MyStudents*)realloc(data, count_of_fields * sizeof(struct MyStudents));");
		
		take_data_to_fild_mystudent_from_file(id_for_std, buffer);
		id_for_std++;
		log_p("Succ: take_data_to_fild_mystudent_from_file(id_for_std, buffer);");
		
		log_p("Succ: end while");
	}

	
	printf("\nStruct arr succesfully taken from file!\n");
	
	fclose(file_ptr);
	system("pause");
}

void take_data_to_fild_mystudent_from_file(int id, char *str)
{	
	char *ptr_for_one_field =  strtok(str, "_");
	int tmp_num;
	tmp_num = atoi(ptr_for_one_field);
	data[id].group = tmp_num;
//	printf("\nS: data[%d].group{%d} = %d\n", id, data[id].group, tmp_num);
	
	ptr_for_one_field = strtok(NULL, "_");
	strcpy(data[id].s_name, ptr_for_one_field);
//	printf("\n%s", data[id].s_name);

	
	ptr_for_one_field = strtok(NULL, "_");
	strcpy(data[id].f_name, ptr_for_one_field);
	
	ptr_for_one_field = strtok(NULL, "_");
	strcpy(data[id].t_name, ptr_for_one_field);
	
	ptr_for_one_field = strtok(NULL, "_");
	tmp_num = atoi(ptr_for_one_field);
	data[id].date = tmp_num;
	
	data[id].count_marks = 5;

	data[id].marks = (int*)malloc(sizeof(int));
	data[id].marks = (int*)realloc(data[id].marks, data[id].count_marks * sizeof(int));
	ptr_err_adv(data[id].marks, "ptr_data1");

//	printf("\n");
	for(int i = 0; i < 5; i++)
	{
		log_p("Entre for");
		ptr_for_one_field = strtok(NULL, "_");
//		printf("\nINFOR:%s");
		data[id].marks[i] = atoi(ptr_for_one_field);
//		printf("%d ", data[id].marks[i]);
	}
}

double *arr_to_print;

void sort_data_1(void)
{
	double *mdiana_marks = (double*)malloc(0*sizeof(double));
	ptr_err_adv(mdiana_marks, "mllc1"); 
	for(int i = 0; i < count_of_fields; i++)
	{
		int mediana_tmp = 0;
		for(int j = 0; j < data[i].count_marks; j++)
		{
			mediana_tmp += data[i].marks[j];
		}
		mdiana_marks = (double*)realloc(mdiana_marks, (i + 1) * sizeof(double));
		ptr_err_adv(mdiana_marks, "rll123");
		mdiana_marks[i] = mediana_tmp / data[i].count_marks;
	}

	printf("\nStart sort");
	mdiana_marks = selection_sort_lowToup_modData(mdiana_marks, count_of_fields + 1);
	
	arr_to_print = (double*)calloc(count_of_fields, sizeof(double));
	ptr_err_adv(arr_to_print, "err_ptr_1111");
	
	memcpy(arr_to_print, mdiana_marks, count_of_fields * sizeof(double));

	
	printf("\nStruct Successfully sort");
}

void sort_data_2(void)
{
	int *tmp_arr = (int*)calloc(count_of_fields, sizeof(int));
	ptr_err_adv(tmp_arr, "sort_data_2_1");
	for(int i = 0; i < count_of_fields; i++)
	{
		tmp_arr[i] = data[i].group;
		printf("%d ", tmp_arr[i]);
	}
	
	printf("\nStart sort");
	tmp_arr = insertion_sort_lowToup_modData(tmp_arr, count_of_fields);
	
//	for(int i = 0; i < count_of_fields; i++)
//	{
//		printf(" %d", tmp_arr[i]);
//	}
	insertion_sort_lowToup_modData_sname(count_of_fields);
		
	printf("\nStruct Successfully sort");
}

void write_data_to_file(void)
{
	if(count_of_fields == 0)
	{
		printf("\nNothing to save");
		return;
	}
	
	FILE *file_ptr = fopen("files/sort_data/outdatasort.txt", "w");
	file_err(file_ptr);
	
	for(int i = 0; i < count_of_fields; i++)
	{
		fprintf(file_ptr, "%d_%s_%s_%s_%d_%d", data[i].group, data[i].s_name, data[i].f_name, data[i].t_name, data[i].date, data[i].count_marks);
		for(int j = 0; j < data[i].count_marks; j++)
		{
			fprintf(file_ptr,"_%d", data[i].marks[j]);
		}
		fprintf(file_ptr, "[%lf]", arr_to_print[i]);
		if(!(i > count_of_fields))
		{
			fprintf(file_ptr, "\n");
		}
	}
	printf("\nSave successfully into file!\n");
	fclose(file_ptr);
	system("pause");
}

void write_data_to_file_2(void)
{
	if(count_of_fields == 0)
	{
		printf("\nNothing to save");
		return;
	}
	
	FILE *file_ptr = fopen("files/sort_data/outdatasort2.txt", "w");
	file_err(file_ptr);
	
	for(int i = 0; i < count_of_fields; i++)
	{
		fprintf(file_ptr, "%d_%s_%s_%s_%d_%d", data[i].group, data[i].s_name, data[i].f_name, data[i].t_name, data[i].date, data[i].count_marks);
		for(int j = 0; j < data[i].count_marks; j++)
		{
			fprintf(file_ptr,"_%d", data[i].marks[j]);
		}
		if(!(i > count_of_fields))
		{
			fprintf(file_ptr, "\n");
		}
	}
	printf("\nSave successfully into file!\n");
	fclose(file_ptr);
	system("pause");
}

void data_sort_1(void)
{
	take_data_sort_from_file();
	sort_data_1();
	write_data_to_file();
}

void data_sort_2(void)
{
	take_data_sort_from_file();
	sort_data_2();
	write_data_to_file_2();
}
