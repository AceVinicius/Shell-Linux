# include "./headers/include.h"
# include "./headers/define.h"
# include "./headers/global_variables.h"
# include "./headers/style.h"
# include "./headers/command.h"
# include "./headers/input.h"



int
mv(char **command,
   char **options,
   char **direction)
{
	if (command[ 1 ] == NULL)
	{
		fprintf(stderr, "mv: missing file operand\n");
		puts("Try 'help mv' for more information.");
		return 2;
	}
	if (command[ 2 ] == NULL)
	{
		fprintf(stderr, "mv: missing destination file operand after '%s'\n", command[ 1 ]);
		puts("Try 'help mv' for more information.");
		return 2;
	}

	char character;

	DIR *dp = NULL;
	FILE *in = fopen(command[ 1 ], "r");
	if (command[ 3 ] != NULL)
	{
		if ((dp = opendir(command[ 3 ])) != NULL)
		{
			closedir(dp);
			strcat(command[ 3 ], command[ 2 ]);
		}
		FILE *out = fopen(command[ 3 ], "w");
		while (fscanf(in, "%c", &character) != EOF)
		{
			fprintf(out, "%c", character);
		}
		if (remove(command[ 1 ]))
		{
			fprintf(stderr, "rm: cannot remove '%s': No such file or directory\n", command[ 1 ]);
			return 2;
		}

		return 1;
	}

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
	while (fscanf(in, "%c", &character) != EOF)
	{
		fprintf(out, "%c", character);
	}

	if (remove(command[ 1 ]))
	{
		fprintf(stderr, "rm: cannot remove '%s': No such file or directory\n", command[ 1 ]);
		return 2;
	}

	fclose( in );
	fclose( out );
	return 1;
}
