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

static void		expan_param_spec(t_expansion *this, char spec)
{
	t_lst		*lspec;
	char		*to_push;
	void		(*del)(void *);

	lspec = expan_get_param_spec(spec);
	del = free;
	if (twl_lst_len(lspec) == 0)
		to_push = twl_strdup("0");
	else if (spec == '@' || spec == '*')
	{
		to_push = twl_itoa(twl_lst_len(lspec));
		del = NULL;
	}
	else
		to_push = twl_itoa(twl_strlen(twl_lst_get(lspec, 0)));
	expansion_push_before_split(this, to_push, !this->quoted);
	free(to_push);
	twl_lst_del(lspec, del);
}

static void		expan_param_pos(t_expansion *this, char *pos)
{
	char		*param;
	char		*to_push;

	param = expan_get_param_pos(pos);
	if (param)
	{
		to_push = twl_itoa(twl_strlen(param));
		expansion_push_before_split(this, to_push, !this->quoted);
		free(to_push);
	}
	else if (shenv_shflag_exist(shenv_singleton(), "nounset"))
	{
		shenv_singl_error(EXIT_FAILURE, "%s: unbound variable", pos);
		shenv_singleton()->shenv_shall_quit_curr_ast = true;
	}
	else
	{
		expansion_push_before_split(this, "0", !this->quoted);
	}
}

static void		expan_param_normal(t_expansion *this, char *normal)
{
	char		*param;
	char		*to_push;

	param = expan_get_param_normal(normal);
	if (param)
	{
		to_push = twl_itoa(twl_strlen(param));
		expansion_push_before_split(this, to_push, !this->quoted);
		free(to_push);
	}
	else if (shenv_shflag_exist(shenv_singleton(), "nounset"))
	{
		shenv_singl_error(EXIT_FAILURE, "%s: unbound variable", normal);
		shenv_singleton()->shenv_shall_quit_curr_ast = true;
	}
	else
	{
		expansion_push_before_split(this, "0", !this->quoted);
	}
}

void			expansion_brace_length(t_expansion *this, t_expansion_brace *eb)
{
	char		c;

	if (this->error)
		return ;
	c = eb->param[0];
	if (expan_is_special_parameter(c))
		expan_param_spec(this, eb->param[0]);
	else if (twl_isdigit(c))
		expan_param_pos(this, eb->param);
	else
		expan_param_normal(this, eb->param);
}
