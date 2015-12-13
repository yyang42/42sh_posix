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

#include "twl_lst.h"
#include "ast/anode/ast_andor.h"
#include "ast/anode/ast_cmd.h"
#include "ast/anode/string_literal.h"

t_ast_andor				*ast_andor_build_rec(char *str)
{
	t_ast_andor			*ast_andor;
	char			*and;
	char			*or;
	t_lst			*segs;

	and = twl_strstr_last(str, "&&");
	or = twl_strstr_last(str, "||");

	if (and && and > or)
	{
		segs = twl_str_split_to_lst(str, "&&");
		ast_andor = ast_andor_new(ANDOR_TYPE_AND);
	}
	else
	{
		segs = twl_str_split_to_lst(str, "||");
		ast_andor = ast_andor_new(ANDOR_TYPE_OR);
	}
	if ((twl_strstr_count(str, "&&") + twl_strstr_count(str, "||")) == 1)
	{
		ast_andor->left = ast_cmd_build(twl_lst_get(segs, 0), NULL);
		ast_andor->right = ast_cmd_build(twl_lst_get(segs, 1), NULL);
	}
	else
	{
		ast_andor->left = ast_andor_build_rec(twl_lst_get(segs, 0));
		ast_andor->right = ast_cmd_build(twl_lst_get(segs, 1), NULL);
	}
	twl_lst_del(segs, free);
	return (ast_andor);
}

t_ast_andor				*ast_andor_build(char *str, int *len_ptr)
{
	t_ast_andor			*ast_andor;

	ast_andor = ast_andor_build_rec(str);
	increment_len(len_ptr, twl_strlen(str));
	return (ast_andor);
}
