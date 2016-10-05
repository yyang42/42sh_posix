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

#include "twl_gnl.h"
#include "edit/edit.h"
#include "edit/research.h"
#include "edit/event.h"
#include "utils.h"

static char			*get_line(t_edit *this, char **remainders)
{
	char			*line;
	int				gnl_return;

	line = NULL;
	gnl_return = twl_gnl(0, &line, remainders);
	if ((!line && edit_is_eof_set(this)) || gnl_return < 0)
	{
		this->puts("\n\r");
		return (twl_strdup("exit"));
	}
	return (line);
}

char				*edit_get_line_without_termcap(t_edit *this,
		char **remainders, t_edit_type type)
{
	char			*line;
	char			*ret;

	this->type = type;
	if (this->type == edit_type_ps1 && this->last_ps1)
		twl_strdel(&this->last_ps1);
	edit_prompt_print(this);
	line = NULL;
	while (!(line = get_line(this, remainders)))
		;
	if (this->last_ps1)
	{
		ret = twl_strjoin(this->last_ps1, line);
		free(this->last_ps1);
	}
	else
	{
		ret = twl_strdup(line);
	}
	this->last_ps1 = twl_strjoin(ret, "\n");
	free(line);
	return (ret);
}
