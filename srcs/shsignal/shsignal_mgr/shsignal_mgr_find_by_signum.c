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

static bool			find_by_signame_fn(void *shsignal_, void *signum_ptr)
{
	t_shsignal		*shsignal;

	shsignal = shsignal_;
	return (shsignal->signum == *(int *)signum_ptr);
}

t_shsignal 			*shsignal_mgr_find_by_signum(t_lst *shsignals, int signum)
{
	return (twl_lst_find(shsignals, find_by_signame_fn, &signum));
}
