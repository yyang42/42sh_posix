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

static void		expan_param_asterisk(t_expansion *this, t_expansion_brace *eb)
{
	t_lst	*lsast;
	char	*join;
	char	*quote;

	lsast = expan_get_param_spec('*');
	if (twl_lst_len(lsast) == 0)
	{
		expansion_brace_hyphen_solve(this, eb->word);
		twl_lst_del(lsast, free);
		return ;
	}
	if (this->quoted)
	{
		join = expan_get_asterisk_quoted(lsast);
		quote = expan_quote(join, this->quoted);
		expansion_push_before_split(this, quote, false);
		free(quote);
		free(join);
	}
	else
	{
		expansion_push_raw_lst(this, lsast);
	}
	twl_lst_del(lsast, free);
}

static void		expan_param_at(t_expansion *this, t_expansion_brace *eb)
{
	t_lst	*lsat;

	lsat = expan_get_param_spec('@');
	if (twl_lst_len(lsat) == 0)
	{
		expansion_brace_hyphen_solve(this, eb->word);
		twl_lst_del(lsat, free);
		return ;
	}
	expansion_push_raw_lst(this, lsat);
	twl_lst_del(lsat, free);
}

static void	expan_param_spec(t_expansion *this, char special, char *word)
{
	t_lst		*ls;
	char		*quote;

	ls = expan_get_param_spec(special);
	if (twl_lst_len(ls) == 0)
	{
		expansion_brace_hyphen_solve(this, word);
		twl_lst_del(ls, free);
		return ;
	}
	quote = expan_quote(twl_lst_get(ls, 0), this->quoted);
	expansion_push_before_split(this, quote, !this->quoted);
	free(quote);
	twl_lst_del(ls, free);
}

void			expbrace_hyphen_special(t_expansion *this,
										t_expansion_brace *eb)
{
	if (eb->param[0] == '*')
		expan_param_asterisk(this, eb);
	else if (eb->param[0]  == '@')
		expan_param_at(this, eb);
	else
		expan_param_spec(this, eb->param[0], eb->word);
}
