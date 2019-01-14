# include "./headers/include.h"
# include "./headers/define.h"
# include "./headers/global_variables.h"
# include "./headers/style.h"
# include "./headers/command.h"
# include "./headers/input.h"



int
rm(char **command,
   char **options,
   char **direction)
{
	if (command[ 1 ] == NULL)
	{
		fprintf(stderr, "rm: missing operand\n");
		puts("Try 'help rm' for more information.");
		return 2;
	}

	for (register unsigned int i = 1; command[ i ] != NULL; ++i)
	{
		if (remove(command[ i ]))
		{
			fprintf(stderr, "rm: cannot remove '%s': No such file or directory\n", command[ 1 ]);
			return 2;
		}
	}

	return 1;
}
