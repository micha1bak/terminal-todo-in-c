#include <stdio.h>
#include <string.h>
#include "lib/todo.h"

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		read_todos_from_file(argv[1]);
	}
	int driver = 1;
	while (driver)
	{
		int temp_id = 0;
		char temp_name[250];
		int temp_priority = 0;
		display_todos();
		if (scanf("%d", &driver) != 1)
		{
			printf("Invalid input! Please enter a number.\n");
			while (getchar() != '\n');
			continue;
		}
		while (getchar() != '\n');
		switch (driver)
		{
			case 1:
				printf("Set a todo discription\n>> ");
				if (fgets(temp_name, sizeof(temp_name), stdin) == NULL)
				{
					printf("Error reading input.\n");
					break;
				}
				temp_name[strcspn(temp_name, "\n")] = '\0';
				printf("Set priority ( 1 - low, 2 - medium, 3 - high)\n>> ");
				scanf("%d", &temp_priority);
				create_todo(todos_size, temp_name, temp_priority, false);
				if (argc > 1)
				{
					save_todos_to_file(argv[1]);
				}
				break;
			case 2:
				int prop = 0;
				printf("Enter id:\n>> ");
				scanf("%d", &temp_id);
				while (getchar() != '\n');
				printf("Actions:\n1. Complete | 2. Priority\n>>");
				scanf("%d", &prop);
				update_todo(temp_id, prop);
				if (argc > 1)
				{
					save_todos_to_file(argv[1]);
				}
				break;
			case 3:
				printf("Enter id:\n>> ");
				scanf("%d", &temp_id);
				while (getchar() != '\n');
				delete_todo(temp_id);
				if (argc > 1)
				{
					save_todos_to_file(argv[1]);
				}
				break;
			case 4:
				driver = 0;
				break;
			default:
				printf("Invalid input! Please enter a number.\n");
		}
	}
	return 0;
}
