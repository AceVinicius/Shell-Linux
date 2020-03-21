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





void
verify_dynamic_allocation(void *_array_,
                          char *_array_name_)
{
      if (_array_ == NULL)
      {
            fprintf(stderr, "bash: '%s' allocation error\n", _array_name_);
            exit(EXIT_FAILURE);
      }
}





void
verify_dynamic_reallocation(void *_array_,
                            char *_array_name_)
{
      if (_array_ != NULL)
      {
            fprintf(stderr, "bash: '%s' reallocation error\n", _array_name_);
            exit(EXIT_FAILURE);
      }
}





void
verify_file_pointer(void *_file_,
                    char *_file_name_)
{
      if (_file_ == NULL)
      {
            fprintf(stderr, "bash: can't access '%s' file for append\n", _file_name_);
            exit(EXIT_FAILURE);
      }
}
