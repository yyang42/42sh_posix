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

#include "expan/expansion_parameter_brace.h"
#include "pattern_matching/substr.h"

/*
** TODO: remplacer le iter2 par un iter et juste faire un strcpy du to_push
** TODO: enlever le if (!lsast)...
*/

static void	iter_fn(void *data, void *word, void *new)
{
	t_substr	*substr;
	char		*to_push;

	substr = substr_new();
	to_push = substr_percent(substr, data, word);
	twl_lst_push_back(new, to_push);
	substr_del(substr);
}

static void	expan_param_asterisk(t_expansion *this, char *word)
{
	t_lst	*lsast;
	t_lst	*new;
	char	*join;
	char	*quoted;

	lsast = expan_get_param_spec('*');
	if (!lsast || twl_lst_len(lsast) == 0)
	{
		if (lsast)
			twl_lst_del(lsast, NULL);
		return ;
	}
	new = twl_lst_new();
	twl_lst_iter2(lsast, iter_fn, word, new);
	if (this->quoted)
	{
		join = expan_get_asterisk_quoted(new);
		quoted = expan_quote(join, this->quoted);
		expansion_push_before_split(this, quoted, false);
		free(quoted);
		free(join);
	}
	else
	{
		expansion_push_raw_lst(this, new);
	}
	twl_lst_del(lsast, NULL);
	twl_lst_del(new, free);
}

static void	expan_param_at(t_expansion *this, char *word)
{
	t_lst	*lsat;
	t_lst	*new;

	lsat = expan_get_param_spec('@');
	if (!lsat || twl_lst_len(lsat) == 0)
	{
		if (lsat)
			twl_lst_del(lsat, NULL);
		return ;
	}
	new = twl_lst_new();
	twl_lst_iter2(lsat, iter_fn, word, new);
	expansion_push_raw_lst(this, new);
	twl_lst_del(lsat, NULL);
	twl_lst_del(new, free);
}

static void	expan_param_spec(t_expansion *this, char special, char *word)
{
	t_lst		*ls;
	char		*to_quote;
	char		*quote;
	t_substr	*substr;

	ls = expan_get_param_spec(special);
	if (!ls || twl_lst_len(ls) != 1)
	{
		if (ls)
			twl_lst_del(ls, free);
		return ;
	}
	substr = substr_new();
	to_quote = substr_percent(substr, twl_lst_get(ls, 0), word);
	quote = expan_quote(to_quote, this->quoted);
	expansion_push_before_split(this, quote, !this->quoted);
	free(quote);
	free(to_quote);
	twl_lst_del(ls, free);
	substr_del(substr);
}

void		expbrace_percent_special(t_expansion *this,
										t_expansion_brace *eb)
{
	if (eb->param[0] == '*')
		expan_param_asterisk(this, eb->word);
	else if (eb->param[0]  == '@')
		expan_param_at(this, eb->word);
	else
		expan_param_spec(this, eb->param[0], eb->word);
}
