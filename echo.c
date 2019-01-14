# include "./headers/include.h"
# include "./headers/define.h"
# include "./headers/global_variables.h"
# include "./headers/style.h"
# include "./headers/command.h"
# include "./headers/input.h"



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
