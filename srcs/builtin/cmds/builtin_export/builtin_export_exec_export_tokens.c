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
#include "token/token_utils.h"

static void			iter_fn(void *str_token, void *shenv, void *command_name)
{
	t_shvar			*shvar;

	shvar = shenv_shvars_set_split_by_equal(shenv, str_token, command_name);
	if (shvar)
		shvar->shvar_exported = true;
}

void				builtin_export_exec_export_tokens(t_argparser_result *argparser_result, t_shenv *shenv)
{
	twl_lst_iter2(argparser_result->remainders, iter_fn, shenv, argparser_result->command_name);
}
