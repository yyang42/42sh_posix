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
#include "expan/expan_quote_removal.h"
#include "environment.h"


static void		expan_quote_removal_init(t_expan_quote_removal *q)
{
	q->i = -1;
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
	res = twl_strnew(*len);
	twl_strncat(res, tmp, i);
	i++;
	twl_strncat(res, &tmp[i], *len - i + 1);
	twl_strdel(&tmp);
	*str = res;
}

static void		expan_quote_slash(t_expan_quote_removal *q, size_t *len)
{
	if (!q->is_backslashed && !q->is_single_quoted && !q->is_double_quoted)
	{
		expan_quote_remove_char(&q->str, q->i, len);
		q->is_backslashed = !q->is_backslashed;
		q->i--;
	}
	else if (!q->is_backslashed && q->is_double_quoted && q->str[q->i + 1] == '\\')
	{
		q->is_backslashed = !q->is_backslashed;
		expan_quote_remove_char(&q->str, q->i, len);
		q->i--;
	}
	else if (!q->is_backslashed && !q->is_single_quoted && q->str[q->i + 1] == '"')
	{
		q->is_backslashed = !q->is_backslashed;
		expan_quote_remove_char(&q->str, q->i, len);
		q->i--;
	}
	else if (q->is_backslashed)
	{
		q->is_backslashed = !q->is_backslashed;
	}
}

static void		expan_quote_double(t_expan_quote_removal *q, size_t *len)
{
	if (!q->is_backslashed && !q->is_single_quoted)
	{
		expan_quote_remove_char(&q->str, q->i, len);
		q->is_double_quoted = !q->is_double_quoted;
		q->i--;
	}
	else if (!q->is_single_quoted)
		q->is_backslashed = !q->is_backslashed;
}

void			expan_quote_removal(char **res)
{
	t_expan_quote_removal	q;
	size_t					len;

	expan_quote_removal_init(&q);
	q.str = *res;
	len = twl_strlen(q.str);
	while (q.str[++q.i] != 0)
	{
		if (q.str[q.i] == '\\')
			expan_quote_slash(&q, &len);
		else if (q.str[q.i] == '\'')
		{
			if (!q.is_backslashed && !q.is_double_quoted)
			{
				expan_quote_remove_char(&q.str, q.i, &len);
				q.is_single_quoted = !q.is_single_quoted;
				q.i--;
			}
		}
		else if (q.str[q.i] == '"')
			expan_quote_double(&q, &len);
		else if (q.is_backslashed)
			q.is_backslashed = !q.is_backslashed;
		*res = q.str;
	}
}
