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
#include "ast/anode/pipeline.h"

#define TAB_WIDTH 2

void				travel_rec(void *anode, void *lvl_ptr, void *out_list)
{
	int				lvl;
	char			*tmp;

	lvl = *(int *)lvl_ptr;
	twl_asprintf(&tmp, "%*s%s", lvl * TAB_WIDTH, "", anode_get_type_str(anode));
	twl_lst_push(out_list, tmp);
	if (anode_get_type(anode) == STRING_LITERAL)
	{
		t_string_literal *string = anode;
		twl_asprintf(&tmp, " \"%s\"", string->text);
		twl_lst_push(out_list, tmp);
	}
	twl_lst_push(out_list, twl_strdup("\n"));
	lvl++;
	if (anode_get_type(anode) == COMPOUND_STMT)
	{
		t_compound_stmt		*compound_stmt = anode;
		twl_lst_iter2(compound_stmt->items, travel_rec, &lvl, out_list);
	}
	else if (anode_get_type(anode) == IF_STMT)
	{
		t_if_stmt			*if_stmt = anode;
		travel_rec(if_stmt->cond, &lvl, out_list);
		travel_rec(if_stmt->body, &lvl, out_list);
		travel_rec(if_stmt->elze, &lvl, out_list);
	}
	else if (anode_get_type(anode) == CMD_STMT)
	{
		t_cmd_stmt			*cmd_stmt = anode;
		twl_lst_iter2(cmd_stmt->strings, travel_rec, &lvl, out_list);
	}
	else if (anode_get_type(anode) == PIPELINE)
	{
		t_pipeline			*pipeline = anode;
		travel_rec(pipeline->left, &lvl, out_list);
		travel_rec(pipeline->right, &lvl, out_list);
	}
}

char				*ast_to_str(t_ast *this)
{
	int				lvl;
	t_lst			*out_list;
	char			*out;

	out_list = twl_lst_new();
	lvl = 0;
	travel_rec(this->root, &lvl, out_list);
	out = twl_lst_strjoin(out_list, "");
	twl_lst_del(out_list, free);
	return (out);
}
