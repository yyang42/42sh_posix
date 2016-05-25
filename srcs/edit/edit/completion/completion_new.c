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

#include "edit/completion.h"

static bool		completion_is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '|' || c == '&' || c == ';' ||
			c == '`' || c == '(' || c == '{' ||
			c == '<' || c == '>' || c == '$');
}

static t_completion_type	completion_get_type(char *current, size_t index)
{
	char					c;

	c = current[index];
	if (c == '|' || c == '&' || c == ';' || c == '`' || c == '(')
		return (COMPLETION_EXEC);
	if (c == '>' || c == '<')
		return (COMPLETION_DIRS);
	if (c == '$')
		return (COMPLETION_VARIABLE);
	if (c == '{' && current[index - 1] == '$')
		return (COMPLETION_BRACE_VARIABLE);
	while (true)
	{
		c = current[index];
		if (index == 0 || (c != ' ' && c != '\t' && c != '\n'))
			break ;
		index -= 1;
	}
	if (index == 0 || c == '|' || c == '&' || c == ';' || c == '`' || c == '(')
		return (COMPLETION_EXEC);
	return (COMPLETION_DIRS);
}

static void		completion_init(t_completion *this, t_edit *edit)
{
	char		*current;
	size_t		index;

	this->current_word = twl_strnew(edit->pos_cursor + 1);
	current = edit->current->line;
	index = edit->pos_cursor ? edit->pos_cursor - 1 : edit->pos_cursor;
	while (index && !completion_is_separator(current[index]))
	{
		index -= 1;
	}
	if (completion_is_separator(current[index]))
		twl_strncpy(this->current_word, current + index + 1,
				edit->pos_cursor - index - 1);
	else
		twl_strncpy(this->current_word, current + index,
				edit->pos_cursor - index);
	this->type = completion_get_type(current, index);
}

t_completion		*completion_new(t_edit *edit)
{
	t_completion	*this;

	this = twl_malloc_x0(sizeof(t_completion));
	completion_init(this, edit);
	this->edit = edit;
	return (this);
}
