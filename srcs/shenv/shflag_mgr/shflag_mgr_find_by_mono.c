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

static bool			find_by_mono(void *shflag_, void *mono_ptr)
{
	t_shflag		*shflag;

	shflag = shflag_;
	return (shflag->shf_mono == *(char *)mono_ptr);
}

t_shflag			*shflag_mgr_find_by_mono(t_lst *shflags, char mono)
{
	return (twl_lst_find(shflags, find_by_mono, &mono));
}
