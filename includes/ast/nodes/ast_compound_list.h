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

#ifndef AST_COMPLETE_COMMAND_H
# define AST_COMPLETE_COMMAND_H

# include "basics.h"

# include "token/token_mgr.h"

# include "ast/ast_utils.h"
# include "ast/ast_defines.h"

# include "ast/nodes/ast_list_item.h"

typedef struct				s_ast_compound_list
{
	t_lst					*ast_list_items;
}							t_ast_compound_list;

t_ast_compound_list			*ast_compound_list_new(void);
void						ast_compound_list_del(t_ast_compound_list *ast_compound_list);

t_ast_compound_list			*ast_compound_list_new_from_tokens(t_lst *tokens, struct s_ast *ast);
void						ast_compound_list_print_rec(t_ast_compound_list *ast_compound_list, int depth);

int							ast_compound_list_exec(t_ast_compound_list *ast_compound_list);
int							ast_compound_list_expan(t_ast_compound_list *ast_compound_list);

#endif
