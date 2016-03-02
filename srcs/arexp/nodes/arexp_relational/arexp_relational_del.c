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

#include "arexp/nodes/arexp_relational.h"

static void		fn_del(void *rel_)
{
	t_arexp_relational__	*rel;

	rel = rel_;
	if (rel->relational_sign)
		token_del(rel->relational_sign);
	if (rel->shift)
		arexp_shift_del(rel->shift);
	free(rel);
}

void			arexp_relational_del(t_arexp_relational *relational)
{
	if (!relational)
		return ;
	if (relational->shift)
		twl_lst_del(relational->shift, fn_del);
	free(relational);
}
