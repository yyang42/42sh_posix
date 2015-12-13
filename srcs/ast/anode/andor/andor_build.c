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
#include "ast/anode/andor.h"
#include "ast/anode/cmd_stmt.h"
#include "ast/anode/string_literal.h"

t_andor				*andor_build_rec(char *str)
{
	t_andor			*andor;
	char			*and;
	char			*or;
	t_lst			*segs;

	and = twl_strstr_last(str, "&&");
	or = twl_strstr_last(str, "||");

	if (and && and > or)
	{
		segs = twl_str_split_to_lst(str, "&&");
		andor = andor_new(ANDOR_TYPE_AND);
	}
	else
	{
		segs = twl_str_split_to_lst(str, "||");
		andor = andor_new(ANDOR_TYPE_OR);
	}
	if ((twl_strstr_count(str, "&&") + twl_strstr_count(str, "||")) == 1)
	{
		andor->left = cmd_stmt_build(twl_lst_get(segs, 0), NULL);
		andor->right = cmd_stmt_build(twl_lst_get(segs, 1), NULL);
	}
	else
	{
		andor->left = andor_build_rec(twl_lst_get(segs, 0));
		andor->right = cmd_stmt_build(twl_lst_get(segs, 1), NULL);
	}
	twl_lst_del(segs, free);
	return (andor);
}

t_andor				*andor_build(char *str, int *len_ptr)
{
	t_andor			*andor;

	andor = andor_build_rec(str);
	increment_len(len_ptr, twl_strlen(str));
	return (andor);
}
