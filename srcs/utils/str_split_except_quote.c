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

t_lst				*str_split_except_quote(char *str, char *split_chars)
{
	t_lst			*segs;
	int				len;

	segs = twl_lst_new();
	len = 0;
	while (*str)
	{

		if (twl_strchr(split_chars, *str))
		{
			twl_lst_push(segs, twl_strndup(str - len + 1, len));
			len = 0;
		}
		len++;
		str++;
	}
	twl_lst_push(segs, twl_strndup(str - len, len));
	// twl_lst_push(segs, "aaa");
	// twl_lst_push(segs, "aaa");
	// twl_lst_push(segs, "aaa");
	return (segs);
	(void)split_chars;
	(void)str;
}
