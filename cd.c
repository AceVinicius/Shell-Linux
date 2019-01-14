# include "./headers/include.h"
# include "./headers/define.h"
# include "./headers/global_variables.h"
# include "./headers/style.h"
# include "./headers/command.h"
# include "./headers/input.h"



int
cd(char **command,
   char **options,
   char **direction)
{
	if (command[ 1 ] == NULL)
	{
		unsigned int   uid = getuid();

		struct passwd *pwd = getpwuid(uid);
		if (!pwd)
		{
			fprintf(stderr, "bash: User with %u ID is unknown.\n", uid);
			return 2;
		}

		if (chdir(pwd -> pw_dir))
		{
			fprintf(stderr, "Unable to change directory to '%s'\n", pwd -> pw_dir);
			return 2;
		}
	}
	else
	{
		if (chdir(command[ 1 ]))
		{
			fprintf(stderr, "bash: cd: %s: No such file or directory\n", command[ 1 ]);
			return 2;
		}
	}
	return 1;
}
