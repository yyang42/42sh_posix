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

#include "twl_xsys/stat.h"

#include "edit/edit.h"
#include "edit/cursor.h"

static void			printfn(void *edit)
{
	twl_printf("%s\n", (char *)edit);
}

static bool			check_if_exec_complete(t_edit *edit, t_lst *words)
{
	if (twl_lst_len(words) == 1)
	{
		if ((int)twl_strlen(twl_lst_get(words, 0)) >= edit->index)
		{
			return (true);
		}
	}
	return (false);
}

static bool			find_fn(void *str, void *ctx)
{
	return (twl_str_starts_with(str, ctx));
}

static void			print_directory_content(char *directory)
{
	t_lst			*files;

	files = read_directory(directory);
	twl_printf("\n");
	twl_lst_iter0(files, printfn);
	twl_lst_del(files, free);
}
static void			filter_path_and_match(t_edit *edit, char *path)
{
	char			*cur_path;
	char			*match_str;
	t_lst			*dir_content;

	cur_path = get_path_of_file(path);
	match_str = get_last_part_of_path(path);
	if (cur_path && twl_strlen(cur_path))
	{
		dir_content = read_directory(cur_path);
		twl_lst_iter0(twl_lst_findall(dir_content, find_fn, match_str), printfn);
	}
	else
	{
		dir_content = read_directory(".");
		twl_lst_iter0(twl_lst_findall(dir_content, find_fn, match_str), printfn);
	}

	(void)edit;
}

static void			search_matching_path(t_edit *edit, t_lst *words)
{
	char			*search_path;

	search_path = twl_lst_last(words);
	if (twl_isdirl(search_path))
	{
		print_directory_content(search_path);
		if (!twl_str_ends_with(search_path, "/"))
		{
			edit_handle_one_input(edit, '/');
		}
	}
	else
	{
		filter_path_and_match(edit, search_path);
	}
}

static void			complete_path(t_edit *edit, t_lst *words)
{
	if (twl_lst_len(words) == 1)
	{
		print_directory_content(".");
	}
	else
	{
		search_matching_path(edit, words);
	}
}

void				edit_autocomplete(void *_edit)
{
	t_edit			*edit;
	char			*cur_cmd;
	t_lst			*words;

	edit = _edit;
	cur_cmd = letter_mgr_concat_string(edit->letters);
	words = twl_str_split_to_lst(cur_cmd, " ");
	if (check_if_exec_complete(edit, words))
	{
		twl_lprintf("Binary complete: not yet implemented\n");
	}
	else
	{
		complete_path(edit, words);
	}
	twl_lst_del(words, free);
	free(cur_cmd);
}


/*
** split cmd to lst
** check if build-in / bin(lst len == 1 && index == len 1 word)
** if built-in / bin, complete bin
** else complete path
**
** if lst len == 1
**	print all current dir content
** else
** 	get last word
**    if is dir
**      print dir content
**    else
**      split path (cur path + search word)
**      read cur path
**      filter by search
**      if filter lst == 1
**        complete
** 		else
**		  print filter list
*/
