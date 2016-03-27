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

char	 			*shsignal_mgr_get_signame(t_lst *shsignals, int signum)
{
	t_shsignal		*sig;

	sig = shsignal_mgr_find_by_signum(shsignals, signum);
	if (sig)
		return (sig->signame);
	return ("UNKNOWN");
}
