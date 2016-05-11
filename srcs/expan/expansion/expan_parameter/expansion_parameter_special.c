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

static void	expan_param_asterisk(t_expansion *this)
{
	t_lst	*lsast;
	char	*join;
	char	*quoted;

	lsast = expan_get_param_spec('*');
	if (!lsast || twl_lst_len(lsast) == 0)
		return ;
	if (this->quoted)
	{
		join = expan_get_asterisk_quoted(lsast);
		quoted = expan_quote(join, this->quoted);
		expansion_push_before_split(this, quoted, false);
		free(quoted);
		free(join);
	}
	else
	{
		expansion_push_raw_lst(this, lsast);
	}
	twl_lst_del(lsast, NULL);
}

static void	expan_param_at(t_expansion *this)
{
	t_lst	*lsat;

	this->is_at_present = true;
	lsat = expan_get_param_spec('@');
	if (!lsat || twl_lst_len(lsat) == 0)
		return ;
	expansion_push_raw_lst(this, lsat);
	twl_lst_del(lsat, NULL);
}

static void	expan_param_spec(t_expansion *this, char special)
{
	t_lst	*ls;
	char	*quote;

	ls = expan_get_param_spec(special);
	if (!ls || twl_lst_len(ls) != 1)
	{
		if (ls)
			twl_lst_del(ls, free);
		if (shenv_shflag_exist(shenv_singleton(), "nounset"))
		{
			shenv_singl_error(EXIT_FAILURE, "$%c: unbound variable", normal);
			shenv_singleton()->shenv_shall_quit_curr_ast = true;
		}
		return ;
	}
	quote = expan_quote(twl_lst_get(ls, 0), this->quoted);
	expansion_push_before_split(this, quote, !this->quoted);
	free(quote);
	twl_lst_del(ls, free);
}

void		expansion_parameter_special(t_expansion *this, t_expan_token *token)
{
	if (token->text[1] == '*')
		expan_param_asterisk(this);
	else if (token->text[1] == '@')
		expan_param_at(this);
	else
		expan_param_spec(this, token->text[1]);
}
