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

static void			create_and_export_shvar(t_shenv *shenv, char *key, char *value, char *command_name)
{
	t_shvar			*shvar;

	if (!token_utils_is_valid_name(key))
	{
		twl_dprintf(2, "%s: `%s': not a valid identifier\n", command_name, key);
		shenv_set_last_exit_status(shenv, BUILTIN_EXEC_FAILURE);
		return ;
	}
	shvar = shvar_mgr_find_or_create(shenv->shvars, key);
	shvar->shvar_exported = true;
	if (value)
	{
		shvar_set_value(shvar, value);
	}
}

void				iter_fn(void *str_token, void *shenv_, void *command_name)
{
	t_lst			*segs;
	t_shenv			*shenv;
	char			*key;
	char			*value;

	shenv = shenv_;
	if (twl_strchr(str_token, '='))
	{
		segs = twl_str_split_once_to_lst(str_token, "=");
		key = twl_strdup(twl_lst_get(segs, 0));
		value = twl_strdup(twl_lst_get(segs, 1));
		twl_lst_del(segs, free);
	}
	else
	{
		key = str_token;
		value = NULL;
	}
	create_and_export_shvar(shenv, key, value, command_name);
}

void				builtin_export_exec_export_tokens(t_argparser_result *argparser_result, t_shenv *shenv)
{
	twl_lst_iter2(argparser_result->remainders, iter_fn, shenv, argparser_result->command_name);
}
