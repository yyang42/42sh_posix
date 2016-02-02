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

#include "pattern_matching/patmatch.h"

int					patmatch_bracket__(t_patmatch *this, t_match__ *m,
														t_pattern_data *data)
{
	char			*content;
	char			*possibilities;
	int				ret;

	content = twl_strndup(data->split + 1, twl_strlen(data->split) - 2);
	ret = 0;
	if (!(possibilities = bracket_expr_get(this->brack_expr, content)))
	{
		free(content);
		return (0);
	}
	free(content);
	if (twl_strchr(possibilities, m->name[m->ind_n]))
	{
		m->ind_n += 1;
		m->ind_p += 1;
		ret = patmatch_supervisor__(this, m);
		m->ind_n -= 1;
		m->ind_p -= 1;
	}
	return (ret);
}
