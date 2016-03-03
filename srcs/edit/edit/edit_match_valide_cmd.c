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

#include "twl_xunistd.h"
#include "twl_ctype.h"

#include "edit/terminal.h"
#include "edit/edit.h"
#include "openclose/openclose_matcher.h"
#include "token/token_mgr.h"


void				create_openclose_condition(t_openclose_matcher *matcher)
{
	openclose_matcher_add(matcher, "\"", "\"");
	openclose_matcher_add(matcher, "'", "'");
	openclose_matcher_add(matcher, "{", "}");
	openclose_matcher_add(matcher, "(", ")");
	openclose_matcher_add(matcher, "[", "]");
}

static void			print_fn(void *data, int i, void *_edit_min)
{
	t_letter		*letter;
	t_edit			*edit_min;

	letter = data;
	edit_min = _edit_min;
	if (i == edit_min->index && !edit_min->return_cmd)
		terminal_radio_letter();
	twl_putstr(letter->letter);
	terminal_clear_letter();
}

static void			print_line(t_edit *edit_min)
{
	terminal_carriage_return();
	terminal_delete_line();
	twl_putstr("Close > ");
	twl_lst_iteri(edit_min->letters, print_fn, edit_min);
	if (edit_min->return_cmd)
		twl_putstr("\n");
}

static char			*new_loop(void)
{
	t_edit			*edit_min;
	char			*cmd;
	int				key;

	edit_min = edit_new_min();
	cmd = NULL;
	print_line(edit_min);
	while (!cmd)
	{
		key = twl_getch();
		cmd = edit_handle_one_input(edit_min, key);
		print_line(edit_min);
	}
	edit_del(edit_min);
	return (cmd);
}

char				*edit_match_valide_cmd(char *cmd)
{
	t_openclose_matcher	*matcher;
	t_lst				*stack;
	char				*cpy;
	char				*res;
	char				*new_cmd;

	cpy = cmd;
	res = NULL;
	matcher = openclose_matcher_new();
	create_openclose_condition(matcher);
	while (cpy)
	{
		res = twl_strchr("\"'{([", *cpy);
		if (res)
			break;
		cpy++;
	}
	stack = openclose_matcher_find_matching_stack(matcher, cpy);
	if (twl_lst_len(stack) > 0)
	{
		new_cmd = new_loop();
		cmd = twl_strjoinfree(cmd, new_cmd, 'r');
		edit_match_valide_cmd(cmd);
	}
	twl_lst_del(stack, NULL);
	openclose_matcher_del(matcher);
	return (cmd);
}
