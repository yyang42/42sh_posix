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

static void			push_data01(t_lst *data)
{
	token_type_item_mgr_add(data, "\n", TOKEN_NEWLINE);
	token_type_item_mgr_add(data, "&&", TOKEN_AND_IF);
	token_type_item_mgr_add(data, "||", TOKEN_OR_IF);
	token_type_item_mgr_add(data, ";;", TOKEN_DSEMI);
	token_type_item_mgr_add(data, "<<", TOKEN_DLESS);
	token_type_item_mgr_add(data, ">>", TOKEN_DGREAT);
	token_type_item_mgr_add(data, "<&", TOKEN_LESSAND);
	token_type_item_mgr_add(data, ">&", TOKEN_GREATAND);
	token_type_item_mgr_add(data, "<>", TOKEN_LESSGREAT);
	token_type_item_mgr_add(data, "<<-", TOKEN_DLESSDASH);
	token_type_item_mgr_add(data, ">|", TOKEN_CLOBBER);
	token_type_item_mgr_add(data, "if", TOKEN_IF);
	token_type_item_mgr_add(data, "then", TOKEN_THEN);
	token_type_item_mgr_add(data, "else", TOKEN_ELSE);
}

static void			push_data02(t_lst *data)
{
	token_type_item_mgr_add(data, "elif", TOKEN_ELIF);
	token_type_item_mgr_add(data, "fi", TOKEN_FI);
	token_type_item_mgr_add(data, "do", TOKEN_DO);
	token_type_item_mgr_add(data, "done", TOKEN_DONE);
	token_type_item_mgr_add(data, "case", TOKEN_CASE);
	token_type_item_mgr_add(data, "esac", TOKEN_ESAC);
	token_type_item_mgr_add(data, "while", TOKEN_WHILE);
	token_type_item_mgr_add(data, "until", TOKEN_UNTIL);
	token_type_item_mgr_add(data, "for", TOKEN_FOR);
	token_type_item_mgr_add(data, "{", TOKEN_LBRACE);
	token_type_item_mgr_add(data, "}", TOKEN_RBRACE);
	token_type_item_mgr_add(data, "!", TOKEN_BANG);
	token_type_item_mgr_add(data, "in", TOKEN_IN);
}

t_lst				*data_token_item_list(void)
{
	static t_lst	*data = NULL;

	if (data == NULL)
	{
		data = twl_lst_new();
		push_data01(data);
		push_data02(data);
	}
	return (data);
}
