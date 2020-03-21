#ifndef MAIN_H
# define MAIN_H



void   initialize_readline   (void);



void   generate_prompt_line  (char *_prompt_line_);



char*  read_user_input       (char *_prompt_line_);



void   add_history_to_file   (char *_user_input_buffer_);



#endif  // MAIN_H
