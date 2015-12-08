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

char				*environment_get_env_value(t_environment *this, char *key)
{
	t_lst_elem__	*temp;

	temp = this->env_vars->head;
	while (temp)
	{
		if (!twl_strcmp(((t_environment_var*)temp->data)->key, key))
			return (((t_environment_var*)temp->data)->value);
		temp = temp->next;
	}
	return (NULL);
}
