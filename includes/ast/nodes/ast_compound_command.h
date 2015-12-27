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

#ifndef AST_COMPOUND_COMMAND_H
# define AST_COMPOUND_COMMAND_H

# include "basics.h"

# include "token_mgr.h"
# include "ast/ast_utils.h"

typedef struct		s_ast_compound_command
{
	t_lst			*tokens;
}					t_ast_compound_command;

t_ast_compound_command			*ast_compound_command_new(void);
void				ast_compound_command_del(t_ast_compound_command *ast_compound_command);

t_ast_compound_command		*ast_compound_command_new_from_tokens(t_lst *tokens);
void				ast_compound_command_print_rec(t_ast_compound_command *ast_compound_command, int depth);

bool				ast_compound_command_is_own_type(t_lst *tokens);

#endif
