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

#include <stdlib.h>

#include "ast.h"

#include "anode.h"

#define TAB_WIDTH 2

void				print_node(void *node, void *lvl_ptr)
{
	int						lvl;

	lvl = *(int *)lvl_ptr;
	twl_printf("%*s<%s>\n", lvl * TAB_WIDTH, "", anode_to_string(node));
	lvl++;
	if (anode_get_type(node) == ANODE_COMPOUND_STMT)
		twl_lst_iter(((t_anode_compound_stmt *)node)->items, print_node, &lvl);
}

void				ast_print(t_ast *this)
{
	int						lvl;
	twl_printf("cmd: %s\n", this->raw);
	lvl = 0;
	print_node(this->root, &lvl);
}
