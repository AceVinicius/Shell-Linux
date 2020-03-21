# include "../lib/headers/include.h"
# include "../lib/headers/define.h"
# include "../lib/headers/global_variables.h"
# include "../lib/headers/style.h"
# include "../lib/headers/command.h"
# include "../lib/headers/input.h"



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
