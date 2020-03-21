# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/global_variables.h"
# include "../lib/headers/style.h"
# include "../lib/headers/command.h"
# include "../lib/headers/input.h"



int
history(char **command,
        char **options,
        char **direction)
{
	char *shell_history = getenv( "HOME" );
	if (!strstr(shell_history, "/.my_history"))
	{
		strcat(shell_history, "/.my_history");
	}

	FILE *file_history = fopen(shell_history, "r");
	if (file_history == NULL)
	{
		fprintf(stderr, "bash: can't find 'history' file\n");
		return 2;
	}

	for (register unsigned int i = 1 ;; i++)
	{
		char history[ HISTORY_LIMIT ];

		if (fscanf(file_history, " %[^\n]%*c", history) != EOF)
		{
			printf("%5d  %s\n", i, history);
		}
		else
		{
			fclose( file_history );
			return 1;
		}
	}
}
