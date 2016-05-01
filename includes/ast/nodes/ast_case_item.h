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

#ifndef AST_CASE_ITEM_H
# define AST_CASE_ITEM_H

# include "basics.h"

# include "token/token_mgr.h"

# include "ast/ast_defines.h"
# include "ast/ast_utils.h"

# include "ast/nodes/ast_compound_list.h"

typedef struct				s_ast_case_item
{
	t_lst					*pattern_tokens;
	t_ast_compound_list		*compound_list;
}							t_ast_case_item;

t_ast_case_item				*ast_case_item_new(void);
void						ast_case_item_del(t_ast_case_item *ast_case_item);
void						ast_case_item_del_void(void *ast_case_item);

t_ast_case_item				*ast_case_item_new_from_tokens(t_lst *tokens,
															struct s_ast *ast);
void						*ast_case_item_new_from_tokens_void(t_lst *tokens,
															struct s_ast *ast);
void						ast_case_item_print_rec(
									t_ast_case_item *ast_case_item, int depth);
void						ast_case_item_print_function(
									t_ast_case_item *ast_case_item, int depth);

bool						ast_case_item_is_own_type(t_lst *tokens);

#endif
