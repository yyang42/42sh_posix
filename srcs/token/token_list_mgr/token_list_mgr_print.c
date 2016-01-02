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

#include "token/token_list_mgr.h"

static void			print_lst_fn(void *token_list_)
{
	t_lst	*token_list;

	token_list = token_list_;
	twl_printf("<Object #%p>\n", token_list);
}

void				token_list_mgr_print(t_lst *token_lists)
{
	twl_printf("%s>>>>>>>>>> token_list list%s\n", C_CYAN, C_CLEAR);
	twl_lst_iter0(token_lists, print_lst_fn);
	twl_printf("%s-------------------------------------%s\n", C_CYAN, C_CLEAR);
}
