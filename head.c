# include "./headers/include.h"
# include "./headers/define.h"
# include "./headers/global_variables.h"
# include "./headers/style.h"
# include "./headers/command.h"
# include "./headers/input.h"



int
head(char **command,
     char **options,
     char **direction)
{
	if (command[ 1 ] == NULL)
	{
		unsigned int line = 1;

		while (true)
		{
			unsigned int  input_size = STRING_LIMIT;
			unsigned int  position   = 0;

			char         *tail_input = (char *) malloc(sizeof(char) * input_size);

			if (!tail_input)
			{
				fprintf(stderr, "bash: 'tail_input' allocation error\n");
				exit(EXIT_FAILURE);
			}

			while (true)
			{
				char character = getchar( );
				if (character == '\n')
				{
					tail_input[ position ] = '\0';
					if (!strcmp(tail_input, "quit") || line == 10)
					{
						printf("%s\n", tail_input);
						return 1;
					}
					printf("%s\n", tail_input);
					line++;
					break;
				}

				tail_input[ position++ ] = character;
				if (position >= input_size)
				{
					input_size += STRING_LIMIT;

					tail_input = realloc(tail_input, input_size);
					if (!tail_input)
					{
						fprintf(stderr, "bash: 'tail_input' allocation error\n");
						exit(EXIT_FAILURE);
					}
				}
			}
		}
	}

	for (register unsigned int i = 1; command[ i ] != NULL; ++i)
	{
		FILE *file_in = fopen(command[ i ], "r");
		if (file_in == NULL)
		{
			fprintf(stderr, "head: %s: No such file or directory\n", command[ i ]);
			continue;
		}

		if ( command[ 2 ] != NULL )
		{
			if ( i > 1 )
			{
				puts("");
			}
			printf("==> %s <==\n", command[ i ]);
		}

		register unsigned int enter_counter = 0;

		char                  character;

		while (enter_counter < 10 && fscanf(file_in, "%c", &character) != EOF)
		{
			if (character == '\n')
			{
				enter_counter++;
			}
			printf("%c", character);
		}
		fclose( file_in );
	}

	return 1;
}
