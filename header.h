#define _USE_MATH_DEFINES
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void prog_10_1(void);
void prog_10_2(void);

void prog_16_1(void);
void prog_16_2(void);


int file_err(FILE *file);
int ptr_err(void *ptr);
int ptr_err_adv(void *ptr, char *str);
int check_for_space(char *str);
void log_p(char *str);
void print_array(int *arr, int n, char *str);
int find_max_arr(int *arr, int n);
void swap(int *a, int *b);
int find_mediana(int *arr, int n);

char* reverse_words_str(char* str);

char* add_num_to_str(char *str);


char** take_strs_file_to_2d_arr(FILE *fp);
void write_strs_to_file(FILE *fp, char** arr_2d);
void printf_2d_arr(char** arr, int n);
char** edit_2d_mas(char **arr_2d);
void free_2d_arr(char **arr_2d);

void hello_its_my_menu(void);
void menu(void);
void exit_menu(void);
void wrong_button(void);
void worked_in_progress(void);

int choice_scroll_menu(int choice, int diff);
void choice_entre_menu(int choice);
void print_menu_0(void);
void print_menu_1(void);
void print_menu_2(void);
void print_menu_3(void);
void print_menu_4(void);
void print_menu_5(void);
void print_menu_6(void);
void print_menu_7(void);
void print_menu_8(void);
void print_menu_9(void);
void print_menu_10(void);

void menu_files(void);
int choice_scroll_file(int choice, int diff);
void choice_entre_file(int choice);
void f_menu(void);
void f_1_menu(void);
void f_2_menu(void);
void f_3_menu(void);
void f_4_menu(void);
void f_esc_menu(void);


void menu_structs(void);
struct student_info;
int choice_scroll_structs(int choice, int diff);
void choice_entre_structs(int choice);
void print_struct_menu_0(void);
void print_struct_menu_1(void);
void print_struct_menu_2(void);
void print_struct_menu_3(void);

void menu_structs_1_db(void);
int choice_scroll_structs_1db(int choice, int diff);
void choice_entre_structs_1db(int choice);
void print_struct_1db_menu_0(void);

void add_student_to_1bd(void);
void print_console_1db(void);
void save_1db_to_file(void);
void take_1db_from_file(void);
void delete_student_by_name(void);
void delete_student_by_id(void);

void snif_data_base_from(unsigned int id_for_del, int count_of_field);
int find_student_by_name(char name[255], int count_of_field);
void take_data_to_fild_student_from_file(int id, char *str);

void menu_structs_2_db(void);
void choice_entre_structs_2db(int choice);

void print_struct_menu_2db_0(void);
void print_struct_menu_2db_1(void);
void print_struct_menu_2db_2(void);
void print_struct_menu_2db_3(void);
void print_struct_menu_2db_4(void);
void print_struct_menu_2db_5(void);
void print_struct_menu_2db_6(void);
void print_struct_menu_2db_7_esc(void);

struct history_event;
int calculate_universal_date(int id);
void snif_data_base_from_for2bd(unsigned int id_for_del, int count_of_field);


void add_history_to_2bd(void);
void delete_history_by_id(void);
void difference_history_by_id(void);
void take_2db_from_file(void);
void save_2db_to_file(void);
void print_console_2db(void);

void input_name_2bd(int id);
void input_year_2bd(int id);
void input_month_2bd(int id);
void input_day_2bd(int id);
void fast_input_2bd(int id);
void take_data_to_fild_history_from_file(int id, char *str);

void menu_sorts(void);
void srt_menu_0(void);
void srt_menu_1(void);
void srt_menu_2(void);
void srt_menu_3(void);
void srt_menu_4(void);
void srt_menu_5(void);
void srt_menu_6(void);
void srt_menu_7(void);
void srt_menu_8_esc(void);

int choice_scroll_sort(int choice, int diff);
void choice_entre_sort(int choice);

int* selection_sort_lowToup(int *arr, int n);
int *bubble_sort_lowToup(int *arr, int n);
double* selection_sort_lowToup_modData(double *arr, int n);
int* insertion_sort_lowToup_modData(int *arr, int n);
void insertion_sort_lowToup_modData_sname(int n);
int partition(int *arr, int left, int right);
void quick_sort(int *arr, int left, int right);
int *shell_sort(int *arr, int n);
int* count_sort(int *arr, int n);

FILE* matrix_choice_file(void);
int** create_matrix(int col, int size);
void print_matrix(int **matrix, int col, int size, char* str);
int** sort_matrix_1(int** matrix, int col, int size);
void matrix_sort_1(void);

void matrix_sort_2(void);
void choose_option_matrix_2(int** matrix, int col, int size);
void sort_matrix_2_main(int** matrix, int col, int size);
void sort_matrix_2_side(int** matrix, int col, int size);
int **sort_main_upTolow(int** matrix, int col, int size);
int **sort_side_upTolow(int** matrix, int col, int size);

struct MyStudents
{
	int group;
	char s_name[30];
	char f_name[30];
	char t_name[30];
	int date;
	int* marks;
	int count_marks;
} *data;
int count_of_fields;
int id_for_std;

void take_data_sort_from_file(void);
void take_data_to_fild_mystudent_from_file(int id, char *str);
void write_data_to_file(void);

void sort_data_1(void);

void data_sort_1(void);
void data_sort_2(void);

void count_sort_menu(void);
void quick_sort_menu(void);
void shell_sort_menu(void);




