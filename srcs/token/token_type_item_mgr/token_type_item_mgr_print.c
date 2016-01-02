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

#include "token/token_type_item_mgr.h"

static void			print_token_type_item_fn(void *token_type_item_)
{
	t_token_type_item	*token_type_item;

	token_type_item = token_type_item_;
	twl_printf("<Object #%p>\n", token_type_item);
}

void				token_type_item_mgr_print(t_lst *token_type_items)
{
	twl_printf("%s>>>>>>>>>> token_type_item list%s\n", C_CYAN, C_CLEAR);
	twl_lst_iter0(token_type_items, print_token_type_item_fn);
	twl_printf("%s-------------------------------------%s\n", C_CYAN, C_CLEAR);
}
