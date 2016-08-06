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

#include "edit/line.h"

typedef struct			s_history
{
	t_line				**histlist;
	size_t				start;
	size_t				end;
	size_t				length;
	size_t				total;
}						t_history;

t_history				*history_new(void);
void					history_del(t_history *this);

void					history_read_file(t_history *this);

void					history_realloc(t_history *this);
void					history_realloc_size(t_history *this, size_t size);
void					history_push(t_history *this, t_line *line);

t_line					*history_get(t_history *this, size_t index);

#endif
