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

int					terminal_enable(void)
{
	char			*name_term;
	t_termios		*term;

	term = terminal_singleton();
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, term) == -1)
		return (-1);
	DISABLE_FLAG(term->c_lflag, ICANON);
	DISABLE_FLAG(term->c_lflag, ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, term);
	tputs(cursor_invisible, 1, twl_putchar);
	return (0);
}
