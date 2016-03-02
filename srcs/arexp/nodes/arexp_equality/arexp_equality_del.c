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

#include "arexp/nodes/arexp_equality.h"

static void				fn_del(void *eq_)
{
	t_arexp_equality__	*eq;

	eq = eq_;
	if (eq->equality_sign)
		token_del(eq->equality_sign);
	if (eq->relational)
		arexp_relational_del(eq->relational);
	free(eq);
}

void					arexp_equality_del(t_arexp_equality *equality)
{
	if (!equality)
		return ;
	if (equality->relational)
		twl_lst_del(equality->relational, fn_del);
	free(equality);
}
