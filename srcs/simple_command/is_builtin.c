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

#include "simple_command.h"

static bool find_bultin(void *builtin_, void *cmd_)
{
	char	*builtin;
	char	*cmd;

	builtin = builtin_;
	cmd = cmd_;
	if (twl_strcmp(builtin, cmd) == 0)
		return (true);
	return (false);
}

bool  is_builtin(char *cmd)
{
	static const char	*builtins[26] = {"echo", "cd", "env", "unsetenv",
	"setenv", "alias", "unalias", "false", "true", "umask", "newgrp" ,"fc",
	"command", "kill", "getopts", "read", "break", "colon", "continue", "return",
	"return", "shift", "set", "unset", "export", NULL};

	if (twl_arr_find(builtins, find_bultin, cmd))
		return (true);
	return (false);
}
