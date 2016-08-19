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

void			completion_path_init(t_completion_path *this,
					t_completion *completion)
{
	char		*path;

	path = twl_strrchr(completion->current_word, '/');
	if (!path)
	{
		this->begin = twl_strdup(completion->current_word);
		this->end = twl_strdup("");
	}
	else
	{
		this->begin = twl_strndup(completion->current_word,
				path - completion->current_word + 1);
		this->end = twl_strdup(path + 1);
	}
}
