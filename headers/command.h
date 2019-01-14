#ifndef COMMAND_H_
# define COMMAND_H_



int  cat       (char **command,
	            char **options,
	            char **direction);

int  cd        (char **command,
	            char **options,
	            char **direction);

int  cp        (char **command,
	            char **options,
	            char **direction);

int  diff      (char **command,
	            char **options,
	            char **direction);

int  echo      (char **command,
	            char **options,
	            char **direction);

int  head      (char **command,
	            char **options,
	            char **direction);

int  help      (char **command,
	            char **options,
	            char **direction);

int  history   (char **command,
	            char **options,
	            char **direction);

int  ls        (char **command,
                char **options,
			    char **direction);

int  mk_dir    (char **command,
                char **options,
			    char **direction);

int  mv        (char **command,
                char **options,
			    char **direction);

int  neofetch  (void);

int  pwd       (char **options,
			    char **direction);

int  rm_dir    (char **command,
                char **options,
			    char **direction);

int  rm        (char **command,
                char **options,
                char **direction);

int  tail      (char **command,
                char **options,
                char **direction);

int  touch     (char **command,
	            char **options,
			    char **direction);

int  wc        (char **command,
                char **options,
			    char **direction);



#endif // COMMAND_H_
