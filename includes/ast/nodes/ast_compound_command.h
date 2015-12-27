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

# include "ast/nodes/ast_subshell.h"
# include "ast/nodes/ast_if_clause.h"

typedef enum		s_compound_command_type
{
	COMPOUND_COMMAND_NONE = 0,
	COMPOUND_COMMAND_SUBSHELL,
	COMPOUND_COMMAND_IF_CLAUSE,
	COMPOUND_COMMAND_NBR
}					t_compound_command_type;

typedef struct		s_ast_compound_command
{
	t_lst						*tokens;
	void						*command;
	t_compound_command_type		type;
}					t_ast_compound_command;

t_ast_compound_command		*ast_compound_command_new(void);
void						ast_compound_command_del(t_ast_compound_command *ast_compound_command);

t_ast_compound_command		*ast_compound_command_new_from_tokens(t_lst *tokens);
void						ast_compound_command_print_rec(t_ast_compound_command *ast_compound_command, int depth);

bool						ast_compound_command_is_own_type(t_lst *tokens);

typedef void *(*t_compound_command_new_from_token_fn)(t_lst *tokens);
typedef void (*t_compound_command_print_rec_fn)(void *command, int depth);

#endif
