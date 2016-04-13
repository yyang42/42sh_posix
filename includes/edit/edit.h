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

# include "basics.h"
# include "edit/edit_key_mgr.h"
# include "edit/letter_mgr.h"
# include "edit/history_mgr.h"
# include "edit/copast.h"
# include "edit/history.h"
# include "utils.h"

typedef enum		e_state
{
	NORMAL,
	SEARCH,
}					t_state;

typedef struct		s_edit
{
	t_lst			*letters;
	t_lst			*edit_keys;
	int				index;
	bool			return_cmd;
	t_history		*history;
	t_copast		*copast;
	t_state			state;
}					t_edit;

t_edit				*edit_new(void);
t_edit				*edit_new_min(void);

void				edit_debug_print(t_edit *this);

void				edit_del(t_edit *this);
char				*edit_loop(t_edit *this);

char				*edit_handle_one_input(t_edit *this, int key);
char				*edit_handle_string(t_edit *this, char *str);

void				edit_handle_printable(t_edit *this, int key);
void				edit_handle_move(t_edit *this);
void				edit_print_letters(t_edit *this);
char				*edit_return_cmd(t_edit *this);

void				edit_clear_line(t_edit *this);

char				*edit_match_valide_cmd(char *cmd);

void				edit_out_of_search(t_edit *this);

#endif
