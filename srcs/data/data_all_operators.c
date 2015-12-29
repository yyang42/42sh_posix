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

t_lst				*data_all_operators(void)
{
	static t_lst	*operators = NULL;

	if (operators == NULL)
	{
		operators = twl_lst_new();
		twl_lst_push_back(operators, "&&");
		twl_lst_push_back(operators, "||");
		twl_lst_push_back(operators, ";;");
		twl_lst_extend(operators, data_redir_operators());
	}
	return (operators);
}
