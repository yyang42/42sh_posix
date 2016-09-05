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

int					shenv_print_error_printf(t_shenv *this, int line,
	char *fmt, ...)
{
	t_pf	*pf;
	size_t	len;

	pf = pf_create((char *)fmt);
	va_start(pf->arglist, (char *)fmt);
	pf_prepare_xprintf__(pf);
	twl_dprintf(STDERR_FILENO, "%s: line %d: ",
		this->shenv_name, line);
	pf_print_fd(pf, STDERR_FILENO);
	twl_dprintf(STDERR_FILENO, "\n");
	va_end(pf->arglist);
	len = pf->output_len;
	pf_free(pf);
	return (len);
}
