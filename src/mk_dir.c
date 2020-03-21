# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/global_variables.h"
# include "../lib/headers/style.h"
# include "../lib/headers/command.h"
# include "../lib/headers/input.h"



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
