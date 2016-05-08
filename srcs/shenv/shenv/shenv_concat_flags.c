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

#include "shenv/shenv.h"
#include "twl_string.h"
#include "twl_lst.h"
#include "twl_opt_elem.h"

static void			concat_flag(void *data, void *concat_ptr_)
{
	t_opt_elem	*elem;
	char		**concat_ptr;

	elem = data;
	concat_ptr = concat_ptr_;
	if (elem && elem->key)
	{
		*concat_ptr = twl_strjoinfree(*concat_ptr, elem->key, 'l');
	}
}

char				*shenv_concat_flags(t_shenv *env)
{
	char	*concat;

	concat = twl_strdup("");
	if (env && env->shenv_set_flags)
		twl_lst_iter(env->shenv_set_flags, concat_flag, &concat);
	return (concat);
}
