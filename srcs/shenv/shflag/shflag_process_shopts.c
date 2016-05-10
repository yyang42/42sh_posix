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
#include "shenv/shflag.h"
#include "shenv/shenv.h"

void				shflag_utils_process_shopts(char sign, char c, char *optarg)
{
	if (c == 'o')
		shflag_mgr_set_state_by_long_sign(shenv_singleton()->shenv_shflags, optarg, sign);
	else if (twl_strchr(FTSH_VALID_SET_OPTS, c))
	{
		shflag_mgr_set_state_by_mono_sign(shenv_singleton()->shenv_shflags, c, sign);
	}
	else
	{
		LOG_ERROR("opt not found: %c", c);
	}
}
