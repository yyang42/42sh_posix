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

char				*tokenizer_utils_find_closing_plus(char *s)
{
	if (twl_str_starts_with(s, "$(("))
		return tokenizer_utils_find_closing(s, "$((", "))");
	else if (twl_str_starts_with(s, "$("))
		return tokenizer_utils_find_closing(s, "$(", ")");
	else if (twl_str_starts_with(s, "`"))
		return tokenizer_utils_find_closing(s, "`", "`");
	else if (twl_str_starts_with(s, "\""))
		return tokenizer_utils_find_closing(s, "\"", "\"");
	else if (twl_str_starts_with(s, "'"))
		return tokenizer_utils_find_closing(s, "'", "'");
	else if (twl_str_starts_with(s, "${"))
		return tokenizer_utils_find_closing(s, "${", "}");
	return (NULL);
}
