# include "./headers/include.h"
# include "./headers/define.h"
# include "./headers/global_variables.h"
# include "./headers/style.h"
# include "./headers/command.h"
# include "./headers/input.h"


char *builtin_commands[ ] =
{
	"rm [OPTION]... [FILE]...",
	"ls [OPTION]... [FILE]...",
	"wc [OPTION]... [FILE]...",
	"mv [OPTION]... [-T] SOURCE DEST",
	"cd [-L|[-P [-e]] [-@]] [dir]",
	"cp [OPTION]... [-T] SOURCE DEST",
	"cat [OPTION]... [FILE]..."
	"pwd [-LP]",
	"tail [OPTION]... [FILE]...",
	"exit [n]",
	"diff [OPTION]... FILES",
	"help [-dms] [pattern ...]",
	"echo [-neE] [arg ...]",
	"head [OPTION]... FILE...",
	"touch [OPTION]... FILE...",
	"rmdir ",
	"mkdir ",
	"history [-c] [-d offset] [n] or history -anrw [filename] or history -ps arg [arg...]"
};
int
help(char **command,
     char **options,
     char **direction)
{
	if (command[ 1 ] == NULL)
	{
		puts("These shell commands are defined internally.  Type 'help' to see this list.");
		puts("Type 'help name' to find out more about the function 'name'.");
		puts("Use 'info bash' to find out more about the shell in general.");
		puts("Use 'man -k' or 'info' to find out more about commands not in this list.");
		puts("");
		puts("A star (*) next to a name means that the command is disabled.");
		puts("");

		for (register unsigned int i = 0; builtin_commands[ i ] != NULL; i++)
		{
			printf(" %s\n", builtin_commands[ i ]);
		}
		return 1;
	}

	if (!strcmp(command[ 1 ], "ls"))
	{
		puts("Usage: ls [OPTION]... [FILE]...");
		puts("List information about the FILEs (the current directory by default).");
		puts("Sort entries alphabetically if none of -cftuvSUX nor --sort is specified.");
		puts("");
		puts("Mandatory arguments to long options are mandatory for short options too.");
		puts("  -a, --all                  do not ignore entries starting with .");
		puts("  -A, --almost-all           do not list implied . and ..");
		puts("      --author               with -l, print the author of each file");
		puts("  -b, --escape               print C-style escapes for nongraphic characters");
		puts("      --block-size=SIZE      scale sizes by SIZE before printing them; e.g.,");
		puts("                               '--block-size=M' prints sizes in units of");
		puts("                               1,048,576 bytes; see SIZE format below");
		puts("  -B, --ignore-backups       do not list implied entries ending with ~");
		puts("  -c                         with -lt: sort by, and show, ctime (time of last");
		puts("                               modification of file status information);");
		puts("                               with -l: show ctime and sort by name;");
		puts("                               otherwise: sort by ctime, newest first");
		puts("  -C                         list entries by columns");
		puts("      --color[=WHEN]         colorize the output; WHEN can be 'always' (default");
		puts("                               if omitted), 'auto', or 'never'; more info below");
		puts("  -d, --directory            list directories themselves, not their contents");
		puts("  -D, --dired                generate output designed for Emacs' dired mode");
		puts("  -f                         do not sort, enable -aU, disable -ls --color");
		puts("  -F, --classify             append indicator (one of */=>@|) to entries");
		puts("      --file-type            likewise, except do not append '*'");
		puts("      --format=WORD          across -x, commas -m, horizontal -x, long -l,");
		puts("                               single-column -1, verbose -l, vertical -C");
		puts("      --full-time            like -l --time-style=full-iso");
		puts("  -g                         like -l, but do not list owner");
		puts("      --group-directories-first");
		puts("                             group directories before files;");
		puts("                               can be augmented with a --sort option, but any");
		puts("                               use of --sort=none (-U) disables grouping");
		puts("  -G, --no-group             in a long listing, don't print group names");
		puts("  -h, --human-readable       with -l and/or -s, print human readable sizes");
		puts("                               (e.g., 1K 234M 2G)");
		puts("      --si                   likewise, but use powers of 1000 not 1024");
		puts("  -H, --dereference-command-line");
		puts("                             follow symbolic links listed on the command line");
		puts("      --dereference-command-line-symlink-to-dir");
		puts("                             follow each command line symbolic link");
		puts("                               that points to a directory");
		puts("      --hide=PATTERN         do not list implied entries matching shell PATTERN");
		puts("                               (overridden by -a or -A)");
		puts("      --hyperlink[=WHEN]     hyperlink file names; WHEN can be 'always'");
		puts("                               (default if omitted), 'auto', or 'never'");
		puts("      --indicator-style=WORD  append indicator with style WORD to entry names:");
		puts("                               none (default), slash (-p),");
		puts("                               file-type (--file-type), classify (-F)");
		puts("  -i, --inode                print the index number of each file");
		puts("  -I, --ignore=PATTERN       do not list implied entries matching shell PATTERN");
		puts("  -k, --kibibytes            default to 1024-byte blocks for disk usage");
		puts("  -l                         use a long listing format");
		puts("  -L, --dereference          when showing file information for a symbolic");
		puts("                               link, show information for the file the link");
		puts("                               references rather than for the link itself");
		puts("  -m                         fill width with a comma separated list of entries");
		puts("  -n, --numeric-uid-gid      like -l, but list numeric user and group IDs");
		puts("  -N, --literal              print entry names without quoting");
		puts("  -o                         like -l, but do not list group information");
		puts("  -p, --indicator-style=slash");
		puts("                             append / indicator to directories");
		puts("  -q, --hide-control-chars   print ? instead of nongraphic characters");
		puts("      --show-control-chars   show nongraphic characters as-is (the default,");
		puts("                               unless program is 'ls' and output is a terminal)");
		puts("  -Q, --quote-name           enclose entry names in double quotes");
		puts("      --quoting-style=WORD   use quoting style WORD for entry names:");
		puts("                               literal, locale, shell, shell-always,");
		puts("                               shell-escape, shell-escape-always, c, escape");
		puts("  -r, --reverse              reverse order while sorting");
		puts("  -R, --recursive            list subdirectories recursively");
		puts("  -s, --size                 print the allocated size of each file, in blocks");
		puts("  -S                         sort by file size, largest first");
		puts("      --sort=WORD            sort by WORD instead of name: none (-U), size (-S)");
		puts("                               time (-t), version (-v), extension (-X)");
		puts("      --time=WORD            with -l, show time as WORD instead of default");
		puts("                               modification time: atime or access or use (-u);");
		puts("                               ctime or status (-c); also use specified time");
		puts("                               as sort key if --sort=time (newest first)");
		puts("      --time-style=STYLE     with -l, show times using style STYLE:");
		puts("                               full-iso, long-iso, iso, locale, or +FORMAT;");
		puts("                               FORMAT is interpreted like in 'date'; if FORMAT");
		puts("                               is FORMAT1<newline>FORMAT2, then FORMAT1 applies");
		puts("                               to non-recent files and FORMAT2 to recent files;");
		puts("                               if STYLE is prefixed with 'posix-', STYLE");
		puts("                               takes effect only outside the POSIX locale");
		puts("  -t                         sort by modification time, newest first");
		puts("  -T, --tabsize=COLS         assume tab stops at each COLS instead of 8");
		puts("  -u                         with -lt: sort by, and show, access time;");
		puts("                               with -l: show access time and sort by name;");
		puts("                               otherwise: sort by access time, newest first");
		puts("  -U                         do not sort; list entries in directory order");
		puts("  -v                         natural sort of (version) numbers within text");
		puts("  -w, --width=COLS           set output width to COLS.  0 means no limit");
		puts("  -x                         list entries by lines instead of by columns");
		puts("  -X                         sort alphabetically by entry extension");
		puts("  -Z, --context              print any security context of each file");
		puts("  -1                         list one file per line.  Avoid '\\n' with -q or -b");
		puts("      --help     display this help and exit");
		puts("      --version  output version information and exit");
		puts("");
		puts("The SIZE argument is an integer and optional unit (example: 10K is 10*1024).");
		puts("Units are K,M,G,T,P,E,Z,Y (powers of 1024) or KB,MB,... (powers of 1000).");
		puts("");
		puts("Using color to distinguish file types is disabled both by default and");
		puts("with --color=never.  With --color=auto, ls emits color codes only when");
		puts("standard output is connected to a terminal.  The LS_COLORS environment");
		puts("variable can change the settings.  Use the dircolors command to set it.");
		puts("");
		puts("Exit status:");
		puts(" 0  if OK,");
		puts(" 1  if minor problems (e.g., cannot access subdirectory),");
		puts(" 2  if serious trouble (e.g., cannot access command-line argument).");
		puts("");
		puts("GNU coreutils online help: <http://www.gnu.org/software/coreutils/>");
		puts("Full documentation at: <http://www.gnu.org/software/coreutils/ls>");
		puts("or available locally via: info '(coreutils) ls invocation'");

		return 1;
	}

	if (!strcmp(command[ 1 ], "wc"))
	{
		puts("Usage: wc [OPTION]... [FILE]...");
		puts("  or:  wc [OPTION]... --files0-from=F");
		puts("Print newline, word, and byte counts for each FILE, and a total line if");
		puts("more than one FILE is specified.  A word is a non-zero-length sequence of");
		puts("characters delimited by white space.");
		puts("");
		puts("With no FILE, or when FILE is -, read standard input.");
		puts("");
		puts("The options below may be used to select which counts are printed, always in");
		puts("the following order: newline, word, character, byte, maximum line length.");
		puts("  -c, --bytes            print the byte counts");
		puts("  -m, --chars            print the character counts");
		puts("  -l, --lines            print the newline counts");
		puts("      --files0-from=F    read input from the files specified by");
		puts("                           NUL-terminated names in file F;");
		puts("                           If F is - then read names from standard input");
		puts("  -L, --max-line-length  print the maximum display width");
		puts("  -w, --words            print the word counts");
		puts("      --help     display this help and exit");
		puts("      --version  output version information and exit");
		puts("");
		puts("GNU coreutils online help: <http://www.gnu.org/software/coreutils/>");
		puts("Full documentation at: <http://www.gnu.org/software/coreutils/wc>");
		puts("or available locally via: info '(coreutils) wc invocation'");

		return 1;
	}

	if (!strcmp(command[ 1 ], "mv"))
	{
		puts("Usage: mv [OPTION]... [-T] SOURCE DEST");
		puts("  or:  mv [OPTION]... SOURCE... DIRECTORY");
		puts("  or:  mv [OPTION]... -t DIRECTORY SOURCE...");
		puts("Rename SOURCE to DEST, or move SOURCE(s) to DIRECTORY.");
		puts("");
		puts("Mandatory arguments to long options are mandatory for short options too.");
		puts("      --backup[=CONTROL]       make a backup of each existing destination file");
		puts("  -b                           like --backup but does not accept an argument");
		puts("  -f, --force                  do not prompt before overwriting");
		puts("  -i, --interactive            prompt before overwrite");
		puts("  -n, --no-clobber             do not overwrite an existing file");
		puts("If you specify more than one of -i, -f, -n, only the final one takes effect.");
		puts("      --strip-trailing-slashes  remove any trailing slashes from each SOURCE");
		puts("                                 argument");
		puts("  -S, --suffix=SUFFIX          override the usual backup suffix");
		puts("  -t, --target-directory=DIRECTORY  move all SOURCE arguments into DIRECTORY");
		puts("  -T, --no-target-directory    treat DEST as a normal file");
		puts("  -u, --update                 move only when the SOURCE file is newer");
		puts("                                 than the destination file or when the");
		puts("                                 destination file is missing");
		puts("  -v, --verbose                explain what is being done");
		puts("  -Z, --context                set SELinux security context of destination");
		puts("                                 file to default type");
		puts("      --help     display this help and exit");
		puts("      --version  output version information and exit");
		puts("");
		puts("The backup suffix is '~', unless set with --suffix or SIMPLE_BACKUP_SUFFIX.");
		puts("The version control method may be selected via the --backup option or through");
		puts("the VERSION_CONTROL environment variable.  Here are the values:");
		puts("");
		puts("  none, off       never make backups (even if --backup is given)");
		puts("  numbered, t     make numbered backups");
		puts("  existing, nil   numbered if numbered backups exist, simple otherwise");
		puts("  simple, never   always make simple backups");
		puts("");
		puts("GNU coreutils online help: <http://www.gnu.org/software/coreutils/>");
		puts("Full documentation at: <http://www.gnu.org/software/coreutils/mv>");
		puts("or available locally via: info '(coreutils) mv invocation'");

		return 1;
	}

	if (!strcmp(command[ 1 ], "rm"))
	{
		puts("Usage: rm [OPTION]... [FILE]...");
		puts("Remove (unlink) the FILE(s).");
		puts("");
		puts("  -f, --force           ignore nonexistent files and arguments, never prompt");
		puts("  -i                    prompt before every removal");
		puts("  -I                    prompt once before removing more than three files, or");
		puts("                          when removing recursively; less intrusive than -i,");
		puts("                          while still giving protection against most mistakes");
		puts("      --interactive[=WHEN]  prompt according to WHEN: never, once (-I), or");
		puts("                          always (-i); without WHEN, prompt always");
		puts("      --one-file-system  when removing a hierarchy recursively, skip any");
		puts("                          directory that is on a file system different from");
		puts("                          that of the corresponding command line argument");
		puts("      --no-preserve-root  do not treat '/' specially");
		puts("      --preserve-root   do not remove '/' (default)");
		puts("  -r, -R, --recursive   remove directories and their contents recursively");
		puts("  -d, --dir             remove empty directories");
		puts("  -v, --verbose         explain what is being done");
		puts("      --help     display this help and exit");
		puts("      --version  output version information and exit");
		puts("");
		puts("By default, rm does not remove directories.  Use the --recursive (-r or -R)");
		puts("option to remove each listed directory, too, along with all of its contents.");
		puts("");
		puts("To remove a file whose name starts with a '-', for example '-foo',");
		puts("use one of these commands:");
		puts("  rm -- -foo");
		puts("");
		puts("  rm ./-foo");
		puts("");
		puts("Note that if you use rm to remove a file, it might be possible to recover");
		puts("some of its contents, given sufficient expertise and/or time.  For greater");
		puts("assurance that the contents are truly unrecoverable, consider using shred.");
		puts("");
		puts("GNU coreutils online help: <http://www.gnu.org/software/coreutils/>");
		puts("Full documentation at: <http://www.gnu.org/software/coreutils/rm>");
		puts("or available locally via: info '(coreutils) rm invocation'");

		return 1;
	}

	if (!strcmp(command[ 1 ], "cd"))
	{
		puts("cd: cd [-L|[-P [-e]] [-@]] [dir]");
		puts("    Change the shell working directory.");
		puts("");
		puts("    Change the current directory to DIR.  The default DIR is the value of the");
		puts("    HOME shell variable.");
		puts("");
		puts("    The variable CDPATH defines the search path for the directory containing");
		puts("    DIR.  Alternative directory names in CDPATH are separated by a colon (:).");
		puts("    A null directory name is the same as the current directory.  If DIR begins");
		puts("    with a slash (/), then CDPATH is not used.");
		puts("");
		puts("    If the directory is not found, and the shell option `cdable_vars' is set,");
		puts("    the word is assumed to be  a variable name.  If that variable has a value,");
		puts("    its value is used for DIR.");
		puts("");
		puts("    Options:");
		puts("      -L        force symbolic links to be followed: resolve symbolic");
		puts("                links in DIR after processing instances of '..'");
		puts("      -P        use the physical directory structure without following");
		puts("                symbolic links: resolve symbolic links in DIR before");
		puts("                processing instances of '..'");
		puts("      -e        if the -P option is supplied, and the current working");
		puts("                directory cannot be determined successfully, exit with");
		puts("                a non-zero status");
		puts("      -@        on systems that support it, present a file with extended");
		puts("                attributes as a directory containing the file attributes");
		puts("");
		puts("    The default is to follow symbolic links, as if '-L' were specified.");
		puts("    '..' is processed by removing the immediately previous pathname component");
		puts("    back to a slash or the beginning of DIR.");
		puts("");
		puts("    Exit Status:");
		puts("    Returns 0 if the directory is changed, and if $PWD is set successfully when");
		puts("    -P is used; non-zero otherwise.");

		return 1;
	}

	if (!strcmp(command[ 1 ], "cp"))
	{
		puts("Usage: cp [OPTION]... [-T] SOURCE DEST");
		puts("  or:  cp [OPTION]... SOURCE... DIRECTORY");
		puts("  or:  cp [OPTION]... -t DIRECTORY SOURCE...");
		puts("Copy SOURCE to DEST, or multiple SOURCE(s) to DIRECTORY.");
		puts("");
		puts("Mandatory arguments to long options are mandatory for short options too.");
		puts("  -a, --archive                same as -dR --preserve=all");
		puts("      --attributes-only        don't copy the file data, just the attributes");
		puts("      --backup[=CONTROL]       make a backup of each existing destination file");
		puts("  -b                           like --backup but does not accept an argument");
		puts("      --copy-contents          copy contents of special files when recursive");
		puts("  -d                           same as --no-dereference --preserve=links");
		puts("  -f, --force                  if an existing destination file cannot be");
		puts("                                 opened, remove it and try again (this option");
		puts("                                 is ignored when the -n option is also used)");
		puts("  -i, --interactive            prompt before overwrite (overrides a previous -n");
		puts("                                  option)");
		puts("  -H                           follow command-line symbolic links in SOURCE");
		puts("  -l, --link                   hard link files instead of copying");
		puts("  -L, --dereference            always follow symbolic links in SOURCE");
		puts("  -n, --no-clobber             do not overwrite an existing file (overrides");
		puts("                                 a previous -i option)");
		puts("  -P, --no-dereference         never follow symbolic links in SOURCE");
		puts("  -p                           same as --preserve=mode,ownership,timestamps");
		puts("      --preserve[=ATTR_LIST]   preserve the specified attributes (default:");
		puts("                                 mode,ownership,timestamps), if possible");
		puts("                                 additional attributes: context, links, xattr,");
		puts("                                 all");
		puts("      --no-preserve=ATTR_LIST  don't preserve the specified attributes");
		puts("      --parents                use full source file name under DIRECTORY");
		puts("  -R, -r, --recursive          copy directories recursively");
		puts("      --reflink[=WHEN]         control clone/CoW copies. See below");
		puts("      --remove-destination     remove each existing destination file before");
		puts("                                 attempting to open it (contrast with --force)");
		puts("      --sparse=WHEN            control creation of sparse files. See below");
		puts("      --strip-trailing-slashes  remove any trailing slashes from each SOURCE");
		puts("                                 argument");
		puts("  -s, --symbolic-link          make symbolic links instead of copying");
		puts("  -S, --suffix=SUFFIX          override the usual backup suffix");
		puts("  -t, --target-directory=DIRECTORY  copy all SOURCE arguments into DIRECTORY");
		puts("  -T, --no-target-directory    treat DEST as a normal file");
		puts("  -u, --update                 copy only when the SOURCE file is newer");
		puts("                                 than the destination file or when the");
		puts("                                 destination file is missing");
		puts("  -v, --verbose                explain what is being done");
		puts("  -x, --one-file-system        stay on this file system");
		puts("  -Z                           set SELinux security context of destination");
		puts("                                 file to default type");
		puts("      --context[=CTX]          like -Z, or if CTX is specified then set the");
		puts("                                 SELinux or SMACK security context to CTX");
		puts("      --help     display this help and exit");
		puts("      --version  output version information and exit");
		puts("");
		puts("By default, sparse SOURCE files are detected by a crude heuristic and the");
		puts("corresponding DEST file is made sparse as well.  That is the behavior");
		puts("selected by --sparse=auto.  Specify --sparse=always to create a sparse DEST");
		puts("file whenever the SOURCE file contains a long enough sequence of zero bytes.");
		puts("Use --sparse=never to inhibit creation of sparse files.");
		puts("");
		puts("When --reflink[=always] is specified, perform a lightweight copy, where the");
		puts("data blocks are copied only when modified.  If this is not possible the copy");
		puts("fails, or if --reflink=auto is specified, fall back to a standard copy.");
		puts("");
		puts("The backup suffix is '~', unless set with --suffix or SIMPLE_BACKUP_SUFFIX.");
		puts("The version control method may be selected via the --backup option or through");
		puts("the VERSION_CONTROL environment variable.  Here are the values:");
		puts("");
		puts("  none, off       never make backups (even if --backup is given)");
		puts("  numbered, t     make numbered backups");
		puts("  existing, nil   numbered if numbered backups exist, simple otherwise");
		puts("  simple, never   always make simple backups");
		puts("");
		puts("As a special case, cp makes a backup of SOURCE when the force and backup");
		puts("options are given and SOURCE and DEST are the same name for an existing,");
		puts("regular file.");
		puts("");
		puts("GNU coreutils online help: <http://www.gnu.org/software/coreutils/>");
		puts("Full documentation at: <http://www.gnu.org/software/coreutils/cp>");
		puts("or available locally via: info '(coreutils) cp invocation'");

		return 1;
	}

	if (!strcmp(command[ 1 ], "cat"))
	{
		puts("Usage: cat [OPTION]... [FILE]...");
		puts("Concatenate FILE(s) to standard output.");
		puts("");
		puts("With no FILE, or when FILE is -, read standard input.");
		puts("");
		puts("  -A, --show-all           equivalent to -vET");
		puts("  -b, --number-nonblank    number nonempty output lines, overrides -n");
		puts("  -e                       equivalent to -vE");
		puts("  -E, --show-ends          display $ at end of each line");
		puts("  -n, --number             number all output lines");
		puts("  -s, --squeeze-blank      suppress repeated empty output lines");
		puts("  -t                       equivalent to -vT");
		puts("  -T, --show-tabs          display TAB characters as ^I");
		puts("  -u                       (ignored)");
		puts("  -v, --show-nonprinting   use ^ and M- notation, except for LFD and TAB");
		puts("      --help     display this help and exit");
		puts("      --version  output version information and exit");
		puts("");
		puts("Examples:");
		puts("  cat f - g  Output f's contents, then standard input, then g's contents.");
		puts("  cat        Copy standard input to standard output.");
		puts("");
		puts("GNU coreutils online help: <http://www.gnu.org/software/coreutils/>");
		puts("Full documentation at: <http://www.gnu.org/software/coreutils/cat>");
		puts("or available locally via: info '(coreutils) cat invocation'");

		return 1;
	}

	if (!strcmp(command[ 1 ], "pwd"))
	{
		puts("pwd: pwd [-LP]");
		puts("    Print the name of the current working directory.");
		puts("");
		puts("    Options:");
		puts("      -L        print the value of $PWD if it names the current working");
		puts("                directory");
		puts("      -P        print the physical directory, without any symbolic links");;
		puts("");
		puts("    By default, `pwd' behaves as if `-L' were specified.");
		puts("");
		puts("    Exit Status:");
		puts("    Returns 0 unless an invalid option is given or the current directory");
		puts("    cannot be read.");

		return 1;
	}

	if (!strcmp(command[ 1 ], "tail"))
	{
		puts("Usage: tail [OPTION]... [FILE]...");
		puts("Print the last 10 lines of each FILE to standard output.");
		puts("With more than one FILE, precede each with a header giving the file name.");
		puts("");
		puts("With no FILE, or when FILE is -, read standard input.");
		puts("");
		puts("Mandatory arguments to long options are mandatory for short options too.");
		puts("  -c, --bytes=[+]NUM       output the last NUM bytes; or use -c +NUM to");
		puts("                             output starting with byte NUM of each file");
		puts("  -f, --follow[={name|descriptor}]");
		puts("                           output appended data as the file grows;");
		puts("                             an absent option argument means 'descriptor'");
		puts("  -F                       same as --follow=name --retry");
		puts("  -n, --lines=[+]NUM       output the last NUM lines, instead of the last 10;");
		puts("                             or use -n +NUM to output starting with line NUM");
		puts("      --max-unchanged-stats=N");
		puts("                           with --follow=name, reopen a FILE which has not");
		puts("                             changed size after N (default 5) iterations");
		puts("                             to see if it has been unlinked or renamed");
		puts("                             (this is the usual case of rotated log files);");
		puts("                             with inotify, this option is rarely useful");
		puts("      --pid=PID            with -f, terminate after process ID, PID dies");
		puts("  -q, --quiet, --silent    never output headers giving file names");
		puts("      --retry              keep trying to open a file if it is inaccessible");
		puts("  -s, --sleep-interval=N   with -f, sleep for approximately N seconds");
		puts("                             (default 1.0) between iterations;");
		puts("                             with inotify and --pid=P, check process P at");
		puts("                             least once every N seconds");
		puts("  -v, --verbose            always output headers giving file names");
		puts("  -z, --zero-terminated    line delimiter is NUL, not newline");
		puts("      --help     display this help and exit");
		puts("      --version  output version information and exit");
		puts("");
		puts("NUM may have a multiplier suffix:");
		puts("b 512, kB 1000, K 1024, MB 1000*1000, M 1024*1024,");
		puts("GB 1000*1000*1000, G 1024*1024*1024, and so on for T, P, E, Z, Y.");
		puts("");
		puts("With --follow (-f), tail defaults to following the file descriptor, which");
		puts("means that even if a tail'ed file is renamed, tail will continue to track");
		puts("its end.  This default behavior is not desirable when you really want to");
		puts("track the actual name of the file, not the file descriptor (e.g., log");
		puts("rotation).  Use --follow=name in that case.  That causes tail to track the");
		puts("named file in a way that accommodates renaming, removal and creation.");
		puts("");
		puts("GNU coreutils online help: <http://www.gnu.org/software/coreutils/>");
		puts("Full documentation at: <http://www.gnu.org/software/coreutils/tail>");
		puts("or available locally via: info '(coreutils) tail invocation'");

		return 1;
	}

	if (!strcmp(command[ 1 ], "exit"))
	{
		puts("exit: exit [n]");
		puts("    Exit the shell.");
		puts("");
		puts("    Exits the shell with a status of N.  If N is omitted, the exit status");
		puts("    is that of the last command executed.");

		return 1;
	}

	if (!strcmp(command[ 1 ], "diff"))
	{
		puts("Usage: diff [OPTION]... FILES");
		puts("Compare FILES line by line.");
		puts("");
		puts("Mandatory arguments to long options are mandatory for short options too.");
		puts("      --normal                  output a normal diff (the default)");
		puts("  -q, --brief                   report only when files differ");
		puts("  -s, --report-identical-files  report when two files are the same");
		puts("  -c, -C NUM, --context[=NUM]   output NUM (default 3) lines of copied context");
		puts("  -u, -U NUM, --unified[=NUM]   output NUM (default 3) lines of unified context");
		puts("  -e, --ed                      output an ed script");
		puts("  -n, --rcs                     output an RCS format diff");
		puts("  -y, --side-by-side            output in two columns");
		puts("  -W, --width=NUM               output at most NUM (default 130) print columns");
		puts("      --left-column             output only the left column of common lines");
		puts("      --suppress-common-lines   do not output common lines");
		puts("");
		puts("  -p, --show-c-function         show which C function each change is in");
		puts("  -F, --show-function-line=RE   show the most recent line matching RE");
		puts("      --label LABEL             use LABEL instead of file name and timestamp");
		puts("                                  (can be repeated)");
		puts("");
		puts("  -t, --expand-tabs             expand tabs to spaces in output");
		puts("  -T, --initial-tab             make tabs line up by prepending a tab");
		puts("      --tabsize=NUM             tab stops every NUM (default 8) print columns");
		puts("      --suppress-blank-empty    suppress space or tab before empty output lines");
		puts("  -l, --paginate                pass output through 'pr' to paginate it");
		puts("");
		puts("  -r, --recursive                 recursively compare any subdirectories found");
		puts("      --no-dereference            don't follow symbolic links");
		puts("  -N, --new-file                  treat absent files as empty");
		puts("      --unidirectional-new-file   treat absent first files as empty");
		puts("      --ignore-file-name-case     ignore case when comparing file names");
		puts("      --no-ignore-file-name-case  consider case when comparing file names");
		puts("  -x, --exclude=PAT               exclude files that match PAT");
		puts("  -X, --exclude-from=FILE         exclude files that match any pattern in FILE");
		puts("  -S, --starting-file=FILE        start with FILE when comparing directories");
		puts("      --from-file=FILE1           compare FILE1 to all operands;");
		puts("                                    FILE1 can be a directory");
		puts("      --to-file=FILE2             compare all operands to FILE2;");
		puts("                                    FILE2 can be a directory");
		puts("");
		puts("  -i, --ignore-case               ignore case differences in file contents");
		puts("  -E, --ignore-tab-expansion      ignore changes due to tab expansion");
		puts("  -Z, --ignore-trailing-space     ignore white space at line end");
		puts("  -b, --ignore-space-change       ignore changes in the amount of white space");
		puts("  -w, --ignore-all-space          ignore all white space");
		puts("  -B, --ignore-blank-lines        ignore changes where lines are all blank");
		puts("  -I, --ignore-matching-lines=RE  ignore changes where all lines match RE");
		puts("");
		puts("  -a, --text                      treat all files as text");
		puts("      --strip-trailing-cr         strip trailing carriage return on input");
		puts("");
		puts("  -D, --ifdef=NAME                output merged file with '#ifdef NAME' diffs");
		puts("      --GTYPE-group-format=GFMT   format GTYPE input groups with GFMT");
		puts("      --line-format=LFMT          format all input lines with LFMT");
		puts("      --LTYPE-line-format=LFMT    format LTYPE input lines with LFMT");
		puts("    These format options provide fine-grained control over the output");
		puts("      of diff, generalizing -D/--ifdef.");
		puts("    LTYPE is 'old', 'new', or 'unchanged'.  GTYPE is LTYPE or 'changed'.");
		puts("    GFMT (only) may contain:");
		puts("      %<  lines from FILE1");
		puts("      %>  lines from FILE2");
		puts("      %=  lines common to FILE1 and FILE2");
		puts("      %[-][WIDTH][.[PREC]]{doxX}LETTER  printf-style spec for LETTER");
		puts("        LETTERs are as follows for new group, lower case for old group:");
		puts("          F  first line number");
		puts("          L  last line number");
		puts("          N  number of lines = L-F+1");
		puts("          E  F-1");
		puts("          M  L+1");
		puts("      %(A=B?T:E)  if A equals B then T else E");
		puts("    LFMT (only) may contain:");
		puts("      %L  contents of line");
		puts("      %l  contents of line, excluding any trailing newline");
		puts("      %[-][WIDTH][.[PREC]]{doxX}n  printf-style spec for input line number");
		puts("    Both GFMT and LFMT may contain:");
		puts("      %%  %");
		puts("      %c'C'  the single character C");
		puts("      %c'\\OOO'  the character with octal code OOO");
		puts("      C    the character C (other characters represent themselves)");
		puts("");
		puts("  -d, --minimal            try hard to find a smaller set of changes");
		puts("      --horizon-lines=NUM  keep NUM lines of the common prefix and suffix");
		puts("      --speed-large-files  assume large files and many scattered small changes");
		puts("      --color[=WHEN]       colorize the output; WHEN can be 'never', 'always',");
		puts("                             or 'auto' (the default)");
		puts("      --palette=PALETTE    the colors to use when --color is active; PALETTE is");
		puts("                             a colon-separated list of terminfo capabilities");
		puts("");
		puts("      --help               display this help and exit");
		puts("  -v, --version            output version information and exit");
		puts("");
		puts("FILES are 'FILE1 FILE2' or 'DIR1 DIR2' or 'DIR FILE' or 'FILE DIR'.");
		puts("If --from-file or --to-file is given, there are no restrictions on FILE(s).");
		puts("If a FILE is '-', read standard input.");
		puts("Exit status is 0 if inputs are the same, 1 if different, 2 if trouble.");
		puts("");
		puts("Report bugs to: bug-diffutils@gnu.org");
		puts("GNU diffutils home page: <http://www.gnu.org/software/diffutils/>");
		puts("General help using GNU software: <http://www.gnu.org/gethelp/>");

		return 1;
	}

	if (!strcmp(command[ 1 ], "help"))
	{
		puts("help: help [-dms] [pattern ...]");
		puts("    Display information about builtin commands.");
		puts("");
		puts("    Displays brief summaries of builtin commands.  If PATTERN is");
		puts("    specified, gives detailed help on all commands matching PATTERN,");
		puts("    otherwise the list of help topics is printed.");
		puts("");
		puts("    Options:");
		puts("      -d        output short description for each topic");
		puts("      -m        display usage in pseudo-manpage format");
		puts("      -s        output only a short usage synopsis for each topic matching");
		puts("                PATTERN");
		puts("");
		puts("    Arguments:");
		puts("      PATTERN   Pattern specifiying a help topic");
		puts("");
		puts("    Exit Status:");
		puts("    Returns success unless PATTERN is not found or an invalid option is given.");

		return 1;
	}

	if (!strcmp(command[ 1 ], "echo"))
	{
		puts("echo: echo [-neE] [arg ...]");
		puts("    Write argumentr to the standard output.");
		puts("");
		puts("    Display the ARGs, separated by a single space character and followed by a");
		puts("    newline, on the standard output.");
		puts("");
		puts("    Options:");
		puts("      -n        do not append a newline");
		puts("      -e        enable interpretation of the following backslash escapes");
		puts("      -E        explicitly suppress interpretation of backslash escapes");
		puts("");
		puts("    'echo' interprets the following backslash-escaped cvharacters:");
		puts("      \\a        alert (bell)");
		puts("      \\b        backspace");
		puts("      \\c        suppress further output");
		puts("      \\e        escape character");
		puts("      \\E        escape character");
		puts("      \\f        form feed");
		puts("      \\n        new line");
		puts("      \\r        carriage return");
		puts("      \\t        horizontal tab");
		puts("      \\v        vertical tab");
		puts("      \\\\        backslash");
		puts("      \\0nnn     the character whose ASCII code is NNN (octal).  NNN can be");
		puts("                0 to 3 octal digits");
		puts("      \\xHH      the eight-bit character whose value is HH (hexadecimal).  HH");
		puts("                can be one or two hex digits");
		puts("");
		puts("    Exit Status:");
		puts("    Returns success unless a write error occurs.");

		return 1;
	}

	if (!strcmp(command[ 1 ], "head"))
	{
		puts("Usage: head [OPTION]... [FILE]...");
		puts("Print the first 10 lines of each FILE to standard output.");
		puts("With more than one FILE, precede each with a header giving the file name.");
		puts("");
		puts("With no FILE, or when FILE is -, read standard input.");
		puts("");
		puts("Mandatory arguments to long options are mandatory for short options too.");
		puts("  -c, --bytes=[-]NUM       print the first NUM bytes of each file;");
		puts("                             with the leading '-', print all but the last");
		puts("                             NUM bytes of each file");
		puts("  -n, --lines=[-]NUM       print the first NUM lines instead of the first 10;");
		puts("                             with the leading '-', print all but the last");
		puts("                             NUM lines of each file");
		puts("  -q, --quiet, --silent    never print headers giving file names");
		puts("  -v, --verbose            always print headers giving file names");
		puts("  -z, --zero-terminated    line delimiter is NUL, not newline");
		puts("      --help     display this help and exit");
		puts("      --version  output version information and exit");
		puts("");
		puts("NUM may have a multiplier suffix:");
		puts("b 512, kB 1000, K 1024, MB 1000*1000, M 1024*1024,");
		puts("GB 1000*1000*1000, G 1024*1024*1024, and so on for T, P, E, Z, Y.");
		puts("");
		puts("GNU coreutils online help: <http://www.gnu.org/software/coreutils/>");
		puts("Full documentation at: <http://www.gnu.org/software/coreutils/head>");
		puts("or available locally via: info '(coreutils) head invocation'");

		return 1;
	}

	if (!strcmp(command[ 1 ], "touch"))
	{
		puts("Usage: touch [OPTION]... FILE...");
		puts("Update the access and modification times of each FILE to the current time.");
		puts("");
		puts("A FILE argument that does not exist is created empty, unless -c or -h");
		puts("is supplied.");
		puts("");
		puts("A FILE argument string of - is handled specially and causes touch to");
		puts("change the times of the file associated with standard output.");
		puts("");
		puts("Mandatory arguments to long options are mandatory for short options too.");
		puts("  -a                     change only the access time");
		puts("  -c, --no-create        do not create any files");
		puts("  -d, --date=STRING      parse STRING and use it instead of current time");
		puts("  -f                     (ignored)");
		puts("  -h, --no-dereference   affect each symbolic link instead of any referenced");
		puts("                         file (useful only on systems that can change the");
		puts("                         timestamps of a symlink)");
		puts("  -m                     change only the modification time");
		puts("  -r, --reference=FILE   use this file's times instead of current time");
		puts("  -t STAMP               use [[CC]YY]MMDDhhmm[.ss] instead of current time");
		puts("      --time=WORD        change the specified time:");
		puts("                           WORD is access, atime, or use: equivalent to -a");
		puts("                           WORD is modify or mtime: equivalent to -m");
		puts("      --help     display this help and exit");
		puts("      --version  output version information and exit");
		puts("");
		puts("Note that the -d and -t options accept different time-date formats.");
		puts("");
		puts("GNU coreutils online help: <http://www.gnu.org/software/coreutils/>");
		puts("Full documentation at: <http://www.gnu.org/software/coreutils/touch>");
		puts("or available locally via: info '(coreutils) touch invocation'");

		return 1;
	}

	if (!strcmp(command[ 1 ], "history"))
	{
		puts("history: history [-c] [-d offset] [n] or history -anrw [filename] or history -ps arg [arg...]");
		puts("    Display or manipulate the history list.");
		puts("");
		puts("    Display the history list with line numbers, prefixing each modified");
		puts("    entry with a `*'.  An argument of N lists only the last N entries.");
		puts("");
		puts("    Options:");
		puts("      -c        clear the history list by deleting all of the entries");
		puts("      -d offset delete the history entry at position OFFSET.");
		puts("");
		puts("      -a        append history lines from this session to the history file");
		puts("      -n        read all history lines not already read from the history file");
		puts("                and append them to the history list");
		puts("      -r        read the history file and append the contents to the history");
		puts("                list");
		puts("      -w        write the current history to the history file");
		puts("");
		puts("      -p        perform history expansion on each ARG and display the result");
		puts("                without storing it in the history list");
		puts("      -s        append the ARGs to the history list as a single entry");
		puts("");
		puts("    If FILENAME is given, it is used as the history file.  Otherwise,");
		puts("    if HISTFILE has a value, that is used, else ~/.bash_history.");
		puts("");
		puts("    If the HISTTIMEFORMAT variable is set and not null, its value is used");
		puts("    as a format string for strftime(3) to print the time stamp associated");
		puts("    with each displayed history entry.  No time stamps are printed otherwise.");
		puts("");
		puts("    Exit Status:");
		puts("    Returns success unless an invalid option is given or an error occurs.");

		return 1;
	}

	fprintf(stderr, "bash: help: no topics match '%s'. Try 'help help'\n", command[ 1 ]);
	return 2;
}
