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

int			environment_set_env_value(t_environment *this, char *key, char *value)
{
	t_lst_elem__	*temp;

	temp = this->env_vars->head;
	while (temp)
	{
		if (!twl_strcmp(((t_environment_var*)temp->data)->key, key))
		{
			if (((t_environment_var*)temp->data)->value)
				free(((t_environment_var*)temp->data)->value);
			((t_environment_var*)temp->data)->value = twl_strdup(value);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}
