# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/global_variables.h"
# include "../lib/headers/style.h"
# include "../lib/headers/command.h"
# include "../lib/headers/input.h"



int
diff(char **command,
     char **options,
     char **direction)
{
	if (command[ 1 ] == NULL)
	{
		fprintf(stderr, "diff: missing file operand\n");
		puts("Try 'help diff' for more information.");
		return 2;
	}

	FILE *file_in_1 = fopen(command[ 1 ], "r");
	FILE *file_in_2 = fopen(command[ 2 ], "r");
	if (file_in_1 == NULL)
	{
		fprintf(stderr, "diff: cannot stat '%s': No such file or directory\n", command[ 1 ]);
		if (file_in_2 == NULL)
		{
			fprintf(stderr, "diff: cannot stat '%s': No such file or directory\n", command[ 2 ]);
		}
		return 2;
	}
	if (file_in_2 == NULL)
	{
		fprintf(stderr, "diff: cannot stat '%s': No such file or directory\n", command[ 2 ]);
		return 2;
	}

	char file_line_1[ STRING_LIMIT ];
	char file_line_2[ STRING_LIMIT ];
	for (register unsigned int i = 0; ; ++i)
	{
		int one = fscanf(file_in_1, " %[^\n]%*c", file_line_1);
		int two = fscanf(file_in_2, " %[^\n]%*c", file_line_2);
		if (one == EOF || two == EOF)
		{
			break;
		}
		if (strcmp(file_line_1, file_line_2))
		{
			printf("%dc%d\n", i, i);
			printf("< %s\n", file_line_1);
			printf("---\n");
			printf("> %s\n", file_line_2);
		}
	}

	fclose(file_in_1);
	fclose(file_in_2);
	return 1;
}
