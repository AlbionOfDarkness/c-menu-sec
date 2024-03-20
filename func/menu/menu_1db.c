#include "../../header.h"

void print_struct_menu_1db_0(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t   1. ADD student to DataBase");
	printf("\n\t   2. Delete student by ID from DataBase");
	printf("\n\t   3. Delete student by NAME from DataBase");
	printf("\n\t   4. LOAD DataBase from file");
	printf("\n\t   5. SAVE DataBase from file");
	printf("\n\t   6. WATCH DataBase");
	printf("\n\t   Esc. to back to struct menu");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}
void print_struct_menu_1db_1(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t>>>1. ADD student to DataBase");
	printf("\n\t   2. Delete student by ID from DataBase");
	printf("\n\t   3. Delete student by NAME from DataBase");
	printf("\n\t   4. LOAD DataBase from file");
	printf("\n\t   5. SAVE DataBase from file");
	printf("\n\t   6. WATCH DataBase");
	printf("\n\t   Esc. to back to struct menu");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}
void print_struct_menu_1db_2(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t   1. ADD student to DataBase");
	printf("\n\t>>>2. Delete student by ID from DataBase");
	printf("\n\t   3. Delete student by NAME from DataBase");
	printf("\n\t   4. LOAD DataBase from file");
	printf("\n\t   5. SAVE DataBase from file");
	printf("\n\t   6. WATCH DataBase");
	printf("\n\t   Esc. to back to struct menu");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}
void print_struct_menu_1db_3(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t   1. ADD student to DataBase");
	printf("\n\t   2. Delete student by ID from DataBase");
	printf("\n\t>>>3. Delete student by NAME from DataBase");
	printf("\n\t   4. LOAD DataBase from file");
	printf("\n\t   5. SAVE DataBase from file");
	printf("\n\t   6. WATCH DataBase");
	printf("\n\t   Esc. to back to struct menu");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}
void print_struct_menu_1db_4(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t   1. ADD student to DataBase");
	printf("\n\t   2. Delete student by ID from DataBase");
	printf("\n\t   3. Delete student by NAME from DataBase");
	printf("\n\t>>>4. LOAD DataBase from file");
	printf("\n\t   5. SAVE DataBase from file");
	printf("\n\t   6. WATCH DataBase");
	printf("\n\t   Esc. to back to struct menu");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}
void print_struct_menu_1db_5(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t   1. ADD student to DataBase");
	printf("\n\t   2. Delete student by ID from DataBase");
	printf("\n\t   3. Delete student by NAME from DataBase");
	printf("\n\t   4. LOAD DataBase from file");
	printf("\n\t>>>5. SAVE DataBase from file");
	printf("\n\t   6. WATCH DataBase");
	printf("\n\t   Esc. to back to struct menu");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}
void print_struct_menu_1db_6(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t   1. ADD student to DataBase");
	printf("\n\t   2. Delete student by ID from DataBase");
	printf("\n\t   3. Delete student by NAME from DataBase");
	printf("\n\t   4. LOAD DataBase from file");
	printf("\n\t   5. SAVE DataBase from file");
	printf("\n\t>>>6. WATCH DataBase");
	printf("\n\t   Esc. to back to struct menu");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}
void print_struct_menu_1db_7_esc(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t   1. ADD student to DataBase");
	printf("\n\t   2. Delete student by ID from DataBase");
	printf("\n\t   3. Delete student by NAME from DataBase");
	printf("\n\t   4. LOAD DataBase from file");
	printf("\n\t   5. SAVE DataBase from file");
	printf("\n\t   6. WATCH DataBase");
	printf("\n\t>>>Esc. to back to struct menu");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}


void menu_structs_1_db(void)
{
	char input_c_structs_1db;
	int choice_structs_1db = 0;
	
	while(1)
	{
		switch(choice_structs_1db)
		{
			case 0: 
				print_struct_menu_1db_0();
				break;
			case 1:
				print_struct_menu_1db_1();
				break;
			case 2:
				print_struct_menu_1db_2();
				break;
			case 3:
				print_struct_menu_1db_3();
				break;
			case 4:
				print_struct_menu_1db_4();
				break;
			case 5:
				print_struct_menu_1db_5();
				break;
			case 6:
				print_struct_menu_1db_6();
				break;
			case 7:
				print_struct_menu_1db_7_esc();
				break;
			default: 
				print_struct_menu_1db_0();
				break;
		}
		
		
		input_c_structs_1db = getch();
		
		switch(input_c_structs_1db)
		{
			case '1':
				system("cls");
				add_student_to_1bd();
				break;
			case '2':
				system("cls");
				delete_student_by_id();
				system("pause");
				break;
			case '3':
				system("cls");
				delete_student_by_name();
				system("pause");
				break;
			case '4':
				system("cls");
				take_1db_from_file();
				break;
			case '5':
				system("cls");
				save_1db_to_file();
				break;
			case '6':
				system("cls");
				print_console_1db();
				system("pause");
				break;
			case 27:
				system("cls");
				menu_structs();
				break;
			case '.':
				system("cls");
				choice_structs_1db = choice_scroll_structs_1db(choice_structs_1db, +1);
				break;
			case ',':
				system("cls");
				choice_structs_1db = choice_scroll_structs_1db(choice_structs_1db, -1);
				break;
			case 32:
				system("cls");
				choice_entre_structs_1db(choice_structs_1db);
				break;
			default: 
				wrong_button();
				break;
				
		}
		
		system("cls");
	}
}

int choice_scroll_structs_1db(int choice, int diff)
{
	if((choice + diff) > 7) return 1;
	if((choice + diff) < 1) return 7;
	return choice + diff;
}

void choice_entre_structs_1db(int choice)
{
	switch(choice)
		{
			case 1:
				system("cls");
				add_student_to_1bd();
				break;
			case 2:
				system("cls");
				delete_student_by_id();
				system("pause");
				break;
			case 3:
				system("cls");
				delete_student_by_name();
				system("pause");
				break;
			case 4:
				system("cls");
				take_1db_from_file();
				break;
			case 5:
				system("cls");
				save_1db_to_file();
				break;
			case 6:
				system("cls");
				print_console_1db();
				system("pause");
				break;
			case 7:
				system("cls");
				menu_structs();
				break;
			default:
				print_struct_menu_1db_0();
				break;
		}
}