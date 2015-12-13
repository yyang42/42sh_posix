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
#include "ast/anode/ast_if.h"
#include "ast/anode/string_literal.h"
#include "ast/anode/pipeline.h"
#include "ast/anode/andor.h"

void				travel_rec(void *anode, void *lvl_ptr, void *out_list);

void				cmd_literal_group(t_lst *literals, char *group_name,
													int lvl, t_lst *out_list)
{
	char			*tmp;

	if (twl_lst_len(literals) == 0)
		return ;
	twl_asprintf(&tmp, "%*s<%s>\n", lvl * TAB_WIDTH, "", group_name);
	lvl++;
	twl_lst_push(out_list, tmp);
	twl_lst_iter2(literals, travel_rec, &lvl, out_list);
}

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
	if (anode_get_type(anode) == ANDOR)
	{
		t_andor			*andor = anode;
		twl_lst_push(out_list, (andor->andor_type == ANDOR_TYPE_AND) ? twl_strdup(" 'and'") : twl_strdup(" 'or'"));
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
		t_ast_if			*ast_if = anode;
		travel_rec(ast_if->cond, &lvl, out_list);
		travel_rec(ast_if->body, &lvl, out_list);
		travel_rec(ast_if->elze, &lvl, out_list);
	}
	else if (anode_get_type(anode) == CMD_STMT)
	{
		t_cmd_stmt			*cmd_stmt = anode;
		cmd_literal_group(cmd_stmt->strings, "strings", lvl, out_list);
		cmd_literal_group(cmd_stmt->redir_in, "redir_in", lvl, out_list);
		cmd_literal_group(cmd_stmt->redir_out, "redir_out", lvl, out_list);
	}
	else if (anode_get_type(anode) == PIPELINE)
	{
		t_pipeline			*pipeline = anode;
		travel_rec(pipeline->left, &lvl, out_list);
		travel_rec(pipeline->right, &lvl, out_list);
	}
	else if (anode_get_type(anode) == ANDOR)
	{
		t_andor			*andor = anode;
		travel_rec(andor->left, &lvl, out_list);
		travel_rec(andor->right, &lvl, out_list);
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
