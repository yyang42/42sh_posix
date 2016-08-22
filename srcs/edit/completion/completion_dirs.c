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

static void		completion_dirs_from_home(t_completion *this)
{
	char		*tmp;

	if (this->current_word[1] == 0)
		edit_place_letter(this->edit, '/');
	else if (this->current_word[1] == '/')
	{
		tmp = this->current_word;
		this->current_word = twl_strjoin(shenv_get_home(shenv_singleton()),
				this->current_word + 1);
		if (this->current_word[0] != '~')
			completion_dirs(this);
		free(this->current_word);
		this->current_word = tmp;
	}
	twl_lst_clear(this->all, free);
}

void			completion_dirs(t_completion *this)
{
	if (this->current_word[0] == '/')
		completion_dirs_from_root(this);
	else if (this->current_word[0] == '~')
		completion_dirs_from_home(this);
	else
		completion_dirs_from_cwd(this);
}
