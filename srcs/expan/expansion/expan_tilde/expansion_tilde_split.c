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

#include "expan/expansion.h"
#include "twl_ctype.h"
#include "builtin/cmds/builtin_dirs.h"

static void			get_home(t_expansion *this)
{
	char			*home;
	struct passwd	*pw;

	home = shenv_shvars_get_value(shenv_singleton(), "HOME");
	if (!home)
	{
		if ((pw = getpwuid(geteuid())))
			expansion_push_before_split(this, pw->pw_dir, false);
		else
			expansion_push_before_split(this, "~", false);
	}
	else
	{
		expansion_push_before_split(this, home, false);
	}
}

static bool			check_dirs(t_expansion *this, size_t index, bool is_neg)
{
	t_lst			*dirs;
	size_t			len;
	char			*cwd;

	dirs = builtin_dirs_singleton();
	len = twl_lst_len(dirs);
	if (index > len)
		return (false);
	index = (is_neg) ? len - index : index;
	if (index == 0)
	{
		if (!(cwd = getcwd(NULL, 4096)))
			return (false);
		expansion_push_before_split(this, cwd, false);
		free(cwd);
	}
	else
	{
		expansion_push_before_split(this, twl_lst_get(dirs, index - 1), false);
	}
	return (true);
}

static bool			is_number(t_expansion *this, char *text)
{
	size_t			index;
	bool			is_neg;

	index = 1;
	is_neg = false;
	if (text[index] == '+')
		index += 1;
	else if (text[index] == '-')
	{
		index += 1;
		is_neg = true;
	}
	if (!text[index])
		return (false);
	while (text[index])
	{
		if (!twl_isdigit(text[index]))
			return (false);
		index += 1;
	}
	index = twl_atoi(twl_isdigit(text[1]) ? text + 1 : text + 2);
	return (check_dirs(this, index, is_neg));
}

void				expansion_tilde_split(t_expansion *this,
											t_expan_token *token)
{
	struct passwd	*pw;

	if (this->error)
		return ;
	if (!token->text[1])
		get_home(this);
	else if (is_number(this, token->text))
		;
	else if ((pw = getpwnam(token->text + 1)))
		expansion_push_before_split(this, pw->pw_dir, false);
	else
		expansion_no_tilde_split(this, token);
}
