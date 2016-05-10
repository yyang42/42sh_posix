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

#include "shenv/shflag_mgr.h"

void				shflag_mgr_set_state_by_long_sign(t_lst *shflags, char *long_form, char sign)
{
	t_shflag		*shflag;

	shflag = shflag_mgr_find_by_long(shflags, long_form);
	if (shflag)
		shflag_set_state_by_sign(shflag, sign);
	else
		LOG_ERROR("shflag not found: %s", long_form);
}
