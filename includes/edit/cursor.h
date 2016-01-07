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

#ifndef CURSOR_H
# define CURSOR_H

# include "basics.h"
# include "edit/terminal.h"


typedef struct		s_cursor
{
	int				prompt_size;
	int				screen_width;
	int				current_cursor_pos;
}					t_cursor;

t_cursor			*cursor_new(void);
void				cursor_del(t_cursor *cursor);
void				cursor_reset_pos(void);


void				cursor_print(void);

t_cursor			*cursor_singleton();

void				cursor_check_pos(int index);

#endif
