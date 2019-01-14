/*
 * This function will separe the prompt line into tokens.
 * This tokens will be separed in three matrix:
 *
 *   commands  -> will store what the user wants to do;
 *   options   -> will store the parameters of the function;
 *   direction -> will store the way I/O will be processed.
 */
 # include "./headers/include.h"
 # include "./headers/define.h"
 # include "./headers/global_variables.h"
 # include "./headers/style.h"
 # include "./headers/command.h"
 # include "./headers/input.h"




char ***
parse_input(char *input)
{
	unsigned int token_size_commands  = TOKEN_LIMIT;
	unsigned int token_size_options   = TOKEN_LIMIT;
	unsigned int token_size_direction = TOKEN_LIMIT;
	unsigned int position_commands    = 0;
	unsigned int position_options     = 0;
	unsigned int position_direction   = 0;

	char ***transfer           = (char ***) malloc(sizeof(char **) * 3);
	char  **commands           = (char  **) malloc(sizeof(char  *) * token_size_commands);
	char  **options            = (char  **) malloc(sizeof(char  *) * token_size_options);
	char  **direction          = (char  **) malloc(sizeof(char  *) * token_size_direction);
	char   *file_shell_history = getenv("HOME");
	char   *token;
	/*
	 * Verifies if dynamic allocation was made with success
	 */
	if (!commands)
	{
		fprintf(stderr, "bash: 'commands' allocation error\n");
		exit(EXIT_FAILURE);
	}
	if (!options)
	{
		fprintf(stderr, "bash: 'options' allocation error\n");
		exit(EXIT_FAILURE);
	}
	if (!direction)
	{
		fprintf(stderr, "bash: 'direction' allocation error\n");
		exit(EXIT_FAILURE);
	}
	if (!transfer)
	{
		fprintf(stderr, "bash: 'transfer' allocation error\n");
		exit(EXIT_FAILURE);
	}
	/*
	 *  Open ./my_history file in home folder
	 */
	if (!strstr(file_shell_history, "/.my_history"))
	{
		strcat(file_shell_history, "/.my_history");
	}
	FILE *file_in_history = fopen(file_shell_history, "a");
	if (file_in_history == NULL)
	{
		fprintf(stderr, "bash: can't access 'history' file for append\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, WHITESPACE);
	/*
	 *  Organize tokens in matrix.
	 */
	while (token != NULL) {
		fprintf(file_in_history, "%s ", token);
		// if (strstr(token, ">"))
		// {
		// 	if (token == '>')
		// 	{
		// 		direction[ position_direction++ ]= ">";
		// 	}
		// 	else
		// 	{
		// 		direction[ position_direction++ ] = ">";
		// 		commands[ position_commands++ ] = token;
		// 		commands[ position_commands-1 ] = strtok(commands[ position_commands-1 ], ">");
		// 		token = strtok(direction[ position_direction ], ">");
		// 		direction[ position_direction++ ] = token;
		// 	}
		// 	if (position_direction >= token_size_direction)
		// 	{
		// 		token_size_direction += TOKEN_LIMIT;
        //
		// 		direction = realloc(direction, sizeof(char *) * token_size_direction);
		// 		if (!options)
		// 		{
		// 			fprintf(stderr, "bash: 'direction' reallocation error\n");
		// 			exit( EXIT_FAILURE );
		// 		}
		// 	}
		// }
		// else
		if (token[ 0 ] == '-')
		{
			options[ position_options++ ] = token;

			if (position_options >= token_size_options)
			{
				token_size_options += TOKEN_LIMIT;
				options = realloc(options, sizeof(char *) * token_size_options);
				if (!options)
				{
	 				fprintf(stderr, "bash: 'options' reallocation error\n");
	 				exit( EXIT_FAILURE );
	 			}
			}
		}
		else
		{
			commands[ position_commands++ ] = token;

			if (position_commands >= token_size_commands)
			{
				token_size_commands += TOKEN_LIMIT;
				commands = realloc(commands, sizeof(char *) * token_size_commands);
				if (!commands)
				{
	 				fprintf(stderr, "bash: 'commands' reallocation error\n");
	 				exit(EXIT_FAILURE);
	 			}
			}
		}
		token = strtok(NULL, WHITESPACE);
	}

	fprintf(file_in_history, "\n");
	fclose(file_in_history);

	commands[ position_commands ]   = NULL;
	options[ position_options ]     = NULL;
	direction[ position_direction ] = NULL;

	transfer[ 0 ] = commands;
	transfer[ 1 ] = options;
	transfer[ 2 ] = direction;

	return transfer;
}
