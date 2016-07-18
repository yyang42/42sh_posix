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

#include "edit/research.h"

void			research_clear_line(t_edit *this)
{
	size_t		tmp_pos_cursor;
	char		*tmp;

	tmp_pos_cursor = this->pos_cursor;
	edit_move_home(this);
	tmp = twl_strnewc(this->current->size, ' ');
	this->puts(tmp);
	free(tmp);
	this->pos_cursor = this->current->size;
	edit_move_home(this);
	this->pos_cursor = tmp_pos_cursor;
}
