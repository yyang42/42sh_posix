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

#include "builtin/cmds/builtin_export.h"
#include "shenv/shenv.h"
#include "shenv/shvar_mgr.h"
#include "twl_opt.h"
#include "twl_lst.h"

static void			iter_fn(void *str_token, void *shenv_)
{
	t_lst			*segs;
	t_shenv			*shenv;

	shenv = shenv_;
	if (twl_strchr(str_token, '='))
	{
		segs = twl_str_split_once_to_lst(str_token, "=");
		shenv_setenv_key_value(shenv, twl_lst_get(segs, 0), twl_lst_get(segs, 1));
		twl_lst_del(segs, free);
	}
	else
	{
		shvar_mgr_find_or_create(shenv->shvars, str_token)->shvar_exported = true;
	}
}

void				builtin_export_add(t_shenv *shenv, t_lst *remaining_tokens)
{
	twl_lst_iter(remaining_tokens, iter_fn, shenv);
}
