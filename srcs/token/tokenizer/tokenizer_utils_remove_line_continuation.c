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

#include "token/tokenizer.h"
#include "shenv/shenv.h"
#include "twl_xstring.h"
#include "openclose/openclose_matcher.h"


static void			copy_move_one(char **forward_ptr, char **final_str)
{
	**final_str = **forward_ptr;
	*forward_ptr += 1;
	*final_str += 1;
}

static bool			is_escaped_handle(char **forward_ptr, char **final_str)
{
	if (**forward_ptr == '\\')
	{
		*forward_ptr += 1;
		*final_str += 1;
		**final_str = **forward_ptr;
		if (**forward_ptr != '\0')
		{
			*forward_ptr += 1;
			*final_str += 1;
		}
		return (1);
	}
	return (0);
}

static bool			handle_single_quote(char **forward_ptr, char **final_str_ptr)
{
	if (**forward_ptr == '\'')
	{
		copy_move_one(forward_ptr, final_str_ptr);
		while (**forward_ptr)
		{
			copy_move_one(forward_ptr, final_str_ptr);
			if (**forward_ptr == '\'')
				break ;
		}
		return (1);
	}
	return (0);
}


void				tokenizer_utils_remove_line_continuation(char *str)
{
	char			*forward;
	char			*final_str;
	bool			is_double_quote_active;

	forward = str;
	final_str = str;
	is_double_quote_active = false;
	while (*forward)
	{
		if (*forward == '"')
			is_double_quote_active = !is_double_quote_active;
		if (*forward == '\\' && (*(forward + 1) == '\n'))
		{
			forward += 2;
			continue ;
		}
		if (is_escaped_handle(&forward, &final_str))
			continue;
		if (!is_double_quote_active)
		{
			if (handle_single_quote(&forward, &final_str))
				continue;
		}
		copy_move_one(&forward, &final_str);
	}
	*final_str = 0;
}
