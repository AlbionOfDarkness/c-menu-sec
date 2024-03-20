#include "../../header.h"



void f_menu(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t   1. Variant 10 Programm 1");
	printf("\n\t   2. Variant 10 Programm 2");
	printf("\n\t   3. Variant 16 Programm 1");
	printf("\n\t   4. Variant 16 Programm 2");
	printf("\n\t   Esc. to close program");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}

void f_1_menu(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t>>>1. Variant 10 Programm 1<<<");
	printf("\n\t   2. Variant 10 Programm 2");
	printf("\n\t   3. Variant 16 Programm 1");
	printf("\n\t   4. Variant 16 Programm 2");
	printf("\n\t   Esc. to close program");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}

void f_2_menu(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t   1. Variant 10 Programm 1");
	printf("\n\t>>>2. Variant 10 Programm 2<<<");
	printf("\n\t   3. Variant 16 Programm 1");
	printf("\n\t   4. Variant 16 Programm 2");
	printf("\n\t   Esc. to close program");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}

void f_3_menu(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t   1. Variant 10 Programm 1");
	printf("\n\t   2. Variant 10 Programm 2");
	printf("\n\t>>>3. Variant 16 Programm 1<<<");
	printf("\n\t   4. Variant 16 Programm 2");
	printf("\n\t   Esc. to close program");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}

void f_4_menu(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t   1. Variant 10 Programm 1");
	printf("\n\t   2. Variant 10 Programm 2");
	printf("\n\t   3. Variant 16 Programm 1");
	printf("\n\t>>>4. Variant 16 Programm 2<<<");
	printf("\n\t   Esc. to close program");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}

void f_esc_menu(void)
{
	system("cls");
	printf("\nThere are are the options that are bottom of this message:");
	
	printf("\n\t   1. Variant 10 Programm 1");
	printf("\n\t   2. Variant 10 Programm 2");
	printf("\n\t   3. Variant 16 Programm 1");
	printf("\n\t   4. Variant 16 Programm 2");
	printf("\n\t>>>Esc. to close program<<<");
	
	printf("\n\n\n\nYou can use '<' and '>' to navigation!");
	printf("\nPress SPACE to confirm choice");
}

int choice_scroll_file(int choice, int diff)
{
	if((choice + diff) > 5) return 1;
	if((choice + diff) < 1) return 5;
	return choice + diff;
}


void choice_entre_file(int choice)
{
	switch(choice)
		{
			case 1:
				system("cls");
				prog_10_1();
				break;
			case 2:
				system("cls");
				prog_10_2();
				break;
			case 3:
				system("cls");
				prog_16_1();
				break;
			case 4:
				system("cls");
				prog_16_2();
				break;
			case 5:
				system("cls");
				menu();
				break;
			default:
				f_menu();
		}
}

void menu_files(void)
{
	char input_c;
	int choice_file = 0;
	
	while(1)
	{
		switch(choice_file)
		{
			case 0: 
				f_menu();
				break;
			case 1:
				f_1_menu();
				break;
			case 2:
				f_2_menu();
				break;
			case 3:
				f_3_menu();
				break;
			case 4:
				f_4_menu();
				break;
			case 5:
				f_esc_menu();
				break;
			default: 
				f_menu();
				break;
		}
		
		
		input_c = getch();
		
		switch(input_c)
		{
			case '1':
				system("cls");
				prog_10_1();
				break;
			case '2':
				system("cls");
				prog_10_2();
				break;
			case '3':
				system("cls");
				prog_16_1();
				break;
			case '4':
				system("cls");
				prog_16_2();
				break;
			case 27:
				system("cls");
				menu();
				break;
			case '.':
				system("cls");
				choice_file = choice_scroll_file(choice_file, +1);
				break;
			case ',':
				system("cls");
				choice_file = choice_scroll_file(choice_file, -1);
				break;
			case 32:
				system("cls");
				choice_entre_file(choice_file);
				break;
			default: 
				wrong_button();
				break;
				
		}
		
		system("cls");
	}
}

