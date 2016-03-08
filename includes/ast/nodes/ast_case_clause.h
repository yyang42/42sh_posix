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

#ifndef AST_CASE_CLAUSE_H
# define AST_CASE_CLAUSE_H

# include "basics.h"

# include "token/token_mgr.h"

# include "ast/ast_defines.h"
# include "ast/ast_utils.h"

struct s_ast_compound_list;

typedef struct		s_ast_case_clause
{
	t_token			*needle_token;
	t_lst			*case_list;
}					t_ast_case_clause;

t_ast_case_clause	*ast_case_clause_new(void);
void				ast_case_clause_del(t_ast_case_clause *ast_case_clause);
void				ast_case_clause_del_void(void *this);

t_ast_case_clause	*ast_case_clause_new_from_tokens(t_lst *tokens, struct s_ast *ast);
void				*ast_case_clause_new_from_tokens_void(t_lst *tokens, struct s_ast *ast);
void				ast_case_clause_print_rec(t_ast_case_clause *ast_case_clause, int depth);
void				ast_case_clause_print_rec_void(void *ast_case_clause, int depth);

bool				ast_case_clause_is_own_type(t_lst *tokens);

void				ast_case_clause_exec(t_ast_case_clause *this);
void				ast_case_clause_exec_void(void *this);

#endif
