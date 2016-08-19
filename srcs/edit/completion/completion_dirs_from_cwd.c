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

static void		completion_path_init_fn(t_completion_path *this,
					t_completion *completion)
{
	char		*path;

	path = twl_strrchr(completion->current_word, '/');
	if (!path)
	{
		this->begin = twl_strdup("./");
		this->end = twl_strdup(completion->current_word);
	}
	else
	{
		this->begin = twl_strndup(completion->current_word,
				path - completion->current_word + 1);
		this->end = twl_strdup(path + 1);
	}
}

void			completion_dirs_from_cwd(t_completion *this)
{
	t_completion_path	path;
	char				*tmp;

	completion_path_init_fn(&path, this);
	if (!*path.end && completion_path_utils_is_begin_dot(path.begin))
	{
		edit_place_letter(this->edit, '/');
	}
	else
	{
		path.begin = twl_strjoinfree("./", path.begin, 'r');
		completion_path_dirs_readfile(this, &path);
		if (!twl_lst_first(this->all))
			;
		else if (this->all_len == 1)
		{
			edit_place_string(this->edit, twl_lst_first(this->all) + twl_strlen(path.end));
		}
		else if ((tmp = completion_path_utils_get_begin_list(this, &path)))
		{
			edit_place_string(this->edit, tmp);
			free(tmp);
		}
		else
		{
			if (this->edit->is_last_tab)
				completion_utils_print_lst(this);
			this->edit->is_last_tab = 2;
		}
	}
	twl_lst_clear(this->all, free);
	completion_path_clear(&path);
}
