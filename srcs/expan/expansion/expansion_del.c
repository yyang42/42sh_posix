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

static void		iter_del_fn(void *data)
{
	twl_lst_del(data, expan_before_split_del);
}

void			expansion_del(t_expansion *this)
{
	if (!this)
		return ;
	if (this->tokens)
		twl_lst_del(this->tokens, expan_token_del);
	if (this->before_split)
	{
		twl_lst_iter0(this->before_split, iter_del_fn);
		twl_lst_del(this->before_split, NULL);
	}
	if (this->to_push_bs)
		twl_lst_del(this->to_push_bs, expan_before_split_del);
	if (this->after_split)
		twl_lst_del(this->after_split, free);
	if (this->patmatch)
		twl_lst_del(this->patmatch, free);
	if (this->error)
		free(this->error);
	free(this->to_push_as);
	free(this);
}
