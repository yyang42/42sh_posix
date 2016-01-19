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
	twl_printf("COUCOUC\n");
	str = *res;
	while (str[i] != 0)
	{
		if (!twl_strchr(ifs, str[i]))
			str[i] = ' ';
		i++;
	}
	if (i > 0 && twl_strchr(ifs, str[i - 1]))
		str[i - 1] = 0;
}
