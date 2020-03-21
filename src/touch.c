# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/global_variables.h"
# include "../lib/headers/style.h"
# include "../lib/headers/command.h"
# include "../lib/headers/input.h"



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
