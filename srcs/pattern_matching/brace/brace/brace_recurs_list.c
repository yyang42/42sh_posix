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

#include "pattern_matching/brace/brace.h"

static void	expand_fn(t_brace *this, t_lst_elem__ *elem,
						char *content, char *acc)
{
	t_lst	*expand;
	t_lst	*copy;
	char	*tmp;

	expand = brace_expand(content);
	copy = twl_lst_copy(expand, NULL);
	while ((tmp = twl_lst_pop_front(copy)))
	{
		tmp = twl_strjoin(acc, tmp);
		brace_recurs(this, elem->next, tmp);
		free(tmp);
	}
	twl_lst_del(copy, NULL);
	twl_lst_del(expand, free);
}

void		brace_recurs_list(t_brace *this, t_lst_elem__ *elem,
								t_brace_token *token, char *acc)
{
	t_lst		*copy;
	char		*content;

	copy = twl_lst_copy(token->brace_list, NULL);
	while ((content = twl_lst_pop_front(copy)))
	{
		expand_fn(this, elem, content, acc);
	}
	twl_lst_del(copy, NULL);
}
