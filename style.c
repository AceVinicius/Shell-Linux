# include "./headers/include.h"
# include "./headers/define.h"
# include "./headers/global_variables.h"
# include "./headers/style.h"
# include "./headers/command.h"
# include "./headers/input.h"



void
style(const int type,
      const int text_color)
{
    printf("\033[%d;%dm", type, text_color);
}



void
reset(void)
{
    printf("\033[0;0m");
}



void
place(const int x,
      const int y)
{
    printf("\033[%d;%dH", y+1, x+1);
}
