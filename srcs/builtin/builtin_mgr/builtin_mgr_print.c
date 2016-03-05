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

#include "builtin/builtin_mgr.h"

static void			print_builtin_fn(void *builtin_)
{
	t_builtin	*builtin;

	builtin = builtin_;
	twl_printf("<Object #%p>\n", builtin);
}

void				builtin_mgr_print(t_lst *builtins)
{
	twl_printf("%s>>>>>>>>>> builtin list%s\n", C_CYAN, C_CLEAR);
	twl_lst_iter0(builtins, print_builtin_fn);
	twl_printf("%s-------------------------------------%s\n", C_CYAN, C_CLEAR);
}
