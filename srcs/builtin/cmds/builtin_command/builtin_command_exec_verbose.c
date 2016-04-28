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

#include "builtin/cmds/builtin_alias.h"
#include "builtin/cmds/builtin_command.h"
#include "builtin/builtin_mgr.h"
#include "data.h"
#include "shenv/shenv.h"

static bool		is_an_alias(char *cmd_name, t_shenv *shenv)
{
	char		*alias;

	if ((alias = builtin_alias_get(cmd_name, shenv)))
	{
		twl_printf("alias %s='%s'\n", cmd_name, alias);
		return (true);
	}
	return (false);
}

static bool		is_a_function(char *cmd_name, t_shenv *shenv)
{
	if (shenv_shfuncs_get(shenv, cmd_name))
	{
		twl_printf("%s\n", cmd_name);
		return (true);
	}
	return (false);
}

static bool		is_a_builtin(char *cmd_name, t_shenv *shenv)
{
	if (builtin_mgr_find_by_name(data_builtins(), cmd_name))
	{
		twl_printf("%s\n", cmd_name);
		return (true);
	}
	return (false);
	(void)shenv;
}

static bool		is_in_path(char *cmd_name, t_shenv *shenv)
{
	char		*path;

	path = shenv_find_binary_path(shenv, cmd_name);
	if (path)
	{
		twl_printf("%s\n", path);
		return (true);
	}
	return (false);
}

void			builtin_command_exec_verbose(t_argparser_result *result,
													t_shenv *shenv)
{
	t_lst		*remainders_copy;
	char		*cmd_name;
	int			ret;

	remainders_copy = twl_lst_copy(result->remainders, NULL);
	ret = 1;
	while ((cmd_name = twl_lst_pop_front(remainders_copy)))
	{
		if (is_an_alias(cmd_name, shenv))
			continue ;
		if (is_a_function(cmd_name, shenv))
			continue ;
		if (is_a_builtin(cmd_name, shenv))
			continue ;
		if (is_in_path(cmd_name, shenv))
			continue ;
		ret = 0;
	}
	twl_lst_del(remainders_copy, NULL);
	shenv->last_exit_code = ret;
}
