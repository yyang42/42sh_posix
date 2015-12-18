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

# include "twl_lst.h"

# include "edit/letter_mgr.h"
# include "edit/edit_move_mgr.h"
# include "basics.h"

typedef struct		s_edit
{
	t_lst			*letters;
	t_lst			*edit_move;
	int				index;
	bool			return_cmd;
}					t_edit;

t_edit				*edit_new(void);
void				edit_del(t_edit *this);
char				*edit_loop(t_edit *this);

char				*edit_handle_one_input(t_edit *this, int key);
char				*edit_handle_string(t_edit *this, char *str);

void				edit_handle_printable(t_edit *this, int key);
void				edit_handle_move(t_edit *this);
void				edit_print_letters(t_edit *this);
char				*edit_return_cmd(t_edit *this, int key);

void				edit_clear_line(t_edit *this);

void				edit_move_left(struct s_edit *this);


#endif
