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

void				terminal_send_veol(void)
{
	char			cp[2];
	t_termios		*term;

	term = terminal_singleton();
	cp[0] = term->c_cc[VEOL];
	cp[1] = 0;
	ioctl(0, TIOCSTI, cp);
}
