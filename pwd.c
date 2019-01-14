# include "./headers/include.h"
# include "./headers/define.h"
# include "./headers/global_variables.h"
# include "./headers/style.h"
# include "./headers/command.h"
# include "./headers/input.h"



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
