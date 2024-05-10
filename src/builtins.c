/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:53:16 by melfersi          #+#    #+#             */
/*   Updated: 2024/05/10 11:16:17 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	single_builtins(t_token *lst, t_env *env)
{
	lst->fd[0] = dup(STDIN_FILENO);
	lst->fd[1] = dup(STDOUT_FILENO);
	if (set_io(lst))
		return (reset_io(lst), 1);
	if (!lst->arr[0])
		return (reset_io(lst), 0);
	if (!ft_strcmp(lst->arr[0], "pwd"))
		return (reset_io(lst), pwd(env));
	if (!ft_strcmp(lst->arr[0], "echo"))
		return (reset_io(lst), echo(lst));
	if (!ft_strcmp(lst->arr[0], "cd"))
		return (reset_io(lst), cd(lst->arr, env));
	if (!ft_strcmp(lst->arr[0], "env"))
		return (reset_io(lst), print_env(env));
	if (!ft_strcmp(lst->arr[0], "export"))
		return (reset_io(lst), export(lst->arr, env));
	if (!ft_strcmp(lst->arr[0], "unset"))
		return (reset_io(lst), unset(lst, env));
	if (!ft_strcmp(lst->arr[0], "exit"))
		return (exiting(lst, env));
	return (reset_io(lst), (-2));
}

void	builtins(t_token *lst, t_env *env)
{
	if (!lst->arr[0])
		exit(1);
	if (!ft_strcmp(lst->arr[0], "pwd"))
		exit(pwd(env));
	if (!ft_strcmp(lst->arr[0], "echo"))
		exit(echo(lst));
	if (!ft_strcmp(lst->arr[0], "cd"))
		exit(cd(lst->arr, env));
	if (!ft_strcmp(lst->arr[0], "env"))
		exit(print_env(env));
	if (!ft_strcmp(lst->arr[0], "export"))
		exit(export(lst->arr, env));
	if (!ft_strcmp(lst->arr[0], "unset"))
		exit(unset(lst, env));
	if (!ft_strcmp(lst->arr[0], "exit"))
		exit(exiting(lst, env));
}

bool	check_valid_identifier(char *s)
{
	if (!ft_isalpha(*s) && *s != '_')
		return (false);
	while (*s)
	{
		if (!ft_isalnum(*s))
			return (false);
		s++;
	}
	return (true);
}
