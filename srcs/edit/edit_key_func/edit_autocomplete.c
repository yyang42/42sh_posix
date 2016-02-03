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
#include "edit/cursor.h"

static bool			find_fn(void *str, void *cmp_str)
{
	return (twl_str_starts_with(str, cmp_str));
}

static char			*complete_path(char *cur)
{
	char			*cur_path;
	char			*complete_word;
	t_lst			*dir_content;
	t_lst			*match_path;
	char			*return_path = NULL;

	cur_path = get_path_of_file(cur);
	if (cur_path == NULL || twl_strlen(cur_path) == 0)
	{
		dir_content = read_directory(".");
		complete_word = get_last_part_of_path(cur);
		match_path = twl_lst_findall(dir_content, find_fn, complete_word);
		free(complete_word);
		if (twl_lst_len(match_path) == 1)
		{
			return_path = twl_strdup(twl_lst_get(match_path, 0));
			// twl_lprintf("comp: %s\n", return_path);
		}
		twl_lst_del(dir_content, free);
		twl_lst_del(match_path, NULL);
	}
	free(cur_path);
	return return_path;
}

void				edit_autocomplete(void *_edit)
{
	t_edit			*edit;
	char			*cur_cmd;
	t_lst			*words;
	char			*new_path;

	edit = _edit;
	cur_cmd = letter_mgr_concat_string(edit->letters);
	words = twl_str_split_to_lst(cur_cmd, " \t");
	free(cur_cmd);
	if (twl_lst_len(words) == 1)
	{
		twl_lprintf("binary + builtin complete: Not yet implemented\n");
	}
	else if (twl_lst_len(words) > 1)
	{
		new_path = complete_path(twl_lst_get(words, -1));
		if (new_path)
		{
			free(twl_lst_pop(words));
			cur_cmd = twl_lst_strjoin(words, "/");
			twl_lst_del(words, free);
			edit->return_cmd = true;
			edit_clear_line(edit);
			edit->return_cmd = false;
			cur_cmd = twl_strjoinfree(cur_cmd, " ", 'l');
			cur_cmd = twl_strjoinfree(cur_cmd, new_path, 'b');
			edit_handle_string(edit, cur_cmd);
			free(cur_cmd);
		}
	}
}
