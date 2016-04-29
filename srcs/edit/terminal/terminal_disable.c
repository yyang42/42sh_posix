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

#include "edit/terminal.h"

void				terminal_disable(void)
{
	t_termios		*term;

	term = terminal_singleton();
	twl_printf("========3\n");
	ENABLE_FLAG(term->c_lflag, ICANON);
	ENABLE_FLAG(term->c_lflag, ECHO);
	tcsetattr(0, TCSADRAIN, term);
	tputs(cursor_normal, 1, twl_putchar);
}
