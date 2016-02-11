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
#include "expan/expan_exec.h"
#include "patmatch.h"
#include "twl_xstring.h"
#include "twl_arr.h"

static bool	expan_field_splitting_is_separator(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (true);
	else
		return (false);
}

static int	expan_field_splitting_count_words(char *str)
{
	bool	is_double_quoted;
	int		i;
	int		nb;

	i = 0;
	nb = str[i] == 0 ? 0 : 1;
	is_double_quoted = false;
	while (str[i] != 0)
	{
		if (str[i] == '"')
			is_double_quoted = !is_double_quoted;
		if (!is_double_quoted && expan_field_splitting_is_separator(str[i]))
		{
			nb++;
			while(expan_field_splitting_is_separator(str[i]) && str[i] != 0 && str[i] != '"')
				i++;
		}
		if (str[i] == 0)
			break;
		else if (str[i] == '"')
			is_double_quoted = !is_double_quoted;
		i++;
	}
	return (nb);
}

static int	expan_field_splitting_word_length(char *str, bool is_double_quoted)
{
	int i;

	i = 0;
	if (is_double_quoted)
	{
		while (str[i] != 0 && str[i] != '"')
			i++;
	}
	while (!expan_field_splitting_is_separator(str[i]) && str[i] != 0)
		i++;
	return (i);
}

static void	expan_field_splitting_fill_array(char **arr, char *str)
{
	bool		is_double_quoted;
	int			i;
	size_t		len;

	is_double_quoted = false;
	i = 0;
	while (str[i] != 0)
	{
		len = expan_field_splitting_word_length(&str[i], is_double_quoted);
		if (len > 0)
		{
			twl_arr_push(arr, twl_strndup(&str[i], len));
			i += len;
		}
		else
			i++;
	}
}

void		expan_field_splitting_white_spaces(char **res)
{

	char	*tmp;
	int		nb_words;
	char	**arr;

	tmp = *res;
	*res = twl_strtrim(*res);
	twl_strdel(&tmp);
	nb_words = expan_field_splitting_count_words(*res);
	arr = twl_arr_new(nb_words);
	expan_field_splitting_fill_array(arr, *res);
	twl_strdel(res);
	*res = twl_strjoinarr((const char **)arr, " ");
	twl_arr_del(arr, free);
}
