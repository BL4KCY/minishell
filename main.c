#include "main.h"

void free_token(t_token *token)
{
	int	i;
	while (token)
	{
		free(token->content);
		free(token);
		if (token->arr)
		{
			i = 0;
			while (token->arr[i])
				free(token->arr[i++]);
			free(token->arr);
		}
		token = token->next;
	}
}
int	cmd_exe(t_token *token, t_env **env)
{
	t_token	*new_token;
	t_token	*cmd_list;
	char	*cmd;

	cmd = readline("$ ");
	if (!cmd)
		return (printf("exit\n"), 1);
	add_history(cmd);
	if (!tokenizer(cmd, &token, env))
		return (0);
	if (!ft_check_errors(token))
		return (free_token(token), 0);
	new_token = expanding(token, env);
	if (!new_token)
		return (free_token(new_token), 0);
	cmd_list = ft_list(new_token, env);
	if (!cmd_list)
		return (free_token(cmd_list),0);
	if (!execution(cmd_list, env))
		return (free_token(cmd_list), 0);
	return 0;
}

int	main(int ac, char *av[], char *envp[])
{
	t_env	*env;

	env = envir(envp);
	if (!env)
		return (printf("exit\n"), EXIT_FAILURE);
	while (!cmd_exe(NULL, &env))
		;
	env_clear(&env);
	rl_clear_history();
	// system("leaks minishell");
	return (EXIT_SUCCESS);
}
