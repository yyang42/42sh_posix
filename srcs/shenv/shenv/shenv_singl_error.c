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

#include "shenv/shenv.h"
#include "twl_printf.h"

void				shenv_singl_error(int exit_code, char *fmt, ...)
{
	t_pf	*pf;

	if (shenv_is_dryrun(shenv_singleton()))
		return ;
	pf = pf_create((char *)fmt);
	va_start(pf->arglist, (char *)fmt);
	pf_prepare_xprintf__(pf);
	twl_dprintf(STDERR_FILENO, "%s: line %d: ",
		shenv_singleton()->shenv_name, shenv_get_cur_line());
	pf_print_fd(pf, STDERR_FILENO);
	twl_dprintf(STDERR_FILENO, "\n");
	va_end(pf->arglist);
	pf_free(pf);
	shenv_singleton()->last_exit_code = exit_code;
}
