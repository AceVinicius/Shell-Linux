# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/global_variables.h"
# include "../lib/headers/style.h"
# include "../lib/headers/command.h"
# include "../lib/headers/input.h"



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
