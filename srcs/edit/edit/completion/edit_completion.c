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

static bool		completion_is_separator(char c)
{
	return (c == ' ' || c == '"' || c == '\t' || c == '\n' || c == '|' ||
			c == '&' || c == '`' || c == '(' || c == ';' ||
			c == '<' || c == '>');
}

static char		*get_current_word(t_edit *this)
{
	char		*ret;
	char		*current;
	size_t		index;

	ret = twl_strnew(this->pos_cursor);
	current = this->current->line;
	index = this->pos_cursor ? this->pos_cursor - 1 : this->pos_cursor;
	while (index && !completion_is_separator(current[index]))
	{
		index -= 1;
	}
	twl_strncpy(ret, current + index, this->pos_cursor - index);
	return (ret);
}

void			edit_completion(t_edit *this)
{
	char		*current_word;

	if (this->current->size == 0)
		return ;
	current_word = get_current_word(this);
	LOG_DEBUG("%s", current_word);
	free(current_word);
	(void)this;
}
