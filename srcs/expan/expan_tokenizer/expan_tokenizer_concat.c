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

#include "basics.h"
#include "expan/expan_token.h"

char				*expan_tokenizer_concat(t_lst *lst)
{
	t_lst_elem__	*elem;
	t_lst_elem__	*next;
	t_expan_token	*token;
	char			*out;

	out = twl_strdup("");
	elem = lst->head;
	while (elem)
	{
		next = elem->next;
		token = elem->data;
		if (token && token->res)
			out = twl_strjoinfree(out, token->res, 'l');
		elem = next;
	}
	return (out);
}
