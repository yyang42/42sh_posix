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

#include "twl_xstdio.h"

#include "arexp/arexp.h"
#include "prog.h"
#include "shenv/shenv.h"

int					prog_print_arexp(t_prog *prog, char *input)
{
	t_arexp			*arexp;
	long long		lol;

	arexp = arexp_new(input);
	if (arexp->error_msg)
	{
		twl_dprintf(2, "%s\n", arexp->error_msg);
		return (1);
	}
	arexp_print_rec(arexp);
	lol = arexp_eval(arexp);
	if (arexp->error_msg)
	{
		twl_dprintf(2, "%s\n", arexp->error_msg);
		return (1);
	}
	twl_printf("Result = %lli\n", lol);
	arexp_del(arexp);
	return (0);
	(void)prog;
}
