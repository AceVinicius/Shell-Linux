# include "./headers/include.h"
# include "./headers/define.h"
# include "./headers/global_variables.h"
# include "./headers/style.h"
# include "./headers/command.h"
# include "./headers/input.h"



int
cat(char **command,
	char **options,
	char **direction)
{
	if (command[ 1 ] == NULL)
	{
		while (1)
		{
			unsigned int  position   = 0;
			unsigned int  input_size = STRING_LIMIT;

			char         *cat_input  = (char *) malloc(sizeof(char) * input_size);

			if (!cat_input)
			{
				fprintf(stderr, "bash: 'cat_input' allocation error\n");
				exit(EXIT_FAILURE);
			}

			while (1)
			{
				int character = getchar();
				if (character == '\n')
				{
					cat_input[ position ] = '\0';
					if (strcmp(cat_input, "quit"))
					{
						printf("%s\n", cat_input);
						break;
					}
					return 1;
				}
				cat_input[ position++ ] = character;
				if (position >= input_size)
				{
					input_size += STRING_LIMIT;
					cat_input = realloc(cat_input, input_size);
					if (!cat_input)
					{
						fprintf(stderr, "bash: 'cat_input' allocation error\n");
						exit(EXIT_FAILURE);
					}
				}
			}
		}
	}

	for (register unsigned int i = 1; command[ i ] != NULL; ++i)
	{
		FILE *in = fopen(command[ i ], "r");
		if (in == NULL)
		{
			fprintf(stderr, "cat: %s: No such file or directory\n", command[ i ]);
			continue;
		}
		char character;
		while (fscanf(in, "%c", &character) != EOF)
		{
			printf("%c", character);
		}
		fclose(in);
	}
	return 1;
}
