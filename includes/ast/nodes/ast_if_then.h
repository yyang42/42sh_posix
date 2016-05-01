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

#ifndef AST_IF_THEN_H
# define AST_IF_THEN_H

# include "basics.h"

# include "token/token_mgr.h"

# include "ast/ast_defines.h"
# include "ast/ast_utils.h"

# include "ast/nodes/ast_compound_list.h"

typedef struct				s_ast_if_then
{
	t_ast_compound_list		*cond_compound;
	t_ast_compound_list		*then_compound;
}							t_ast_if_then;

t_ast_if_then				*ast_if_then_new(void);
void						ast_if_then_del(t_ast_if_then *ast_if_then);
void						ast_if_then_del_void(void *ast_if_then);

t_ast_if_then				*ast_if_then_new_from_tokens(t_lst *tokens,
														struct s_ast *ast);
void						*ast_if_then_new_from_tokens_void(t_lst *tokens,
														struct s_ast *ast);
void						ast_if_then_print_rec(t_ast_if_then *ast_if_then,
													int depth);
void						ast_if_then_print_function(
										t_ast_if_then *ast_if_then, int depth);

bool						ast_if_then_is_own_type(t_lst *tokens);

#endif
