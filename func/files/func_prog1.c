#include "../../header.h"

void prog_10_1(void)
{
	FILE *file;
	char buffer[128];
	
	file = fopen("files/for_1.txt", "r");
	file_err(file);
	
	printf("\n\n");
	int flag;
	while(feof(file) == 0)
	{
		fgets(buffer, 127, file);
		if (check_for_space(buffer) == 1)
		{
			printf("%s", buffer);
		}
	}
	
	
    fclose(file);
    
    printf("\nALL DONE WATCH UPPER\n");
	system("pause");
}