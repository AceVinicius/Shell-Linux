/******************************************************************************************************
 ******************************************************************************************************
 *****                                                                                            *****
 *****                                  Engenharia de Computaçao                                  *****
 *****                                                                                            *****
 *****                                         Linux Shell                                        *****
 *****                                        Version 0.0.1                                       *****
 *****                                                                                            *****
 *****                                       Vinícius Aguiar                                      *****
 *****                                                                                            *****
 *****                                   19.06.2018 - 04.07.2018                                  *****
 *****                                                                                            *****
 ******************************************************************************************************
 ******************************************************************************************************/



# include <math.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <fnmatch.h>
# include <unistd.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <glob.h>
# include <pwd.h>
# include <ftw.h>

# include "./headers/define.h"
# include "./headers/global_variables.h"
# include "./headers/style.h"
# include "./headers/command.h"
# include "./headers/input.h"



int
main(int         argc,
	 const char *argv[ ])
{
	char *input;
	char *shell_history = getenv("HOME");
	char  prompt_line[ 128 ];
	char  computer[ 128 ];

	bool  status;

	start();
	gethostname(computer, 128);
	rl_initialize();
	using_history();
	rl_bind_key('\t', rl_complete);

	strcat(shell_history, "/.my_history");
	if (access(shell_history, F_OK))
	{
		// create_history_file(shell_history);
	}
	else
	{
		read_history(shell_history);
	}

	do
	{
		// snprintf(prompt_line, sizeof(prompt_line), "\033[1;32m%s@%s\033[0;0m:\033[1;34m%s\033[0;0m$ ", getenv("USER"), computer,
		// strcmp(getcwd(NULL, 1024), getenv("PWD")) ? getcwd(NULL, 1024) : "~" );
		style(BOLD, GREEN);
			printf("%s@%s", getenv("USER"), computer);
		reset( );
			printf(":");
		style(BOLD, BLUE);
			printf("%s", !strcmp(getcwd(NULL, 1024), getenv("PWD")) ? getcwd(NULL, 1024) : "~");
		reset( );
			printf("$ ");

		input = readline(prompt_line);

		add_history(input);

		char ***receive   = parse_input(input);
		char  **command   = *(receive + 0);
		char  **options   = *(receive + 1);
		char  **direction = *(receive + 2);

		status = execute_input(command,
			                   options,
							   direction);

		free(input);
		free(command);
		free(options);
		free(direction);
	}
	while (status);

	finish();
	return EXIT_SUCCESS;
}
