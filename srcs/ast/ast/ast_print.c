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

#include "ast/ast.h"

#include "ast/anode/anode.h"
#include "ast/anode/if_stmt.h"
#include "ast/anode/string_literal.h"

#define TAB_WIDTH 2

void				print_node(void *node, void *lvl_ptr)
{
	int						lvl;

	lvl = *(int *)lvl_ptr;

	lvl++;
	if (anode_get_type(node) == COMPOUND_STMT)
	{
		t_compound_stmt		*compound_stmt = node;
		twl_printf("%*s<%s>\n", lvl * TAB_WIDTH, "", anode_to_string(node));
		twl_lst_iter(compound_stmt->items, print_node, &lvl);
	}
	else if (anode_get_type(node) == IF_STMT)
	{
		twl_printf("%*s<%s>\n", lvl * TAB_WIDTH, "", anode_to_string(node));
		t_t_if_stmt			*if_stmt = node;
		print_node(if_stmt->cond, &lvl);
		twl_lst_iter(if_stmt->body->items, print_node, &lvl);

	}
	else if (anode_get_type(node) == STRING_LITERAL)
	{
		t_string_literal *string = node;
		twl_printf("%*s<%s> %s\n", lvl * TAB_WIDTH, "", anode_to_string(node),
																string->text);
	}
}

void				ast_print(t_ast *this)
{
	int						lvl;
	twl_printf("cmd: %s\n", this->raw);
	lvl = 0;
	print_node(this->root, &lvl);
}
