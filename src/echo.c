# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/global_variables.h"
# include "../lib/headers/style.h"
# include "../lib/headers/command.h"
# include "../lib/headers/input.h"



int
echo(char **command,
     char **options,
     char **direction)
{
	if (command[ 1 ] == NULL)
	{
		puts("");
		return 1;
	}

	printf("%s", command[ 1 ]);
	for (register unsigned int i = 2; command[ i ] != NULL; i++)
	{
		printf(" %s", command[ i ]);
	}
	puts("");

	return 1;
}
