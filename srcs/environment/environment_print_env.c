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

void		environment_print_env(t_environment *this)
{
	t_lst_elem__	*temp;

	temp = this->env_vars->head;
	while (temp)
	{
		if (((t_environment_var*)temp->data)->type == ENVIRONMENT)
			twl_printf("%s=%s\n", ((t_environment_var*)temp->data)->key,
				((t_environment_var*)temp->data)->key);
		temp = temp->next;
	}
}
