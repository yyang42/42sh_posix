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

#include "twl_lst.h"

#include "token/token.h"
#include "token/token_type_item_mgr.h"

t_lst				*data_token_arexp_item_list(void)
{
	static t_lst	*data = NULL;

	if (data == NULL)
	{
		data = twl_lst_new();
		token_type_item_mgr_add(data, ",", TOK_AREXP_COMMA);
		token_type_item_mgr_add(data, "(", TOK_AREXP_LPARENTHESIS);
		token_type_item_mgr_add(data, ")", TOK_AREXP_RPARENTHESIS);
		token_type_item_mgr_add(data, "?", TOK_AREXP_QUESTION_MARK);
		token_type_item_mgr_add(data, ":", TOK_AREXP_COLON);
		token_type_item_mgr_add(data, "||", TOK_AREXP_LOGICAL_OR);
		token_type_item_mgr_add(data, "&&", TOK_AREXP_LOGICAL_AND);
		token_type_item_mgr_add(data, "|", TOK_AREXP_INC_OR);
		token_type_item_mgr_add(data, "^", TOK_AREXP_EXC_OR);
		token_type_item_mgr_add(data, "&", TOK_AREXP_AND);
		token_type_item_mgr_add(data, "+", TOK_AREXP_PLUS);
		token_type_item_mgr_add(data, "-", TOK_AREXP_MINUS);
		token_type_item_mgr_add(data, "*", TOK_AREXP_MUL);
		token_type_item_mgr_add(data, "/", TOK_AREXP_DIV);
		token_type_item_mgr_add(data, "%", TOK_AREXP_MOD);
		token_type_item_mgr_add(data, "<<", TOK_AREXP_LSHIFT);
		token_type_item_mgr_add(data, ">>", TOK_AREXP_RSHIFT);
		token_type_item_mgr_add(data, "|=", TOK_AREXP_ASSIGN_INC_OR);
		token_type_item_mgr_add(data, "^=", TOK_AREXP_ASSIGN_EXC_OR);
		token_type_item_mgr_add(data, "&=", TOK_AREXP_ASSIGN_AND);
		token_type_item_mgr_add(data, "+=", TOK_AREXP_ASSIGN_PLUS);
		token_type_item_mgr_add(data, "-=", TOK_AREXP_ASSIGN_MINUS);
		token_type_item_mgr_add(data, "*=", TOK_AREXP_ASSIGN_MUL);
		token_type_item_mgr_add(data, "/=", TOK_AREXP_ASSIGN_DIV);
		token_type_item_mgr_add(data, "%=", TOK_AREXP_ASSIGN_MOD);
		token_type_item_mgr_add(data, "<<=", TOK_AREXP_ASSIGN_LSHIFT);
		token_type_item_mgr_add(data, ">>=", TOK_AREXP_ASSIGN_RSHIFT);
		token_type_item_mgr_add(data, "~", TOK_AREXP_TILDE);
		token_type_item_mgr_add(data, "!", TOK_AREXP_EXC_MARK);
		token_type_item_mgr_add(data, "<", TOK_AREXP_LESS);
		token_type_item_mgr_add(data, ">", TOK_AREXP_GREAT);
		token_type_item_mgr_add(data, "<=", TOK_AREXP_LESS_EQ);
		token_type_item_mgr_add(data, ">=", TOK_AREXP_GREAT_EQ);
		token_type_item_mgr_add(data, "==", TOK_AREXP_EQUAL);
		token_type_item_mgr_add(data, "!=", TOK_AREXP_NOT_EQUAL);
	}
	return (data);
}

