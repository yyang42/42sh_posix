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

#ifndef AST_FUNCTION_DEF_H
# define AST_FUNCTION_DEF_H

# include "basics.h"

# include "token/token_mgr.h"
# include "ast/ast_utils.h"
# include "ast/ast_defines.h"

struct s_ast_compound_command;

typedef struct						s_ast_function_def
{
	void							*name;
	struct s_ast_compound_command	*compound_command;
	t_lst							*redir_items;
	t_lst							*func_def_tokens;
}									t_ast_function_def;

t_ast_function_def					*ast_function_def_new(void);
void								ast_function_def_del(
										t_ast_function_def *ast_function_def);

t_ast_function_def					*ast_function_def_new_from_tokens(
										t_lst *tokens, struct s_ast *ast);
void								ast_function_def_print_rec(
										t_ast_function_def *ast_function_def,
										int depth);
void								ast_function_def_print_function(
										t_ast_function_def *ast_function_def,
										int depth);

bool								ast_function_def_is_own_type(t_lst *tokens);

void								ast_function_def_exec(
										t_ast_function_def *this);
void								ast_function_def_exec_void(void *this);

#endif
