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

#ifndef AST_BRACE_GROUP_H
# define AST_BRACE_GROUP_H

# include "basics.h"

# include "token/token_mgr.h"

# include "ast/ast_defines.h"
# include "ast/ast_utils.h"

struct s_ast_compound_list;
typedef struct					s_ast_brace_group
{
	t_lst						*tokens;
	struct s_ast_compound_list	*ast_compound_list;
}								t_ast_brace_group;

t_ast_brace_group	*ast_brace_group_new(void);
void				ast_brace_group_del(t_ast_brace_group *ast_brace_group);
void				ast_brace_group_del_void(void *this);

t_ast_brace_group	*ast_brace_group_new_from_tokens(t_lst *tokens, struct s_ast *ast);
void				*ast_brace_group_new_from_tokens_void(t_lst *tokens, struct s_ast *ast);
void				ast_brace_group_print_rec(t_ast_brace_group *ast_brace_group, int depth);
void				ast_brace_group_print_rec_void(void *ast_brace_group, int depth);

bool				ast_brace_group_is_own_type(t_lst *tokens);

#endif
