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

t_lst				*data_all_separators(void)
{
	static t_lst	*separators = NULL;

	if (separators == NULL)
	{
		separators = twl_lst_new();
		twl_lst_extend(separators, data_list_separators());
		twl_lst_extend(separators, data_andor_separators());
		twl_lst_extend(separators, data_pipe_separators());
	}
	return (separators);
}
