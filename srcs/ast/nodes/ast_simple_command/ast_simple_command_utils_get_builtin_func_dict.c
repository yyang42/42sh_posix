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

#include "ast/nodes/ast_simple_command.h"
#include "builtin/builtin.h"

t_dict				*ast_simple_command_utils_get_builtin_func_dict(void)
{
	t_dict *dict;

	dict = twl_dict_new();
	twl_dict_add(dict, ".", &builtin_dot_exec);
	twl_dict_add(dict, "alias", &builtin_alias_exec);
	twl_dict_add(dict, "cd", &builtin_cd_exec);
	twl_dict_add(dict, "echo", &builtin_echo_exec);
	twl_dict_add(dict, "env", &builtin_env_exec);
	twl_dict_add(dict, "eval", &builtin_eval_exec);
	twl_dict_add(dict, "exit", &builtin_exit_exec);
	twl_dict_add(dict, "export", &builtin_export_exec);
	twl_dict_add(dict, "false", &builtin_false_exec);
	twl_dict_add(dict, "jobs", &builtin_jobs_exec);
	twl_dict_add(dict, "readonly", &builtin_readonly_exec);
	twl_dict_add(dict, "set", &builtin_set_exec);
	twl_dict_add(dict, "setenv", &builtin_setenv_exec);
	twl_dict_add(dict, "shift", &builtin_shift_exec);
	twl_dict_add(dict, "times", &builtin_times_exec);
	twl_dict_add(dict, "true", &builtin_true_exec);
	twl_dict_add(dict, "umask", &builtin_umask_exec);
	twl_dict_add(dict, "unset", &builtin_unset_exec);
	twl_dict_add(dict, "unsetenv", &builtin_unsetenv_exec);
	return (dict);
}
