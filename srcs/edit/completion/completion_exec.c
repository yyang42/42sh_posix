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
