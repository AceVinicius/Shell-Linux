/******************************************************************************
 ******************************************************************************
 *****                                                                    *****
 *****                      Engenharia de Computaçao                      *****
 *****                                                                    *****
 *****                            Linux Shell                             *****
 *****                           Version 1.0.0                            *****
 *****                                                                    *****
 *****                          Vinícius Aguiar                           *****
 *****                                                                    *****
 *****                      19.06.2018 - 04.07.2018                       *****
 *****                                                                    *****
 ******************************************************************************
 ******************************************************************************/



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

# include "../lib/headers/define.h"
# include "../lib/headers/global_variables.h"
# include "../lib/headers/style.h"
# include "../lib/headers/command.h"
# include "../lib/headers/input.h"
# include "../lib/headers/error.h"
# include "../lib/headers/main.h"



void
initialize_readline(void)
{
      char *_history_file_path_ = getenv("HOME");

      rl_initialize();

      using_history();
      strcat(_history_file_path_, "/.my_history");
      if (access(_history_file_path_, F_OK))
      {
            // create_history_file(_history_file_path_);
      }
      else
      {
            read_history(_history_file_path_);
      }
}





void
generate_prompt_line(char *_prompt_line_)
{
      char *_current_user_ = getenv("USER");
      char  _computer_name_[ COMPUTER_NAME_LIMIT ];
      char  _current_directory_[ PWD_LIMIT ];

      gethostname(_computer_name_, COMPUTER_NAME_LIMIT);

      getcwd(_current_directory_, PWD_LIMIT);
      if (strcmp(_current_directory_, "/") == 0)
      {}
      else if (strstr(strrchr(_current_directory_, '/'), _current_user_) != NULL)
      {
            _current_directory_[ 0 ] = '~';
            _current_directory_[ 1 ] = '\0';
      }
      else
      {
            strcpy(_current_directory_, strrchr(_current_directory_, '/') + 1);
      }

      // fix /hmee bug
      snprintf(_prompt_line_, PROMPT_LINE_LIMIT, "[%s@%s %s]$ ", _current_user_, _computer_name_, _current_directory_);
}





char *
read_user_input(char *_prompt_line_)
{
      char *_buffer_;

      do
      {
            _buffer_ = readline(_prompt_line_);
      }
      while(strlen(_buffer_) == 0);
      add_history(_buffer_);
      add_history_to_file(_buffer_);

      return _buffer_;
}





void
add_history_to_file(char *_user_input_buffer_)
{
      char *_history_file_path_ = getenv("HOME");

      strcat(_history_file_path_, "/.my_history");

      FILE *_history_file_pointer_ = fopen(_history_file_path_, "a");
      verify_file_pointer(&_history_file_pointer_, ".my_history");

      fprintf(_history_file_pointer_, "%s\n", _user_input_buffer_);
      fclose(_history_file_pointer_);
}





int
main(      int   argc,
     const char *argv[ ])
{
      bool status;

      initialize_readline();

      do
      {
            char prompt_line[ PROMPT_LINE_LIMIT ];

            generate_prompt_line(prompt_line);

            reset(); style(BOLD, RED);  //Only for differentiating from original terminal
            char ***receive   = parse_input(read_user_input(prompt_line));
            char  **command   = *(receive + 0);
            char  **options   = *(receive + 1);
            char  **direction = *(receive + 2);

            status = execute_input(command, options, direction);

            free(receive);
            free(command);
            free(options);
            free(direction);
      }
      while (status);

      reset();

      return EXIT_SUCCESS;
}
