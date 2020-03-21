# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/global_variables.h"
# include "../lib/headers/style.h"
# include "../lib/headers/command.h"
# include "../lib/headers/input.h"




int
execute_input(char **command,
              char **options,
              char **direction)
{
	if (command[ 0 ] == NULL)
	{
		return 1;
	}
	else if (!strcmp(command[ 0 ], "exit"))
	{
		return EXIT_SUCCESS;
	}
	else
	{
		if (!strcmp(command[ 0 ], "cd"))
		{
			return cd(command,
				      options,
					  direction);
		}
		if (!strcmp(command[ 0 ], "ls"))
		{
			return ls(command,
				      options,
					  direction);
		}
		if (!strcmp(command[ 0 ], "wc"))
		{
			return wc(command,
				      options,
					  direction);
		}
		if (!strcmp(command[ 0 ], "mv"))
		{
			return mv(command,
				      options,
					  direction);
		}
		if (!strcmp(command[ 0 ], "rm"))
		{
			return rm(command,
				      options,
					  direction);
		}
		if (!strcmp(command[ 0 ], "cp"))
		{
			return cp(command,
				      options,
					  direction);
		}
		if (!strcmp(command[ 0 ], "cat"))
		{
			return cat(command,
				       options,
					   direction);
		}
		if (!strcmp(command[ 0 ], "pwd"))
		{
			const int var = pwd(options,
				                direction);
			puts("");
			return var;
		}
		if (!strcmp(command[ 0 ], "tail"))
		{
			return tail(command,
				        options,
						direction);
		}
		if (!strcmp(command[ 0 ], "diff"))
		{
			return diff(command,
				        options,
						direction);
		}
		if (!strcmp(command[ 0 ], "help"))
		{
			return help(command,
				        options,
						direction);
		}
		if (!strcmp(command[ 0 ], "echo"))
		{
			return echo(command,
				        options,
						direction);
		}
		if (!strcmp(command[ 0 ], "head"))
		{
			return head(command,
				        options,
						direction);
		}
		if (!strcmp(command[ 0 ], "mkdir"))
		{
			return mk_dir(command,
				          options,
						  direction);
		}
		if (!strcmp(command[ 0 ], "rmdir"))
		{
			return rm_dir(command,
				          options,
						  direction);
		}
		if (!strcmp(command[ 0 ], "touch")) {
			return touch(command,
				         options,
						 direction);
		}
		if (!strcmp(command[ 0 ], "history")) {
			return history(command,
				           options,
						   direction);
		}
		if (!strcmp(command[ 0 ], "neofetch")) {
			return neofetch();
		}
	}
	fprintf(stderr, "%s: command not found\n", command[ 0 ]);
	return 2;
}
