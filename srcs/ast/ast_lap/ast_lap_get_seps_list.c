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

#include "ast/ast_lap.h"

t_lst				**ast_lap_get_seps_list(void)
{
	static t_lst	*segs[AST_TYPE_NBR];
	static bool		is_loaded = false;

	if (is_loaded == false)
	{
		segs[AST_TYPE_LIST_ITEM] = data_list_separators();
		segs[AST_TYPE_ANDOR_ITEM] = data_andor_separators();
		segs[AST_TYPE_PIPE_ITEM] = data_pipe_separators();
		is_loaded = true;
	}
	return (segs);
}
