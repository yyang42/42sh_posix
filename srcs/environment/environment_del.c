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

#include <stdlib.h>

#include "environment.h"

static void			clear_environment(void *data)
{
	twl_strdel(&((t_environment_var *)data)->key);
	twl_strdel(&((t_environment_var *)data)->value);
}

void				environment_del(t_environment *this)
{
	twl_lst_del(this->env_vars, clear_environment);
	free(this);
}
