# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/global_variables.h"
# include "../lib/headers/style.h"
# include "../lib/headers/command.h"
# include "../lib/headers/input.h"



int
rm_dir(char **command,
       char **options,
       char **direction)
{
	if (command[ 1 ] == NULL)
	{
		fprintf(stderr, "rmdir: missing operand\n");
		puts("Try 'help rmdir' for more information.");
		return 2;
	}
	for (register unsigned int i = 0; options[ i ] != NULL; i++)
	{
	}
	// for (register unsigned int i = 0; direction[ i ] != NULL; i++)
	// {
	// }

	for (register unsigned int i = 1; command[ i ] != NULL; i++)
	{
		if (rmdir(command[ i ]))
		{
			fprintf(stderr, "rmdir: failed to remove '%s': Directory not empty\n", command[ i ]);
			return 2;
		}
	}

	return 1;
}
