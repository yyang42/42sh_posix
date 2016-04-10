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

void			expansion_push_before_split(t_expansion *this,
											char *text,
											bool quoted)
{
	t_expan_before_split	*ebs;

	if (!text)
		return ;
	ebs = expan_before_split_new(text, quoted);
	if (!this->to_push_bs)
		this->to_push_bs = twl_lst_new();
	twl_lst_push_back(this->to_push_bs, ebs);
}
