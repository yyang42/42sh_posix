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
#include "shenv/shenv.h"

static void		iter_fn(void *data, void *next, void *context)
{
	char		ifs[2];
	char		*full_ifs;

	*((char **)context) = twl_strjoinfree(*((char **)context), data, 'l');
	if (next)
	{
		full_ifs = shenv_shvars_get_value(shenv_singleton(), "IFS");
		ifs[0] = (!full_ifs) ? ' ' : full_ifs[0];
		ifs[1] = 0;
		*((char **)context) = twl_strjoinfree(*((char **)context), ifs, 'l');
	}
}

char			*expan_get_asterisk_quoted(t_lst *lsast)
{
	char		*ret;

	ret = twl_strnew(0);
	twl_lst_itern(lsast, iter_fn, &ret);
	return (ret);
}
