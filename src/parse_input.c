/*
 * This function will separe the prompt line into tokens.
 * This tokens will be separed in three matrix:
 *
 *   commands  -> will store what the user wants to do;
 *   options   -> will store the parameters of the function;
 *   direction -> will store the way I/O will be processed.
 */



# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/global_variables.h"
# include "../lib/headers/style.h"
# include "../lib/headers/command.h"
# include "../lib/headers/input.h"
# include "../lib/headers/error.h"





char ***
parse_input(char *input)
{
	unsigned int token_size_commands  = TOKEN_LIMIT;
	unsigned int token_size_options   = TOKEN_LIMIT;
	unsigned int token_size_direction = TOKEN_LIMIT;
	unsigned int position_commands    = 0;
	unsigned int position_options     = 0;
	unsigned int position_direction   = 0;

	char ***transfer  = (char ***) malloc(sizeof(char **) * 3);
	char  **commands  = (char  **) malloc(sizeof(char  *) * token_size_commands);
	char  **options   = (char  **) malloc(sizeof(char  *) * token_size_options);
	char  **direction = (char  **) malloc(sizeof(char  *) * token_size_direction);
	char   *token;

	verify_dynamic_allocation(&transfer , "transfer");
	verify_dynamic_allocation(&commands , "commands");
	verify_dynamic_allocation(&options  , "options");
	verify_dynamic_allocation(&direction, "direction");

	token = strtok(input, WHITESPACE);

	while (token != NULL) {
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

                        verify_dynamic_reallocation(&options, "options");
				// if (!options)
				// {
	 			// 	fprintf(stderr, "bash: 'options' reallocation error\n");
	 			// 	exit( EXIT_FAILURE );
	 			// }
			}
		}
		else
		{
			commands[ position_commands++ ] = token;

			if (position_commands >= token_size_commands)
			{
				token_size_commands += TOKEN_LIMIT;
				commands = realloc(commands, sizeof(char *) * token_size_commands);

                        verify_dynamic_reallocation(&commands, "commands");
				// if (!commands)
				// {
	 			// 	fprintf(stderr, "bash: 'commands' reallocation error\n");
	 			// 	exit(EXIT_FAILURE);
	 			// }
			}
		}
		token = strtok(NULL, WHITESPACE);
	}

	commands[ position_commands ]   = NULL;
	options[ position_options ]     = NULL;
	direction[ position_direction ] = NULL;

	transfer[ 0 ] = commands;
	transfer[ 1 ] = options;
	transfer[ 2 ] = direction;

	return transfer;
}
