#ifndef ERROR_H
# define ERROR_H



void  verify_dynamic_allocation    (void *_array_,
                                    char *_array_name_);



void  verify_dynamic_reallocation  (void *_array_,
                                    char *_array_name_);



void  verify_file_pointer          (void *_file_,
                                    char *_file_name_);



#endif  //ERROR_H
