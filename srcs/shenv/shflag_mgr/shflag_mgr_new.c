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

t_lst				*shflag_mgr_new(void)
{
	t_lst			*shflags;

	shflags = twl_lst_new();
	shflag_mgr_add(shflags, shflag_new('a', "allexport"));
	shflag_mgr_add(shflags, shflag_new('e', "errexit"));
	shflag_mgr_add(shflags, shflag_new('C', "noclobber"));
	shflag_mgr_add(shflags, shflag_new('f', "noglob"));
	shflag_mgr_add(shflags, shflag_new('b', "notify"));
	shflag_mgr_add(shflags, shflag_new(0, "ignoreeof"));
	shflag_mgr_add(shflags, shflag_new('m', "monitor"));
	shflag_mgr_add(shflags, shflag_new('n', "noexec"));
	shflag_mgr_add(shflags, shflag_new('u', "nounset"));
	shflag_mgr_add(shflags, shflag_new('v', "verbose"));
	shflag_mgr_add(shflags, shflag_new(0, "vi"));
	return (shflags);
}
