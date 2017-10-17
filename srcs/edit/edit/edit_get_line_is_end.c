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

#include "edit/edit.h"
#include "edit/research.h"
#include "edit/event.h"
#include "utils.h"

static bool		edit_get_line_not_end(t_edit *this)
{
	this->research_mode = false;
	research_del(this->research);
	this->research = NULL;
	line_del(this->last);
	this->last = line_new();
	this->current = this->last;
	history_reset_current(this->history);
	this->pos_cursor = 0;
	this->type = edit_type_ps1;
	return (false);
}

bool			edit_get_line_is_end(t_edit *this)
{
	char		*expand;
	char		*tmp;
	size_t		len;
	size_t		tot;

	expand = event_expand(this);
	if (!expand)
	{
		return (edit_get_line_not_end(this));
	}
	len = twl_strlen(expand);
	tot = len < this->current->total ?
		this->current->total : utils_upper_power_of_two(len);
	tmp = twl_strnew(tot);
	twl_strcpy(tmp, expand);
	free(expand);
	free(this->current->line);
	this->current->line = tmp;
	this->current->size = len;
	this->current->total = tot;
	return (true);
}
