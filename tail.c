# include "./headers/include.h"
# include "./headers/define.h"
# include "./headers/global_variables.h"
# include "./headers/style.h"
# include "./headers/command.h"
# include "./headers/input.h"



int
tail(char **command,
	 char **options,
	 char **direction)
{
	if (command[ 1 ] == NULL) {
		register unsigned line = 0;



		command[ 1 ] = "javeiros.txt";



		FILE *file_in = fopen(command[ 1 ], "w");

		if (file_in == NULL) {
			fprintf(stderr, "tail: cannot create '%s' file\n", command[ 1 ]);
			exit(EXIT_FAILURE);
		}



		while (1) {
			unsigned int position   = 0;
			unsigned int input_size = STRING_LIMIT;

			char *tail_input        = (char *) malloc(sizeof(char) * input_size);

			if (!tail_input) {
				fprintf(stderr, "bash: 'tail_input' allocation error\n");
				exit( EXIT_FAILURE );
			}



			while (1) {
				char character = getchar( );

				if (character == '\n') {
					tail_input[ position ] = '\0';

					if (strcmp(tail_input, "quit")) {
						fprintf(file_in, "%s\n", tail_input);

						line++;

						break;
					}

					fclose(file_in);

					goto print;
				}



				tail_input[ position++ ] = character;

				if (position >= input_size) {
					input_size += STRING_LIMIT;

					tail_input = realloc(tail_input, input_size);

					if (!tail_input) {
						fprintf(stderr, "bash: 'tail_input' allocation error\n");
						exit(EXIT_FAILURE);
					}
				}
			}
		}
	}

	print:

	for (register unsigned int i = 1; command[ i ] != NULL; ++i) {
		FILE *file_in = fopen(command[ i ], "r");

		if (file_in == NULL) {
			fprintf(stderr, "tail: cannot stat '%s': No such file or directory\n", command[ i ]);

			continue;
		}



		if (command[ 2 ] != NULL) {
			if (i > 1) {
				puts("");
			}

			printf("==> %s <==\n", command[ i ]);
		}



		unsigned int line_counter = 0;
		unsigned int j            = 0;

		char character;

		while ( fscanf(file_in, "%c", &character) != EOF )
		{
			if ( character == '\n' )
			{
				line_counter++;
			}
		}

		rewind( file_in );

		if (line_counter <= 10) {
			while (fscanf(file_in, "%c", &character) != EOF) {
				printf("%c", character);
			}
		} else {
			while (fscanf(file_in, "%c", &character) != EOF) {
				if (j >= line_counter - 10) {
					printf("%c", character);
				}

				if (character == '\n') {
					j++;
				}
			}
		}

		fclose( file_in );
	}



	if (!strcmp(command[ 1 ], "java_e_pra_viado.txt")) {
		if (remove(command[ 1 ])) {
			fprintf(stderr, "rm: cannot remove '%s': No such file or directory\n", command[ 1 ]);

			return 2;
		}
	}

	return 1;
}
