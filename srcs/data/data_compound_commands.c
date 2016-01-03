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

#include "twl_lst.h"

#include "data.h"

t_lst				*data_compound_commands(void)
{
	static t_lst	*compounds = NULL;

	if (compounds == NULL)
	{
		compounds = twl_lst_new();
		twl_lst_push_back(compounds, twl_str_split_to_lst("(_)", "_"));
		twl_lst_push_back(compounds, twl_str_split_to_lst("{_}", "_"));
		twl_lst_push_back(compounds, twl_str_split_to_lst("if_fi", "_"));
	}
	return (compounds);
}
