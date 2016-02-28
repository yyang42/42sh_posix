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

#include "arexp/nodes/arexp_additive.h"

static void		call_bash(void *add_)
{
	t_arexp_additive__	*add;

	add = add_;
	if (add->additive_sign)
		token_del(add->additive_sign);
	if (add->multiplicative)
		arexp_multiplicative_del(add->multiplicative);
	free(add);
}

void			arexp_additive_del(t_arexp_additive *additive)
{
	if (!additive)
		return ;
	if (additive->multiplicative)
		twl_lst_del(additive->multiplicative, call_bash);
	free(additive);
}
