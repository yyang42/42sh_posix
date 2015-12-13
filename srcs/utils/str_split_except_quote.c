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

#include "utils.h"

#define STR_SPLIT_EXCEPT_QUOTE_SPLIT_CHARS " "

static int			count_prev_slash(char *str)
{
	int				len;

	len = 0;
	str--;
	while (*str == '\\')
	{
		len++;
		str--;
	}
	return (len);
}

static bool			is_quote(char *str, int is_first)
{
	if (*str == '"')
	{
		if (is_first)
			return (true);
		if (count_prev_slash(str) % 2 == 1)
			return (false);
		return (true);
	}
	return (false);
	(void)is_first;
}

static int			handle_quote_string(char **str_ptr, int len)
{
	*str_ptr += 1;
	len++;
	while (!is_quote(*str_ptr, false))
	{
		*str_ptr += 1;
		len++;
	}
	*str_ptr += 1;
	len++;
	return (len);
}

static char			*handle_new_seg(t_lst *segs, char *str, int len)
{
	if (len)
		twl_lst_push(segs, twl_strndup(str - len, len));
	while (*str && twl_strchr(STR_SPLIT_EXCEPT_QUOTE_SPLIT_CHARS, *str))
	{
		str++;
	}
	return (str);
}

t_lst				*str_split_except_quote(char *str)
{
	t_lst			*segs;
	int				len;
	char			*sav;

	sav = str;
	segs = twl_lst_new();
	len = 0;
	while (*str)
	{
		if (twl_strchr(STR_SPLIT_EXCEPT_QUOTE_SPLIT_CHARS, *str))
		{
			str = handle_new_seg(segs, str, len);
			len = 0;
		}
		else if (is_quote(str, (str == sav)))
		{
			len = handle_quote_string(&str, len);
		}
		else
		{
			len++;
			str++;
		}
	}
	if (len)
		twl_lst_push(segs, twl_strndup(str - len, len));
	return (segs);
}
