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

#include "tokenizer.h"

static void			update_on_open(char **s, char *open, int *count_ptr)
{
	*count_ptr += 1;
	*s += twl_strlen(open);
}

static void			update_on_close(char **s, char *close, int *count_ptr)
{
	*count_ptr -= 1;
	*s += twl_strlen(close);
}

static void			update_on_quote(char **s_ptr)
{
	*s_ptr += 1;
	if (**s_ptr != '\0')
		*s_ptr += 1;
}

char				*tokenizer_utils_find_closing(char *s, char *open,
																char *close)
{
	int				count;

	if (!twl_str_starts_with(s, open))
		return (NULL);
	count = 0;
	update_on_open(&s, open, &count);
	while (*s)
	{
		if (*s == '\\')
		{
			update_on_quote(&s);
			if (*s == '\0')
				break ;
		}
		else if (twl_str_starts_with(s, close))
			update_on_close(&s, close, &count);
		else if (twl_str_starts_with(s, open))
			update_on_open(&s, open, &count);
		else
			s++;
		if (count == 0)
			return (s);
	}
	return (NULL);
}
