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

static char			*get_next_word_after_heredoc(char *str)
{
	char			buff[1000];
	int				i;

	i = 0;
	str += 2;
	twl_bzero(buff, 1000);
	while (twl_isspace(*str))
		str++;
	while (!twl_isblank(*str))
	{
		buff[i] = *str;
		i++;
		str++;
	}
	return twl_strdup(buff);
}

static char			*get_heredoc_sep(char* cmd)
{
	char			*heredoc_pos;
	char			*sep;

	heredoc_pos = twl_strstr(cmd, "<<");
	if (heredoc_pos == NULL)
		return NULL;
	sep = get_next_word_after_heredoc(heredoc_pos);
	return (twl_strdup(sep));

}

static void			match_heredoc(char *cmd, t_openclose_matcher *matcher)
{
	char 			*sep;

	while (true)
	{
		sep = get_heredoc_sep(cmd);
		if (sep == NULL)
			return ;
		openclose_matcher_add(matcher, sep, sep);
		free(sep);
		while (!twl_str_starts_with(cmd, sep))
		{
			cmd++;
			if (!*cmd)
				return ;
		}
	}
}

static bool			find_fn(void *_pairs, void *cmd)
{
	t_openclose 	*pairs;

	pairs = _pairs;
	(void)cmd;
	return (twl_str_starts_with(cmd, pairs->open));
}

static char			*get_part_before_heredoc(char *cmd)
{
	char			buff[1000];
	int				i;

	i = 0;
	twl_bzero(buff, 1000);
	while (!twl_str_starts_with(cmd, "<<"))
	{
		buff[i] = *cmd;
		cmd++;
		i++;
	}
	return twl_strdup(buff);
}

static char			*get_part_between_sep(char *cmd,char *sep)
{
	char			buff[1000];
	int				i;

	i = 0;
	twl_bzero(buff, 1000);
	while (!twl_str_starts_with(cmd, "<<"))
		cmd++;
	cmd += 2;
	while (twl_isspace(*cmd))
		cmd++;
	cmd += twl_strlen(sep);
	while (!twl_str_starts_with(cmd, sep))
	{
		buff[i] = *cmd;
		cmd++;
		i++;
	}
	return twl_strdup(twl_strtrim(buff));
}

static char			*clean_heredoc(char *cmd)
{
	char			*sep;
	char			*first_part;
	char			*middle_part;
	char			*new_cmd;

	sep = get_heredoc_sep(cmd);
	if (sep == NULL)
		return (cmd);
	first_part = get_part_before_heredoc(cmd);
	middle_part = get_part_between_sep(cmd, sep);
	new_cmd = twl_strjoinfree(first_part, " ", 'l');
	new_cmd = twl_strjoinfree(new_cmd, middle_part, 'b');
	return (new_cmd);
}

char				*edit_match_valide_cmd(char *cmd)
{
	t_openclose_matcher	*matcher;
	t_lst				*stack;
	char				*cpy;
	bool				res;
	char				*new_cmd;

	cpy = cmd;
	res = NULL;
	matcher = openclose_matcher_new(0);
	create_openclose_condition(matcher);
	match_heredoc(cmd, matcher);
	while (true)
	{
		cpy = cmd;
		res = false;
		while (*cpy)
		{
			res = twl_lst_find(matcher->oc_pairs, find_fn, cpy);
			if (res)
				break;
			cpy++;
		}
		stack = openclose_matcher_find_matching_stack(matcher, cpy);
		if (twl_lst_len(stack) > 0)
		{
			new_cmd = new_loop();
			cmd = twl_strjoinfree(cmd, new_cmd, 'b');
		}
		else
		{
			break;
		}
	}
	twl_lst_del(stack, NULL);
	cmd = clean_heredoc(cmd);
	openclose_matcher_del(matcher);
	return (cmd);
}
