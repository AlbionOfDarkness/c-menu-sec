#include "../../header.h"

void print_struct_menu_0(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t   1. Open FIRST psevdo-DataBase Menu");
	printf("\n\t   2. Open SECOND psevdo-DataBase Menu");
	printf("\n\t   Esc. to back to main menu");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}

void print_struct_menu_1(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t>>>1. Open FIRST psevdo-DataBase Menu");
	printf("\n\t   2. Open SECOND psevdo-DataBase Menu");
	printf("\n\t   Esc. to back to main menu");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}

void print_struct_menu_2(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t   1. Open FIRST psevdo-DataBase Menu");
	printf("\n\t>>>2. Open SECOND psevdo-DataBase Menu");
	printf("\n\t   Esc. to back to main menu");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}

void print_struct_menu_3(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t   1. Open FIRST psevdo-DataBase Menu");
	printf("\n\t   2. Open SECOND psevdo-DataBase Menu");
	printf("\n\t>>>Esc. to back to main menu");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}

int choice_scroll_structs(int choice, int diff)
{
	if((choice + diff) > 3) return 1;
	if((choice + diff) < 1) return 3;
	return choice + diff;
}


void choice_entre_structs(int choice)
{
	switch(choice)
		{
			case 1:
				system("cls");
				menu_structs_1_db();
				break;
			case 2:
				system("cls");
				menu_structs_2_db();
				break;
			case 3:
				system("cls");
				menu();
				break;
			default:
				print_struct_menu_0();
				break;
		}
}

void menu_structs(void)
{
	char input_c_structs;
	int choice_structs = 0;
	
	while(1)
	{
		switch(choice_structs)
		{
			case 0: 
				print_struct_menu_0();
				break;
			case 1:
				print_struct_menu_1();
				break;
			case 2:
				print_struct_menu_2();
				break;
			case 3:
				print_struct_menu_3();
				break;
			default: 
				print_struct_menu_0();
				break;
		}
		
		
		input_c_structs = getch();
		
		switch(input_c_structs)
		{
			case '1':
				system("cls");
				menu_structs_1_db();
				break;
			case '2':
				system("cls");
				menu_structs_2_db();
				break;
			case '3':
				system("cls");
				menu();
				break;
			case 27:
				system("cls");
				menu();
				break;
			case '.':
				system("cls");
				choice_structs = choice_scroll_structs(choice_structs, +1);
				break;
			case ',':
				system("cls");
				choice_structs = choice_scroll_structs(choice_structs, -1);
				break;
			case 32:
				system("cls");
				choice_entre_structs(choice_structs);
				break;
			default: 
				wrong_button();
				break;
				
		}
		
		system("cls");
	}
}