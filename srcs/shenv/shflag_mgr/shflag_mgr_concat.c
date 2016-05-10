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
#include "shenv/shenv.h"

static void			print_shflag_fn(void *shflag_, void *concat_ptr_)
{
	t_shflag	*shflag;
	char		**concat_ptr;

	shflag = shflag_;
	concat_ptr = concat_ptr_;
	if (shflag->shf_mono && shflag->shf_enabled)
	{
		*concat_ptr = twl_strjoinfree(*concat_ptr, (char [2]){shflag->shf_mono, 0}, 'l');
	}
}

char				*shflag_mgr_concat(t_lst *shflags)
{
	char			*concat;

	concat = twl_strdup("");
	twl_lst_iter(shflags, print_shflag_fn, &concat);
	return (concat);
}
