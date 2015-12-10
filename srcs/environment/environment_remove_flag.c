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

#include "set.h"
#include "environment.h"
#include "twl_dict.h"
#include "twl_opt_elem.h"

static bool			find_opt(void *data, void *key)
{
	t_opt_elem *elem;

	elem = data;
	return (twl_strcmp(elem->key, key) == 0);
}


static void			free_opt(void *data)
{
	t_opt_elem *elem;

	elem = data;
	if (elem->key)
		free(elem->key);
	if (elem->value)
		free(elem->value);
}
void				environment_remove_flag(char *flag, t_environment *env)
{
	twl_lst_remove_if(env->flags, find_opt, flag, free_opt);
}
