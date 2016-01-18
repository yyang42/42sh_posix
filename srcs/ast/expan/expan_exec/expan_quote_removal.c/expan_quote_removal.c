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

#include "basics.h"
#include "ast/expan/ast_expan_quote_removal.h"
#include "environment.h"


static void		expan_quote_removal_init(t_expan_quote_removal *q)
{
	q->i = 0;
	q->is_single_quoted = false;
	q->is_double_quoted = false;
	q->is_backslashed = false;
}

static void		expan_quote_remove_char(char **str, int i, size_t *len)
{
	char	*tmp;
	char	*res;

	tmp = *str;
	*len = *len - 1;
	res = twl_strnew(*len - 1);
	twl_strncat(res, tmp, i);
	i++;
	twl_strncat(res, &tmp[i], *len - i);
	twl_strdel(&tmp);
	*str = res;
}

void			expan_quote_removal(char **res)
{
	t_expan_quote_removal	q;
	size_t					len;

	expan_quote_removal_init(&q);
	q.str = *res;
	len = twl_strlen(q.str);
	while (q.str[q.i] != 0)
	{
		if (q.str[q.i] == '\\')
		{
			if (q.is_single_quoted || q.is_double_quoted)
				expan_quote_remove_char(&q.str, q.i, &len);
			else
				q.is_backslashed = !q.is_backslashed;
		}
		else if (q.str[q.i] == '\'')
		{
			if (q.is_backslashed || q.is_double_quoted)
				expan_quote_remove_char(&q.str, q.i, &len);
			else
				q.is_single_quoted = !q.is_single_quoted;
		}
		else if (q.str[q.i] == '"')
		{
			if (q.is_backslashed || q.is_single_quoted)
				expan_quote_remove_char(&q.str, q.i, &len);
			else
				q.is_single_quoted = !q.is_single_quoted;
		}
		q.i++;
	}
}
