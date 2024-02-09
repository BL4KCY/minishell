#include "main.h"

void	check_builtin(mini_t *mini, char **env, int exit_status)
{
	mini->piped_command = ft_split(mini->cmd, ' ');
	if (!mini->piped_command)
		return ;
	if (cmp(mini->piped_command[0], "cd", 2) == 0)
        ft_cd(mini, env);
    else if (cmp(mini->cmd, "exit", 4) == 0)
        exit(EXIT_SUCCESS);
    else if (cmp(mini->piped_command[0], "echo", 4) == 0)
        ft_echo(mini, env, exit_status);
}