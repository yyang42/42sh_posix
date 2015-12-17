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

bool  is_builtin(char *cmd)
{
	int i;
	static const char *builtins[22] = {"echo", "cd", "env", "unsetenv",
	"setenv", "alias", "unalias", "false", "true", "umask", "newgrp" ,"fc",
	"command", "kill", "getopts", "read", "break", "colon", "continue", "return",
	"return", "shift"};

	i = 0;
	while (i < 22)
	{
		if (twl_strcmp(cmd, builtins[i]) == 0)
			return (true);
		i++;
	}
	return (false);
}
