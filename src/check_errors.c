/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melfersi <melfersi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:06:36 by melfersi          #+#    #+#             */
/*   Updated: 2024/05/02 07:10:22 by melfersi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_token	*ft_check_errors(t_token *token)
{
	if (!syntax_error(token))
	{
		ft_putendl_fd("syntax error", 2);
		g_exit_status = 258;
		return (NULL);
	}
	return (token);
}
