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

#include "token/token_mgr.h"
#include "data_utils.h"

static void		fn_iter2n(void *data_, void *next_, void *assign_,
												void *is_assign_extracted_)
{
	t_token		*data;
	t_token		*next;
	t_token		***assign;
	bool		*is_assign_extracted;

	data = data_;
	next = next_;
	assign = assign_;
	is_assign_extracted = is_assign_extracted_;
	if (*assign == NULL || *is_assign_extracted == true)
		return ;
	if (data->type == TOK_AREXP_VARIABLE && next != NULL &&
			data_utils_arexp_is_assign(next->text))
	{
		(*assign)[0] = data;
		(*assign)[1] = next;
		(*is_assign_extracted) = true;
		return ;
	}
	if (!data_utils_arexp_is_unary_operator(next->text))
	{
		free(*assign);
		*assign = NULL;
	}
}

t_token			**token_mgr_arexp_extract_assign(t_lst *tokens)
{
	t_token		**assign;
	t_token		*pop;
	bool		is_assign_extracted;

	assign = twl_malloc_x0(sizeof(t_token *) * 2);
	is_assign_extracted = false;
	twl_lst_iter2n(tokens, fn_iter2n, &assign, &is_assign_extracted);
	if (assign == NULL)
		return (NULL);
	if (is_assign_extracted == false)
	{
		free(assign);
		return (NULL);
	}
	while (1)
	{
		pop = twl_lst_pop_back(tokens);
		if (pop == assign[1])
			break ;
		if (pop != assign[0])
			token_del(pop);
	}
	return (assign);
}
