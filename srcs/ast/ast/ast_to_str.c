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

#include "ast/nodes/ast_node.h"
#include "ast/nodes/ast_if.h"
#include "ast/nodes/ast_cmd_field.h"
#include "ast/nodes/ast_pipe.h"
#include "ast/nodes/ast_andor.h"
#include "ast/nodes/ast_cmd_sub.h"

void				travel_rec(void *ast_node, void *lvl_ptr, void *out_list);

void				cmd_literal_group(t_lst *literals, char *group_name,
													int lvl, t_lst *out_list)
{
	char			*tmp;

	if (twl_lst_len(literals) == 0)
		return ;
	twl_asprintf(&tmp, "%*s<%s>\n", lvl * AST_TAB_WIDTH, "", group_name);
	lvl++;
	twl_lst_push(out_list, tmp);
	twl_lst_iter2(literals, travel_rec, &lvl, out_list);
}

void				travel_rec(void *ast_node, void *lvl_ptr, void *out_list)
{
	int				lvl;
	char			*tmp;

	lvl = *(int *)lvl_ptr;
	twl_asprintf(&tmp, "%*s%s", lvl * AST_TAB_WIDTH, "", ast_node_get_type_str(ast_node));
	twl_lst_push(out_list, tmp);
	if (ast_node_get_type(ast_node) == AST_STRING)
	{
		t_ast_string *string = ast_node;
		twl_asprintf(&tmp, " \"%s\"", string->text);
		twl_lst_push(out_list, tmp);
	}
	if (ast_node_get_type(ast_node) == AST_ANDOR)
	{
		t_ast_andor			*ast_andor = ast_node;
		twl_lst_push(out_list, (ast_andor->andor_type == ANDOR_TYPE_AND) ? twl_strdup(" 'and'") : twl_strdup(" 'or'"));
	}

	twl_lst_push(out_list, twl_strdup("\n"));
	lvl++;
	if (ast_node_get_type(ast_node) == AST_CMD_FIELD)
	{
		t_ast_cmd_field *cmd_field = ast_node;
		twl_lst_iter2(cmd_field->items, travel_rec, &lvl, out_list);
	}
	if (ast_node_get_type(ast_node) == AST_LIST)
	{
		t_ast_list		*ast_list = ast_node;
		twl_lst_iter2(ast_list->items, travel_rec, &lvl, out_list);
	}
	else if (ast_node_get_type(ast_node) == AST_IF)
	{
		t_ast_if			*ast_if = ast_node;
		travel_rec(ast_if->cond, &lvl, out_list);
		travel_rec(ast_if->body, &lvl, out_list);
		travel_rec(ast_if->elze, &lvl, out_list);
	}
	else if (ast_node_get_type(ast_node) == AST_CMD)
	{
		t_ast_cmd			*ast_cmd = ast_node;
		cmd_literal_group(ast_cmd->strings, "fields", lvl, out_list);
		cmd_literal_group(ast_cmd->redir_in, "redir_in", lvl, out_list);
		cmd_literal_group(ast_cmd->redir_out, "redir_out", lvl, out_list);
	}
	else if (ast_node_get_type(ast_node) == AST_PIPE)
	{
		t_ast_pipe			*ast_pipe = ast_node;
		travel_rec(ast_pipe->left, &lvl, out_list);
		travel_rec(ast_pipe->right, &lvl, out_list);
	}
	else if (ast_node_get_type(ast_node) == AST_ANDOR)
	{
		t_ast_andor			*ast_andor = ast_node;
		travel_rec(ast_andor->left, &lvl, out_list);
		travel_rec(ast_andor->right, &lvl, out_list);
	}
	else if (ast_node_get_type(ast_node) == AST_CMD_SUB)
	{
		t_ast_cmd_sub			*ast_cmd_sub = ast_node;
		travel_rec(ast_cmd_sub->list, &lvl, out_list);
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
