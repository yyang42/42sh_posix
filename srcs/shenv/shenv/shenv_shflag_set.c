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

#include "shenv/shenv.h"
#include "shenv/shflag_mgr.h"
#include "twl_lst.h"
#include "twl_opt_elem.h"

void				shenv_shflag_set(t_shenv *this, char mono, bool enabled)
{
	t_shflag		*shflag;

	shflag = shflag_mgr_find_by_mono(this->shenv_shflags, mono);
	if (shflag)
		shflag->shf_enabled = enabled;
	else
		LOG_ERROR("shflag not found: %c", mono);
}
