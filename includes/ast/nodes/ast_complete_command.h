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

# include "token_mgr.h"
# include "ast/ast_utils.h"
# include "ast/nodes/ast_list_item.h"

typedef struct				s_ast_complete_command
{
	t_lst					*ast_list_item_lst;
}							t_ast_complete_command;

t_ast_complete_command		*ast_complete_command_new(void);
void						ast_complete_command_del(t_ast_complete_command *ast_complete_command);

t_ast_complete_command		*ast_complete_command_new_from_tokens(t_lst *tokens);
void						ast_complete_command_print_rec(t_ast_complete_command *ast_complete_command, int depth);

#endif
