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

#include "expan/expansion.h"

/*
** TODO: cf TODO expansion_get_fields_dquote.c
*/

static void		iter_fn_wrap(void *data)
{
	t_expan_before_split	*ebs;

	ebs = expan_before_split_new("\"", false);
	twl_lst_push_back(data, ebs);
	ebs = expan_before_split_new("\"", false);
	twl_lst_push_front(data, ebs);
}

void			expansion_dquote(t_expansion *this, t_expan_token *token)
{
	char		*dquote;
	t_expansion	*inner;
	t_lst		*lst_inner;

	if (this->error)
		return ;
	dquote = twl_strndup(token->text + 1, twl_strlen(token->text + 2));
	inner = expansion_new_from_text(dquote);
	free(dquote);
	lst_inner = expansion_get_fields_dquote(inner);
	this->error = inner->error;
	inner->error = NULL;
	if (this->error)
		return ;
	twl_lst_iter0(lst_inner, iter_fn_wrap);
	expansion_push_lst_before_split(this, lst_inner);
}
