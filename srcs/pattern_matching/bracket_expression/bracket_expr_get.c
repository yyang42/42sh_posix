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

char			*bracket_expr_get(t_bracket_expr *this, char *key)
{
	char		*ret;

	ret = twl_dict_get(this->dict, key);
	if (ret == NULL)
	{
		bracket_expr_find_(this, key);
		ret = twl_dict_get(this->dict, key);
	}
	if (ret == (void *)-1)
		ret = NULL;
	return (ret);
}
