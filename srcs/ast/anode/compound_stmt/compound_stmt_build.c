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

#include "ast/anode/ast_if.h"
#include "ast/anode/cmd_stmt.h"
#include "ast/anode/string_literal.h"
#include "ast/anode/pipeline.h"
#include "ast/anode/ast_andor.h"

static bool			is_ast_if(char *str)
{
	if (twl_str_starts_with(str, "if "))
		return (true);
	else
		return (false);
}

static int			ast_build_compound_stmt_lists(t_compound_stmt *compound_stmt, char *str)
{
	int				len;
	char			*not_comp_stmt;

	not_comp_stmt = twl_str_split_get(str, AST_SEPARATOR, 0);
	len = 0;
	if ((twl_strstr(str, "&&") || twl_strstr(str, "||")) && "TODO is_ast_andor")
	{
		COUCOU;
		twl_lst_push(compound_stmt->items, ast_andor_build(not_comp_stmt, &len));
		COUCOU;
	}
	else if (twl_strchr(str, '|') && "TODO is_pipe_case")
	{
		twl_lst_push(compound_stmt->items, pipeline_build(not_comp_stmt, &len));
	}
	else if ("TODO is_a_simple_cmd")
	{
		twl_lst_push(compound_stmt->items, cmd_stmt_build(not_comp_stmt, &len));
	}
	return (len + twl_strlen(AST_SEPARATOR));
}

t_compound_stmt		*compound_stmt_build(char *str, int *len_ptr)
{
	int				len;
	int				total_len;
	t_compound_stmt	*compound_stmt;

	compound_stmt = compound_stmt_new();
	total_len = twl_strlen(str);
	len = 0;
	while (len < total_len)
	{
		if (is_ast_if(str + len))
		{
			twl_lst_push(compound_stmt->items, ast_if_build(str + len, &len));
		}
		else
		{
			len += ast_build_compound_stmt_lists(compound_stmt, str + len);
		}
	}
	increment_len(len_ptr, len);
	return (compound_stmt);
}
