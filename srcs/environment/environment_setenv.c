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
#include "twl_arr.h"

void				environment_setenv(t_environment *this, char *str)
{
	char				**tab;
	char				*tmp;

	tab = twl_strsplit(str, '=');
	if (!tab[0])
		return ;
	if (!tab[1])
		tmp = twl_strdup("");
	if (environment_get_env_value(this, tab[0]))
		environment_set_env_value(this, tab[0], tab[1] ? tab[1] : tmp);
	else
		twl_lst_push(this->env_vars, environment_var_new(str, LOCAL));
	twl_arr_del(tab, free);
}
