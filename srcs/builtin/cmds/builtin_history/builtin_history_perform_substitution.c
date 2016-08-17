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
#include "edit/event.h"

static void		iter_fn(void *data)
{
	char		*expand;

	expand = event_expand_history_string(data);
	if (expand)
	{
		twl_printf("%s\n", expand);
		free(expand);
	}
}

void			builtin_history_perform_substitution(t_argparser_result *result)
{
	history_pop_last(edit_singleton()->history);
	twl_lst_iter0(result->remainders, iter_fn);
}
