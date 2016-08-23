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

#ifndef AST_SUBSHELL_H
# define AST_SUBSHELL_H

# include "basics.h"

# include "token/token_mgr.h"

# include "ast/ast_defines.h"
# include "ast/ast_utils.h"

struct s_ast_compound_list;
typedef struct					s_ast_subshell
{
	t_lst						*tokens;
	struct s_ast_compound_list	*ast_compound_list;
}								t_ast_subshell;

t_ast_subshell					*ast_subshell_new(void);
void							ast_subshell_del(t_ast_subshell *ast_subshell);
void							ast_subshell_del_void(void *this);

t_ast_subshell					*ast_subshell_new_from_tokens(t_lst *tokens,
														struct s_ast *ast);
void							*ast_subshell_new_from_tokens_void(
														t_lst *tokens,
														struct s_ast *ast);
void							ast_subshell_print_rec(
												t_ast_subshell *ast_subshell,
												int depth);
void							ast_subshell_print_rec_void(void *ast_subshell,
																	int depth);

void							ast_subshell_print_function(
												t_ast_subshell *ast_subshell,
												int depth);
void							ast_subshell_print_function_void(
												void *ast_subshell,
												int depth);

bool							ast_subshell_is_own_type(t_lst *tokens);

void							ast_subshell_exec(t_ast_subshell *this);
void							ast_subshell_exec_void(void *this);

#endif
