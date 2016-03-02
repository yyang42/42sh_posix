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

#include "arexp/nodes/arexp_shift.h"

static void		fn_del(void *sh_)
{
	t_arexp_shift__	*sh;

	sh = sh_;
	if (sh->shift_sign)
		token_del(sh->shift_sign);
	if (sh->additive)
		arexp_additive_del(sh->additive);
	free(sh);
}

void			arexp_shift_del(t_arexp_shift *shift)
{
	if (!shift)
		return ;
	if (shift->additive)
		twl_lst_del(shift->additive, fn_del);
	free(shift);
}
