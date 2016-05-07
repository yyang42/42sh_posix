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

void				brace_recurs(t_brace *this, t_lst_elem__ *elem, char *acc)
{
	t_brace_token	*token;

	if (!elem)
	{
		twl_lst_push_front(this->final, acc);
		return ;
	}
	token = elem->data;
	if (token->type == BRACE_IGNORE)
		brace_recurs_ignore(this, elem, token, acc);
	else if (token->type == BRACE_LIST)
		brace_recurs_list(this, elem, token, acc);
	else
		brace_recurs_sequence(this, elem, token, acc);
}
