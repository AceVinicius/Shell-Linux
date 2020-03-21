# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/global_variables.h"
# include "../lib/headers/style.h"
# include "../lib/headers/command.h"
# include "../lib/headers/input.h"



int
pwd(char **options,
    char **direction)
{
	char cwd[ PWD_LIMIT ];
	if (getcwd(cwd, sizeof(cwd)) == NULL)
	{
		fprintf(stderr, "bash: couldn't get current directory\n");
		return 2;
	}
	printf("%s", cwd);

	return 1;
}
