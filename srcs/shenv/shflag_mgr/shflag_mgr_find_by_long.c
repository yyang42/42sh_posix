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

static bool			find_by_mono(void *shflag_, void *long_form)
{
	t_shflag		*shflag;

	shflag = shflag_;
	return (twl_strequ(shflag->shf_long, long_form));
}

t_shflag			*shflag_mgr_find_by_long(t_lst *shflags, char *long_form)
{
	return (twl_lst_find(shflags, find_by_mono, long_form));
}
