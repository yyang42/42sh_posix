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
#include "ast/expan/ast_expan_field_splitting.h"
#include "environment.h"
#include "patmatch.h"
#include "twl_xstring.h"

void		expan_field_splitting_ifs(char **res, char *ifs)
{
	int		i;
	char	*str;

	i = 0;
	str = *res;
	while (str[i] != 0)
	{
		if (twl_strchr(ifs, str[i]))
		{
			if (str[i + 1] == 0)
				str[i] = 0;
			else
				str[i] = ' ';
		}
		i++;
	}
}
