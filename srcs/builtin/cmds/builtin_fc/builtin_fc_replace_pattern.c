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

#include "builtin/cmds/builtin_fc.h"

char		*builtin_fc_replace_pattern(char *command, char *pattern)
{
	char		*old;
	char		*new;
	char		*ret;
	size_t		index;

	if (!pattern)
		return (twl_strdup(command));
	index = 0;
	while (pattern[index] && pattern[index] != '=')
		index += 1;
	old = twl_strndup(pattern, index);
	new = pattern[index] ? pattern + index + 1 : pattern + index;
	ret = twl_str_replace_first(command, old, new);
	free(old);
	return (ret);
}
