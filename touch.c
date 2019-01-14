# include "./headers/include.h"
# include "./headers/define.h"
# include "./headers/global_variables.h"
# include "./headers/style.h"
# include "./headers/command.h"
# include "./headers/input.h"



int
touch(char **command,
      char **options,
      char **direction)
{
	if (command[ 1 ] == NULL)
	{
		fprintf(stderr, "touch: missing file operand\n");
		puts("Try 'help touch' for more information.");
		return 2;
	}

	for (register unsigned int i = 1; command[ i ] != NULL; i++)
	{
		FILE *file_new = fopen(command[ i ], "w");
		fclose(file_new);
	}

	return 1;
}
