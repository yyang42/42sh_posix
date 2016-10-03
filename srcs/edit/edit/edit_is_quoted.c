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

static void		edit_is_quoted_init(t_edit *this,
		char **command, size_t *cursor)
{
	if (this->last_ps1)
	{
		*command = twl_strjoin(this->last_ps1, this->current->line);
		*cursor = twl_strlen(this->last_ps1) + this->pos_cursor;
	}
	else
	{
		*command = twl_strdup(this->current->line);
		*cursor = this->pos_cursor;
	}
}

bool			edit_is_quoted(t_edit *this)
{
	char		*command;
	size_t		cursor;
	size_t		index;
	bool		quoted;

	edit_is_quoted_init(this, &command, &cursor);
	index = 0;
	quoted = false;
	while (command[index] && index < cursor)
	{
		if (command[index] == '\\' && command[index + 1] && !quoted)
			index += 1;
		else if (command[index] == '\'')
			quoted = !quoted;
		index += 1;
	}
	free(command);
	return (quoted);
}
