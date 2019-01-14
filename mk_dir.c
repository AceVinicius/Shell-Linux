# include "./headers/include.h"
# include "./headers/define.h"
# include "./headers/global_variables.h"
# include "./headers/style.h"
# include "./headers/command.h"
# include "./headers/input.h"



int
mk_dir(char **command,
       char **options,
       char **direction)
{
	if (command[ 1 ] == NULL) {
		fprintf(stderr, "mkdir: missing operand\n");
		puts("Try 'help mkdir' for more information.");
	}

	for (register unsigned int i = 0; options[ i ] != NULL; i++) {

	}

	// for (register unsigned int i = 0; direction[ i ] != NULL; i++){
	//
	// }

	for (register unsigned int i = 1; command[ i ] != NULL; i++) {
		if (mkdir(command[ i ], S_IRWXU)) {
			fprintf(stderr, "bash: mkdir: '%s': Cannot create directory.\n", command[ i ]);

			return 2;
		}
	}

	return 1;
}
