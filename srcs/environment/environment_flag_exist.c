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
#include "twl_lst.h"
#include "twl_opt_elem.h"

bool				check_flag(void *data, void *context)
{
	char		*flag;
	t_opt_elem	*elem;

	flag = context;
	elem = data;
	return (twl_strcmp(flag, elem->key) == 0);
}

int					environment_flag_exist(t_environment *this, char *flag)
{
	return (twl_lst_find(this->flags, check_flag, flag) ? 1 : 0);
}
