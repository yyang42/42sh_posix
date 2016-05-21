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

int					shenv_shflag_enabled(t_shenv *this, char *flag)
{
	t_shflag		*shflag;

	if (twl_strlen(flag) == 1)
		shflag = shflag_mgr_find_by_mono(this->shenv_shflags, *flag);
	else
		shflag = shflag_mgr_find_by_long(this->shenv_shflags, flag);
	if (shflag)
		return (shflag->shf_enabled);
	else
		LOG_ERROR("shflag not found: flag: %s", flag);
	return (false);
}
