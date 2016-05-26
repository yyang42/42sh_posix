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

bool			completion_utils_exec_absolute_path(t_completion *this)
{
	char		*path;

	path = this->current_word;
	if (path[0] == '/')
		return (true);
	if (path[0] == '.' && (!path[1] || path[1] == '/'))
		return (true);
	if ((path[0] == '.' && path[1] == '.') && (!path[2] || path[2] == '/'))
		return (true);
	while (*path)
	{
		if (*path == '/')
			return (true);
		path += 1;
	}
	return (false);
}

void			completion_exec_from_root(t_completion *this)
{
	LOG_DEBUG("From root");
	(void)this;
}

void			completion_exec_from_cwd(t_completion *this)
{
	LOG_DEBUG("From cwd");
	(void)this;
}

void			completion_exec_from_shenv(t_completion *this)
{
	LOG_DEBUG("From shenv");
	(void)this;
}

void			completion_exec(t_completion *this)
{
	if (completion_utils_exec_absolute_path(this))
	{
		if (this->current_word[0] == '/')
			completion_exec_from_root(this);
		else
			completion_exec_from_cwd(this);
	}
	else
	{
		completion_exec_from_shenv(this);
	}
}
