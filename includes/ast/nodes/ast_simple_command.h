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

#ifndef AST_SIMPLE_COMMAND_H
# define AST_SIMPLE_COMMAND_H

# include "basics.h"

# include "token/token_mgr.h"

# include "ast/ast_defines.h"
# include "ast/ast_utils.h"

typedef struct			s_ast_simple_command
{
	t_lst				*command_tokens;
	t_lst				*redir_items;
	t_lst				*assignment_items;
}						t_ast_simple_command;

t_ast_simple_command	*ast_simple_command_new(void);
void					ast_simple_command_del(t_ast_simple_command *ast_simple_command);

t_ast_simple_command	*ast_simple_command_new_from_tokens(t_lst *tokens, struct s_ast *ast);
void					ast_simple_command_print_rec(t_ast_simple_command *ast_simple_command, int depth);

bool					ast_simple_command_is_own_type(t_lst *tokens);
int						ast_simple_command_exec(t_ast_simple_command *cmd);

#endif
