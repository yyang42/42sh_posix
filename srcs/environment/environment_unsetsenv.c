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

static void			clear_environment(void *data)
{
	twl_strdel(&((t_environment_var *)data)->key);
	twl_strdel(&((t_environment_var *)data)->value);
}

void				environment_unsetenv(t_environment *this, char *key)
{
	t_lst_elem__		*temp;

	temp = this->env_vars->head;
	while (temp)
	{
		if (!twl_strcmp(((t_environment_var *)temp->data)->key, key))
		{
			twl_lst_del_elem__(this->env_vars, temp, clear_environment);
			return ;
		}
		temp = temp->next;
	}
}
