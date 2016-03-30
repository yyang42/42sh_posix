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

#include "shsignal/shsignal_mgr.h"
#include "data.h"
#include "twl_stdlib.h"

t_shsignal			*shsignal_mgr_find_by_signame_or_signum(t_lst *shsignals, char *sigstr)
{
	t_shsignal		*shsignal;

	shsignal = shsignal_mgr_find_by_signame(shsignals, sigstr);
	if (!shsignal && twl_str_is_pos_num(sigstr))
	{
		shsignal = shsignal_mgr_find_by_signum(shsignals, twl_atoi(sigstr));
	}
	return (shsignal);
}
