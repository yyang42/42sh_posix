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

static void			print_directory_content(char *directory)
{
	t_lst			*files;

	files = read_directory(directory);
	twl_printf("\n");
	twl_lst_iter0(files, printfn);
	twl_lst_del(files, free);
}

static void			complete_path(t_edit *edit, t_lst *words)
{
	(void)edit;
	if (twl_lst_len(words) == 1)
	{
		print_directory_content(".");
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
