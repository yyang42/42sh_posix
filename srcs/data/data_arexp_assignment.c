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

#include "data.h"
#include "token/token.h"

t_lst				*data_arexp_assignment(void)
{
	static t_lst	*assignment = NULL;

	if (assignment == NULL)
	{
		assignment = twl_lst_new();
		twl_lst_push_back(assignment, "=");
		twl_lst_push_back(assignment, "|=");
		twl_lst_push_back(assignment, "^=");
		twl_lst_push_back(assignment, "&=");
		twl_lst_push_back(assignment, "+=");
		twl_lst_push_back(assignment, "-=");
		twl_lst_push_back(assignment, "*=");
		twl_lst_push_back(assignment, "/=");
		twl_lst_push_back(assignment, "%=");
		twl_lst_push_back(assignment, "<<=");
		twl_lst_push_back(assignment, ">>=");
	}
	return (assignment);
}
