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

# define PS1 "$ "
# define PS2 "> "

typedef struct			s_edit
{
	t_lst				*history;
	t_line				*current;
	t_line				*last;
	unsigned char		buffer[8];
	size_t				pos_cursor;
	size_t				winsize_x;
	size_t				base_x;
	struct termios		term;
	struct termios		save;
	char				*copy_buffer;
	bool				echoing;
	bool				dumb;
	char				is_last_tab;
	int					(*putc)(int);
	int					(*puts)(char *);
}						t_edit;

typedef void			(*t_edit_fn)(t_edit *);

t_edit					*edit_new(void);
void					edit_del(t_edit *this);

t_edit					*edit_singleton(void);

void					edit_clear_line(t_edit *this);
void					edit_clear_screen(t_edit *this);

void					edit_get_winsize(t_edit *this);
void					edit_terminal_init(t_edit *this);
void					edit_terminal_enable(t_edit *this);
void					edit_terminal_disable(t_edit *this);

char					*edit_get_line(t_edit *this);
void					edit_new_last_line(t_edit *this);

void					edit_match_char(t_edit *this, unsigned char buf);
void					edit_place_letter(t_edit *this, unsigned char buf);
void					edit_place_string(t_edit *this, char *string);
void					edit_padding(t_edit *this);

void					edit_move_goto_pos_cursor(t_edit *this, size_t pos);

void					edit_move_right(t_edit *this);
void					edit_move_left(t_edit *this);

void					edit_move_home(t_edit *this);
void					edit_move_end(t_edit *this);

void					edit_del_left(t_edit *this);
void					edit_del_right(t_edit *this);

void					edit_del_all_left(t_edit *this);
void					edit_del_all_right(t_edit *this);
void					edit_paste(t_edit *this);

bool					edit_utils_can_buffer_form_sequence(t_edit *this);
t_edit_fn				edit_utils_buffer_match_sequence(t_edit *this);
t_edit_fn				edit_utils_buf_match_simple(t_edit *this,
							unsigned char buf);

void					edit_completion(t_edit *this);

#endif
