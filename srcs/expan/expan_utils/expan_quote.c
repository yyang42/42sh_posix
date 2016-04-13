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

#include "expan/expan_utils.h"

char			*expan_quote(char *param, bool quoted)
{
	char		*cpy;
	char		*ret;
	size_t		ind_par;
	size_t		ind_cpy;

	cpy = twl_strnew((twl_strlen(param) << 1) + 1);
	ind_par = 0;
	ind_cpy = 0;
	while (param[ind_par])
	{
		if ((quoted && (param[ind_par] == '\\' || param[ind_par] == '"')) ||
			(!quoted && (param[ind_par] == '\\' || param[ind_par] == '"' ||
						 param[ind_par] == '\'')))
		{
			cpy[ind_cpy] = '\\';
			ind_cpy += 1;
		}
		cpy[ind_cpy] = param[ind_par];
		ind_par += 1;
		ind_cpy += 1;
	}
	ret = twl_strdup(cpy);
	free(cpy);
	return (ret);
}
