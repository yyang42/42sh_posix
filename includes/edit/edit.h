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

#ifndef EDIT_H
# define EDIT_H

# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/termios.h>
# include <term.h>
# include <termcap.h>
# include <termios.h>

# include "basics.h"
# include "shenv/shenv.h"
# include "edit/line.h"

typedef struct			s_edit
{
	t_line				*current;
	struct termios		term;
	struct termios		save;
	bool				echoing;
}						t_edit;

t_edit					*edit_new(void);
void					edit_del(t_edit *this);

t_edit					*edit_singleton(void);

void					edit_terminal_init(t_edit *this);
void					edit_terminal_enable(t_edit *this);
void					edit_terminal_disable(t_edit *this);

char					*edit_get_line(t_edit *this);

#endif
