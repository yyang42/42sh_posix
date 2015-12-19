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

#include "utils.h"

#include "ast/nodes/ast_if.h"
#include "ast/nodes/ast_cmd.h"
#include "ast/nodes/ast_cmd_field.h"
#include "ast/nodes/ast_pipe.h"
#include "ast/nodes/ast_andor.h"

static bool			is_ast_if(char *str)
{
	if (twl_str_starts_with(str, "if "))
		return (true);
	else
		return (false);
}

static int			ast_build_ast_list_lists(t_ast_list *ast_list, char *str)
{
	int				len;
	char			*not_comp_stmt;

	not_comp_stmt = twl_str_split_get(str, AST_SEPARATOR, 0);
	len = 0;
	if ((twl_strstr(str, "&&") || twl_strstr(str, "||")) && "TODO is_ast_andor")
	{
		twl_lst_push(ast_list->andors, ast_andor_build(not_comp_stmt, &len));
	}
	else if (twl_strchr(str, '|') && "TODO is_pipe_case")
	{
		twl_lst_push(ast_list->andors, ast_pipe_build(not_comp_stmt, &len));
	}
	else if ("TODO is_a_simple_cmd")
	{
		twl_lst_push(ast_list->andors, ast_cmd_build(not_comp_stmt, &len));
	}
	return (len + twl_strlen(AST_SEPARATOR));
}

t_ast_list		*ast_list_build(char *str, int *len_ptr)
{
	int				len;
	int				total_len;
	t_ast_list	*ast_list;

	ast_list = ast_list_new();
	total_len = twl_strlen(str);
	len = 0;
	while (len < total_len)
	{
		if (is_ast_if(str + len))
		{
			twl_lst_push(ast_list->andors, ast_if_build(str + len, &len));
		}
		else
		{
			len += ast_build_ast_list_lists(ast_list, str + len);
		}
	}
	increment_len(len_ptr, len);
	return (ast_list);
}
