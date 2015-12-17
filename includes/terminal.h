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

#ifndef TERMINAL_H
# define TERMINAL_H

# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/termios.h>
# include <term.h>
# include <termcap.h>
# include <termios.h>

# include "basics.h"

# define DISABLE_FLAG(flag_storage, flag) (flag_storage &= ~(flag))
# define ENABLE_FLAG(flag_storage, flag) (flag_storage |= flag)

# ifndef ERR
#  define ERR -1
# endif
typedef struct termios	t_termios;

typedef struct		s_terminal
{
	t_termios		*term;
}					t_terminal;




t_terminal			*terminal_new(t_termios *term);

t_termios			*terminal_singleton(t_termios *term);

int					terminal_enable(void);
void				terminal_disable(void);

#endif
