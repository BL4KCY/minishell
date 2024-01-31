#include "main.h"
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src [j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char *ft_path(char **env)
{
    int i = 0;
    char **args;
    while (env[i])
    {
        args = ft_split(env[i], '=');
        if (strcmp(args[0], "PATH") == 0)
            return args[1];
        free(args[0]);
        free(args[1]);
        i++;
    }
    return NULL;
}
char *ft_getpath(char *cmd, char **env)
{
    if (cmd[0] == '/')
    {
        if (access(cmd, X_OK) == 0)
            return cmd;
        else
            return NULL;
    }
    char *str = ft_path(env);
    char **splited = ft_split(str, ':');
    char *path;
    int i = 0;
    while (splited[i])
    {
        path = ft_strjoin(ft_strcat(splited[i], "/"), cmd);
        if (access(path, X_OK) == 0)
            return path;
        i++;
    }
    int j = 0;
    while (splited[j])
        free(splited[j++]);
    return NULL;
}

void signals_handle(char *cmd)
{
    // handle signals and parsing here (i guess)
    if (ft_strncmp(cmd, "exit", 4) == 0)
        exit(0);
}
void cmd_exe(mini_t *mini, char **env)
{
    mini->cmd = readline("→ ");
    int i = 0;
    while (mini->cmd[i] != ' ' && mini->cmd[i])
        i++;
    add_history(mini->cmd);
    signals_handle(mini->cmd);
    int pid = fork();
    if (pid == 0)
    {
        mini->args = ft_split(mini->cmd , ' ');
        mini->path = ft_getpath(mini->args[0], env);
        if (execve(mini->path, mini->args, env) == -1)
        {
            printf("command not found\n");
            free(mini->path);
        }
    }
    wait(NULL);

}
void execution(mini_t *mini, char **env)
{
    while (1)
    {
        cmd_exe(mini, env);
    }
    rl_clear_history();
}
int main(int ac , char *av[], char *env[])
{
    mini_t mini;
    
    execution(&mini, env);
}