# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/global_variables.h"
# include "../lib/headers/style.h"
# include "../lib/headers/command.h"
# include "../lib/headers/input.h"



int
neofetch(void)
{
	printf("\033[1;31m            .-/+oossssoo+/-.               ");                                       printf("vinicius@Ubuntu-18\n");
	printf("\033[1;31m        `:+ssssssssssssssssss+:`           ");                                       printf("\033[1;0m------------------\n");
	printf("\033[1;31m      -+ssssssssssssssssssyyssss+-         ");                                       printf("OS\033[0;0m");         printf(": Ubuntu 18.04 LTS x86_64\n");
	printf("\033[1;31m    .ossssssssssssssssss\033[1;0mdMMMNy\033[1;31msssso.       ");                    printf("Host\033[0;0m");       printf(": Inspiron 15-7579\n");
	printf("\033[1;31m   /sssssssssss\033[1;0mhdmmNNmmyNMMMMh\033[1;31mssssss/      ");                    printf("Kernel\033[0;0m");     printf(": 4.15.0-24-generic\n");
	printf("\033[1;31m  +sssssssss\033[1;0mhm\033[1;31myd\033[1;0mMMMMMMMNddddy\033[1;31mssssssss+     "); printf("Uptime\033[0;0m");     printf(": 1 day, 2 hours, 41 mins\n");
	printf("\033[1;31m /ssssssss\033[1;0mhNMMM\033[1;31myh\033[1;0mhyyyyhmNMMMNh\033[1;31mssssssss/    "); printf("Packages\033[0;0m");   printf(": 1985\n");
	printf("\033[1;31m.ssssssss\033[1;0mdMMMNh\033[1;31msssssssss\033[1;0mshNMMMd\033[1;31mssssssss.   "); printf("Shell\033[0;0m");      printf(": bash 4.4.19\n");
	printf("\033[1;31m+ssss\033[1;0mhhhyNMMNy\033[1;31mssssssssssss\033[1;0myNMMMy\033[1;31msssssss+   "); printf("Resolution\033[0;0m"); printf(": 1920x1080\n");
	printf("\033[1;31moss\033[1;0myNMMMNyMMh\033[1;31mssssssssssssss\033[1;0mhmmmh\033[1;31mssssssso   "); printf("DE\033[0;0m");         printf(": GNOME 3.28.1\n");
	printf("\033[1;31moss\033[1;0myNMMMNyMMh\033[1;31msssssssssssssshmmmhssssssso   ");                    printf("WM\033[0;0m");         printf(": GNOME Shell\n");
	printf("\033[1;31m+ssss\033[1;0mhhhyNMMNy\033[1;31mssssssssssss\033[1;0myNMMMy\033[1;31msssssss+   "); printf("WM Theme\033[0;0m");   printf(": Adwaita\n");
	printf("\033[1;31m.ssssssss\033[1;0mdMMMNh\033[1;31mssssssssss\033[1;0mhNMMMd\033[1;31mssssssss.   "); printf("Theme\033[0;0m");      printf(": Ambiance [GTK2/3]\n");
	printf("\033[1;31m /ssssssss\033[1;0mhNMMM\033[1;31myh\033[1;0mhyyyyhdNMMMNh\033[1;31mssssssss/    "); printf("Icons\033[0;0m");      printf(": Ubuntu-mono-light [GTK2/3]\n");
	printf("\033[1;31m  +sssssssss\033[1;0mdm\033[1;31myd\033[1;0mMMMMMMMMddddy\033[1;31mssssssss+     "); printf("Terminal\033[0;0m");   printf(": gnome-terminal\n");
	printf("\033[1;31m   /sssssssssss\033[1;0mhdmNNNNmyNMMMMh\033[1;31mssssss/      ");                    printf("CPU\033[0;0m");        printf(": Intel i5-7200U (4) @ 3.100GHz\n");
	printf("\033[1;31m    .ossssssssssssssssss\033[1;0mdMMMNy\033[1;31msssso.       ");                    printf("GPU\033[0;0m");        printf(": Intel HD Graphics 620\n");
	printf("\033[1;31m      -+sssssssssssssssss\033[1;0myyy\033[1;31mssss+-         ");                    printf("Memory\033[0;0m");     printf(": 1578MiB / 7715MiB\n");
	printf("\033[1;31m        `:+ssssssssssssssssss+:`\n");
	printf("\033[1;31m            .-/+oossssoo+/-.\n\n\n\033[0;0m");
	return 1;
}
