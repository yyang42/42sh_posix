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

#ifndef AST_ASSIGNMENT_H
# define AST_ASSIGNMENT_H

# include "basics.h"

# include "token_mgr.h"
# include "ast/ast_utils.h"

typedef struct		s_ast_assignment
{
	t_lst			*tokens;
}					t_ast_assignment;

t_ast_assignment	*ast_assignment_new(void);
void				ast_assignment_del(t_ast_assignment *ast_assignment);

t_ast_assignment	*ast_assignment_new_from_tokens(t_lst *tokens);
void				*ast_assignment_new_from_tokens_void(t_lst *tokens);
void				ast_assignment_print_rec(t_ast_assignment *ast_assignment, int depth);

bool				ast_assignment_is_own_type(t_lst *tokens);

#endif
