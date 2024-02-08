#include "main.h"

void	handler(int signal_num)
{
	write(1, "\n" ANSI_COLOR_YELLOW "→" ANSI_COLOR_RESET " ", 14);
	return ;
}
void nothing()
{
printf(" ");

}
void	signals_handle(void)
{
	if (signal(SIGINT, handler) == SIG_ERR)
	{
		perror("signal");
		return ;
	}
    if (signal(SIGQUIT, nothing) == SIG_ERR)
	{
		perror("signal");
		return ;
	}
}