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

void				print_node(void *anode, void *lvl_ptr, void *out_list)
{
	int				lvl;
	char			*tmp;

	lvl = *(int *)lvl_ptr;
	twl_asprintf(&tmp, "%*s<%s>", lvl * TAB_WIDTH, "", anode_to_string(anode));
	twl_lst_push(out_list, tmp);
	if (anode_get_type(anode) == STRING_LITERAL)
	{
		t_string_literal *string = anode;
		twl_asprintf(&tmp, " %s", string->text);
		twl_lst_push(out_list, tmp);
	}
	twl_lst_push(out_list, twl_strdup("\n"));
	lvl++;
	if (anode_get_type(anode) == COMPOUND_STMT)
	{
		t_compound_stmt		*compound_stmt = anode;
		twl_lst_iter2(compound_stmt->items, print_node, &lvl, out_list);
	}
	else if (anode_get_type(anode) == IF_STMT)
	{
		t_t_if_stmt			*if_stmt = anode;
		print_node(if_stmt->cond, &lvl, out_list);
		twl_lst_iter2(if_stmt->body->items, print_node, &lvl, out_list);

	}
}

char				*ast_to_str(t_ast *this)
{
	int				lvl;
	t_lst			*out_list;
	char			*out;

	out_list = twl_lst_new();
	lvl = 0;
	print_node(this->root, &lvl, out_list);
	out = twl_lst_strjoin(out_list, "");
	twl_lst_del(out_list, free);
	return (out);
}
