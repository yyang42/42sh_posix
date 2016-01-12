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
#include "builtin.h"

bool			isDoubleQuoted(char *str)
{
	int	len;
	if (str)
	{
		len = twl_strlen(str);
		if (twl_strlen(str) > 1)
		{
			if (str[0] == '"' && str[len] == '"')
				return (true);
		}
	}
	return (false);
}

bool			isSingleQuoted(char *str)
{
	int	len;
	if (str)
	{
		len = twl_strlen(str);
		if (twl_strlen(str) > 1)
		{
			if (str[0] == '\'' && str[len] == '\'')
				return (true);
		}
	}
	return (false);
}
