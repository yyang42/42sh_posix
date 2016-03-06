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

#include "pattern_matching/bracket_expr.h"

static char		*bce_fn(int (*func)(int))
{
	char	expr[128];
	char	*ret;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < 128)
	{
		if (func(i))
		{
			expr[j] = i;
			j += 1;
		}
		i += 1;
	}
	expr[j] = 0;
	ret = twl_strdup(expr);
	return (ret);
}

static void		build_bracket_expr(t_bracket_expr *this)
{
	this->dict = twl_dict_new();
	twl_dict_add(this->dict, "[:alnum:]", bce_fn(twl_isalnum));
	twl_dict_add(this->dict, "[:alpha:]", bce_fn(twl_isalpha));
	twl_dict_add(this->dict, "[:blank:]", bce_fn(twl_isblank));
	twl_dict_add(this->dict, "[:cntrl:]", bce_fn(twl_iscntrl));
	twl_dict_add(this->dict, "[:digit:]", bce_fn(twl_isdigit));
	twl_dict_add(this->dict, "[:graph:]", bce_fn(twl_isgraph));
	twl_dict_add(this->dict, "[:lower:]", bce_fn(twl_islower));
	twl_dict_add(this->dict, "[:print:]", bce_fn(twl_isprint));
	twl_dict_add(this->dict, "[:punct:]", bce_fn(twl_ispunct));
	twl_dict_add(this->dict, "[:space:]", bce_fn(twl_isspace));
	twl_dict_add(this->dict, "[:upper:]", bce_fn(twl_isupper));
	twl_dict_add(this->dict, "[:xdigit:]", bce_fn(twl_isxdigit));
}

t_bracket_expr	*bracket_expr_new(void)
{
	t_bracket_expr	*this;

	this = twl_malloc_x0(sizeof(t_bracket_expr));
	build_bracket_expr(this);
	return (this);
}
