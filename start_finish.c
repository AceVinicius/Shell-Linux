# include "./headers/include.h"
# include "./headers/define.h"
# include "./headers/global_variables.h"
# include "./headers/style.h"
# include "./headers/command.h"
# include "./headers/input.h"



void
start(void)
{
	system("clear");

 	style(ITALIC,
		  PURPLE);
 		puts("");
 		puts("                Linux shell Development");
 		puts("");
 		puts("          Created by Vinícius Ferreira Aguiar");
 		puts("");
 		puts("This shell was created to improve my knowledge creating");
 		puts("something very different from everything I've ever cre-");
 		puts("ated. That was not an easy job ..");
 		puts("");
 		puts("                    Hope you enjoy!");
 		puts("");
 		puts("                                          Version 1.0.0");
 		puts("");
 	reset();
}



void
finish(void)
{
 	style(ITALIC,
		  PURPLE);
 		puts("");
 		puts("              Goodbye!! Hope you enjoyed.");
 		puts("");
 		puts("                                          Version 1.0.0");
 		puts("");
 	reset();
}
