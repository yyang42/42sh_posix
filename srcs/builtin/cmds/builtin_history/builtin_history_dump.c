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

#include "builtin/cmds/builtin_history.h"
#include "shenv/shenv.h"
#include "edit/edit.h"
#include "edit/history.h"
#include "twl_ctype.h"

static bool		is_numeric(char *s)
{
	while (*s && twl_isspace(*s))
		s += 1;
	if (*s == '+' || *s == '-')
		s += 1;
	while (*s && twl_isdigit(*s))
		s += 1;
	if (*s && !twl_isspace(*s))
		return (false);
	while (*s && twl_isspace(*s))
		s += 1;
	return (!*s);
}

void			builtin_history_dump(t_argparser_result *result)
{
	char		*first;
	
	first = twl_lst_first(result->remainders);
	if (!first)
	{
		history_dump(edit_singleton()->history);
		return ;
	}
	if (!is_numeric(first))
	{
		shenv_singl_error(1, "history: %s: numeric argument required", first);
		return ;
	}
	history_dump_last(edit_singleton()->history, twl_atoi(first));
}
