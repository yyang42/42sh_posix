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

#include "token/token_mgr.h"
#include "token/token_list_mgr.h"

#include "ast/ast.h"
#include "ast/nodes/ast_andor_item.h"
#include "ast/nodes/ast_list_item.h"

void	*ast_andor_item_new_from_tokens_void(t_lst *tokens, struct s_ast *ast)
{
	return (ast_andor_item_new_from_tokens(tokens, ast));
}
