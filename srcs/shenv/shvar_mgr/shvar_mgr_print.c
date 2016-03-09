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

#include "shenv/shvar_mgr.h"

static void			print_shvar_fn(void *shvar_)
{
	t_shvar	*shvar;

	shvar = shvar_;
	twl_printf("<%s=%s>\n", shvar->shvar_key, shvar->shvar_value);
}

void				shvar_mgr_print(t_lst *shvars)
{
	twl_printf("%s>>>>>>>>>> shvar list%s\n", C_CYAN, C_CLEAR);
	twl_lst_iter0(shvars, print_shvar_fn);
	twl_printf("%s-------------------------------------%s\n", C_CYAN, C_CLEAR);
}
