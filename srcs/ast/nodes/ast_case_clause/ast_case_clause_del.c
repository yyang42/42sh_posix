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

#include "ast/nodes/ast_if_then.h"
#include "ast/nodes/ast_case_clause.h"
#include "ast/nodes/ast_case_item.h"

void				ast_case_clause_del(t_ast_case_clause *this)
{
	token_del(this->needle_token);
	token_del(this->needle_expanded);
	twl_lst_del(this->case_list, ast_case_item_del);
	free(this);
}
