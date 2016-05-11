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

static void		set_err_fn(char *text)
{
	if (shenv_shflag_exist(shenv_singleton(), "nounset"))
	{
		shenv_singl_error(EXIT_FAILURE, "%s: unbound variable", text);
		shenv_singleton()->shenv_shall_quit_curr_ast = true;
	}
}

static void		expan_param_pos(t_expansion *this, t_expansion_brace *eb)
{
	char		*param;
	t_substr	*substr;
	char		*match;
	char		*quote;

	param = expan_get_param_pos(eb->param);
	if (!param)
	{
		set_err_fn(eb->param);
		return ;
	}
	substr = substr_new();
	match = substr_sharp(substr, param, eb->word);
	if (!*match)
	{
		free(match);
		substr_del(substr);
		return ;
	}
	quote = expan_quote(match, this->quoted);
	expansion_push_before_split(this, quote, !this->quoted);
	free(quote);
	free(match);
	substr_del(substr);
}

static void		expan_param_normal(t_expansion *this, t_expansion_brace *eb)
{
	char		*param;
	t_substr	*substr;
	char		*match;
	char		*quote;

	param = expan_get_param_normal(eb->param);
	if (!param)
	{
		set_err_fn(eb->param);
		return ;
	}
	substr = substr_new();
	match = substr_sharp(substr, param, eb->word);
	if (!*match)
	{
		free(match);
		substr_del(substr);
		return ;
	}
	quote = expan_quote(match, this->quoted);
	expansion_push_before_split(this, quote, !this->quoted);
	free(quote);
	free(match);
	substr_del(substr);
}

void			expansion_brace_sharp(t_expansion *this, t_expansion_brace *eb)
{
	char		c;

	if (this->error)
		return ;
	c = eb->param[0];
	if (expan_is_special_parameter(c))
		expbrace_sharp_special(this, eb);
	else if (twl_isdigit(c))
		expan_param_pos(this, eb);
	else
		expan_param_normal(this, eb);
}
