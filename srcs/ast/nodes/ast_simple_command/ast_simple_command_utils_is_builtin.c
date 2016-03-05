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
#include "data.h"

bool			ast_simple_command_utils_is_builtin(char *cmd_name)
{
	// static const char	*builtins[33] = {"echo", "cd", "env", "unsetenv"
	// , "setenv", "alias", "unalias", "false", "true", "umask", "newgrp", "fc"
	// , "command", "kill", "getopts", "read", "break", "colon", "continue"
	// , "return", "shift", "set", "unset", "export", "setenv", "times"
	// , "eval", ".", "readonly", "exit", "jobs", NULL};

	t_dict	*dict;

	dict = data_builtins();
	return twl_dict_get(dict, cmd_name);
}
