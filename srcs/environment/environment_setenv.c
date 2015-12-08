/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include <stdio.h>

void				environment_setenv(t_environment *this, char *str)
{
	t_lst_elem__		*temp;
	// char	*key;
	char	*value;

	value = twl_strchr(str, '=');
	if (!value)
		return ;
	temp = this->env_vars->head;
	while (temp)
	{
		printf("%s\n", ((t_environment_var*)temp->data)->key);
		temp = temp->next;
	}
}
