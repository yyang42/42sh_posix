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

static void			print_shsignal_fn(void *shsignal_)
{
	t_shsignal	*shsignal;

	shsignal = shsignal_;
	twl_printf("<Object #%p>\n", shsignal);
}

void				shsignal_mgr_print(t_lst *shsignals)
{
	twl_printf("%s>>>>>>>>>> shsignal list%s\n", C_CYAN, C_CLEAR);
	twl_lst_iter0(shsignals, print_shsignal_fn);
	twl_printf("%s-------------------------------------%s\n", C_CYAN, C_CLEAR);
}
