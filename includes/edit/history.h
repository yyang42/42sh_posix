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

#ifndef HISTORY_H
# define HISTORY_H

# include "utils.h"
# include "edit/line.h"
# include "shenv/shenv.h"

# define DFL_HISTSIZE 128
# define DFL_HISTFILE ".sh_history"

typedef struct			s_histlist
{
	t_line				*line;
	size_t				number;
	struct s_histlist	*next;
	struct s_histlist	*prev;
}						t_histlist;

typedef struct			s_history
{
	t_histlist			*first;
	t_histlist			*current;
	t_histlist			*last;
	size_t				length;
	size_t				total;
}						t_history;

t_history				*history_new(void);
void					history_del(t_history *this);

void					history_get_histsize(t_history *this);

void					history_read_file(t_history *this);

void					history_push(t_history *this, t_line *line);
void					history_pop(t_history *this);

t_line					*history_get(t_history *this, size_t index);
t_line					*history_get_current(t_history *this);

void					history_up(t_history *this);
void					history_down(t_history *this);

bool					history_is_current_first(t_history *this);
bool					history_is_current_last(t_history *this);

void					history_reset_current(t_history *this);

#endif
