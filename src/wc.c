# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/global_variables.h"
# include "../lib/headers/style.h"
# include "../lib/headers/command.h"
# include "../lib/headers/input.h"



typedef struct
{
	char *file;

	unsigned int character_counter;
	unsigned int line_counter;
	unsigned int word_counter;
} counter_store;



int
wc(char **command,
   char **options,
   char **direction)
{
	counter_store file[ 128 ];

	unsigned int character_total = 0;
	unsigned int line_total      = 0;
	unsigned int word_total      = 0;
	unsigned int size;

	bool         character       = false;
	bool         line            = false;
	bool         word            = false;

	char         character_read;

	for (register unsigned int i = 0; options[ i ] != NULL; ++i)
	{
		if (!strcmp(options[ i ], "-m"))
		{
			character = true;
		}
		else if (!strcmp(options[ i ], "-w"))
		{
			word = true;
		}
		else if(!strcmp(options[ i ], "-l"))
		{
			line = true;
		}
	}

	if (command[ 1 ] == NULL)
	{
		command[ 1 ] = "javeiros.txt";

		FILE *file_in = fopen(command[ 1 ], "w");
		if (file_in == NULL)
		{
			fprintf(stderr, "wc: cannot create '%s' file\n", command[ 1 ]);
			exit(EXIT_FAILURE);
		}

		while (true)
		{
			unsigned int  position   = 0;
			unsigned int  input_size = STRING_LIMIT;

			char         *wc_input   = (char *) malloc(sizeof(char) * input_size);

			if (!wc_input)
			{
				fprintf(stderr, "bash: 'wc_input' allocation error\n");
				exit(EXIT_FAILURE);
			}

			while (true)
			{
				char character = getchar( );
				if (character == '\n')
				{
					wc_input[ position ] = '\0';
					if (strcmp(wc_input, "quit"))
					{
						fprintf(file_in, "%s\n", wc_input);
						break;
					}
					fclose(file_in);
					goto print;
				}
				wc_input[ position++ ] = character;

				if (position >= input_size)
				{
					input_size += STRING_LIMIT;

					wc_input    = realloc(wc_input, input_size);
					if (!wc_input)
					{
						fprintf(stderr, "bash: 'wc_input' allocation error\n");
						exit(EXIT_FAILURE);
					}
				}
			}
		}
	}
print:

	for (register unsigned int i = 1; command[ i ] != NULL; ++i)
	{
		FILE *in = fopen(command[ i ], "r");
		if (in == NULL)
		{
			file[ i-1 ].file = NULL;
			continue;
		}

		file[ i-1 ].file              = command[ i ];
		file[ i-1 ].character_counter = 0;
		file[ i-1 ].line_counter      = 0;
		file[ i-1 ].word_counter      = 0;

		while (fscanf(in, "%c", &character_read) != EOF)
		{
			char last;
			if (character_read == '\n')
			{
				file[ i-1 ].line_counter++;
			}
			if (isspace(character_read) && !isspace(last))
			{
				file[ i-1 ].word_counter++;
			}
			file[ i-1 ].character_counter++;
			last = character_read;
		}
		fclose(in);

		character_total += file[ i-1 ].character_counter;
		line_total      += file[ i-1 ].line_counter;
		word_total      += file[ i-1 ].word_counter;
	}

	if (!strcmp(command[ 1 ], "javeiros.txt"))
	{
		char **transition = NULL;
		rm(command, transition, transition);

		size = 7;

		if (line)
		{
			printf("%*u", size + 1, file[ 0 ].line_counter);
		}
		if (word)
		{
			printf(" %*u", size + 1, file[ 0 ].word_counter);
		}
		if (character)
		{
			printf(" %*u", size + 1, file[ 0 ].character_counter);
		}
		if (!line &&
		    !word &&
		    !character)
		{
			printf("%*u",  size + 1, file[ 0 ].line_counter);
			printf(" %*u", size + 1, file[ 0 ].word_counter);
			printf(" %*u", size + 1, file[ 0 ].character_counter);
		}

		puts("");
	}
	else
	{
		unsigned int times = 0;

		size = log10(character_total);

		for (register unsigned int i = 0; command[ i+1 ] != NULL; ++i)
		{
			if (file[ i ].file == NULL)
			{
				fprintf(stderr, "wc: %s: No such file or directory\n", command[ i+1 ]);
				continue;
			}

			if(line)
			{
				printf("%*u", size + 1, file[ i ].line_counter);
			}

			if(word)
			{
				printf(" %*u", size + 1, file[ i ].word_counter);
			}

			if(character)
			{
				printf(" %*u", size + 1, file[ i ].character_counter);
			}

			if (!line &&
			    !word &&
			    !character)
			{
				printf("%*u",  size + 1, file[ i ].line_counter);
				printf(" %*u", size + 1, file[ i ].word_counter);
				printf(" %*u", size + 1, file[ i ].character_counter);
			}

			printf(" %s\n", file[ i ].file);
			times++;
		}

		if (times >= 2)
		{
			if (line)
			{
				printf("%*u", size + 1, line_total);
			}
			if (word)
			{
				printf(" %*u", size + 1, word_total);
			}
			if (character)
			{
				printf(" %*u", size + 1, character_total);
			}
			if (!line &&
			    !word &&
			    !character)
			{
				printf("%*u", size + 1, line_total);
				printf(" %*u", size + 1, word_total);
				printf(" %*u", size + 1, character_total);
			}
			puts(" total");
		}
	}

	return 1;
}
