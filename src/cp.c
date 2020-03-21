# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/global_variables.h"
# include "../lib/headers/style.h"
# include "../lib/headers/command.h"
# include "../lib/headers/input.h"



int
cp(char **command,
   char **options,
   char **direction)
{
	if (command[ 1 ] == NULL)
	{
		fprintf(stderr, "cp: missing file operand\n");
		puts("Try 'help cp' for more information.");
		return 2;
	}
	if (command[ 2 ] == NULL)
	{
		fprintf(stderr, "cp: missing destination file operand after '%s'\n", command[ 1 ]);
		puts("Try 'help cp' for more information.");
		return 2;
	}

	char character;

	FILE *in = fopen(command[ 1 ], "r");
	DIR *dp = NULL;
	if (in == NULL)
	{
		fprintf(stderr, "cp: cannot stat '%s': No such file or directory\n", command[ 1 ]);
		return 2;
	}
	if ((dp = opendir(command[ 2 ])) != NULL)
	{
		closedir(dp);
		strcat(command[ 2 ], command[ 1 ]);
	}

	FILE *out = fopen(command[ 2 ], "w");
	if (out == NULL)
	{
		fprintf(stderr, "bash: cannot create '%s' file\n", command[ 2 ]);
		exit(EXIT_FAILURE);
	}
	while (fscanf(in, "%c", &character) != EOF)
	{
		fprintf(out, "%c", character);
	}

	fclose(in);
	fclose(out);
	return 1;
}
