#include "main.h"

void	ft_cd(mini_t *mini, char **env)
{
	if (!mini->piped_command[1])
		mini->piped_command[1] = ft_strdup("/home/oussama");
	if (chdir(mini->piped_command[1]) == -1)
	{
		printf("cd: no such file or directory: %s\n", mini->piped_command[1]);
		int i = 0;
		while (mini->piped_command[i])
			free(mini->piped_command[i++]);
		free(mini->piped_command);
		return ;
	}
}

void ft_pwd(mini_t *mini, char **env)
{
	char cwd[1024];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("%s\n", cwd);
    else
        printf("%s\n", mini->current_path);
}