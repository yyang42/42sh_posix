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

static void		expan_param_pos(t_expansion *this, char *pos)
{
	char		*param;
	char		*quote;

	param = expan_get_param_pos(pos + 1);
	if (!param)
	{
		if (shenv_shflag_exist(shenv_singleton(), "nounset"))
		{
			shenv_singl_error(EXIT_FAILURE, "%s: unbound variable", pos);
			shenv_singleton()->shenv_shall_quit_curr_ast = true;
		}
		return ;
	}
	quote = expan_quote(param, this->quoted);
	expansion_push_before_split(this, quote, !this->quoted);
	free(quote);
}

static void		expan_param_normal(t_expansion *this, char *normal)
{
	char		*param;
	char		*quote;

	param = expan_get_param_normal(normal + 1);
	if (!param)
	{
		if (shenv_shflag_exist(shenv_singleton(), "nounset"))
		{
			shenv_singl_error(EXIT_FAILURE, "%s: unbound variable", normal + 1);
			shenv_singleton()->shenv_shall_quit_curr_ast = true;
		}
		return ;
	}
	quote = expan_quote(param, this->quoted);
	expansion_push_before_split(this, quote, !this->quoted);
	free(quote);
}

void			expansion_parameter(t_expansion *this, t_expan_token *token)
{
	char		c;

	if (this->error)
		return ;
	c = token->text[1];
	if (c == '{')
		expansion_parameter_brace(this, token);
	else if (expan_is_special_parameter(c))
		expansion_parameter_special(this, token);
	else if (twl_isdigit(c))
		expan_param_pos(this, token->text);
	else if (twl_isalpha(c) || c == '_')
		expan_param_normal(this, token->text);
	else
		expansion_push_before_split(this, token->text, false);
}
