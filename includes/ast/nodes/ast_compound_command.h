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

# include "token/token_mgr.h"
# include "ast/ast_utils.h"
# include "ast/ast_defines.h"

# include "ast/nodes/ast_redir.h"

# include "ast/nodes/ast_brace_group.h"
# include "ast/nodes/ast_subshell.h"
# include "ast/nodes/ast_for_clause.h"
# include "ast/nodes/ast_case_clause.h"
# include "ast/nodes/ast_if_clause.h"
# include "ast/nodes/ast_while_clause.h"
# include "ast/nodes/ast_until_clause.h"

typedef enum		s_compound_command_type
{
	COMPOUND_COMMAND_NONE = 0,
	COMPOUND_COMMAND_SUBSHELL,
	COMPOUND_COMMAND_IF_CLAUSE,
	COMPOUND_COMMAND_FOR_CLAUSE,
	COMPOUND_COMMAND_WHILE_CLAUSE,
	COMPOUND_COMMAND_CASE_CLAUSE,
	COMPOUND_COMMAND_UNTIL_CLAUSE,
	COMPOUND_COMMAND_BRACE_GROUP,
	COMPOUND_COMMAND_NBR
}					t_compound_command_type;

typedef struct		s_ast_compound_command
{
	t_compound_command_type		command_type;
	void						*command;
	t_lst						*command_tokens;
	t_lst						*redir_items;
	t_lst						*redir_fds;
}					t_ast_compound_command;

t_ast_compound_command		*ast_compound_command_new(void);
void						ast_compound_command_del(t_ast_compound_command *ast_compound_command);

t_ast_compound_command		*ast_compound_command_new_from_tokens(t_lst *tokens, struct s_ast *ast);
void						ast_compound_command_print_rec(t_ast_compound_command *ast_compound_command, int depth);

bool						ast_compound_command_is_own_type(t_lst *tokens);

typedef void *(*t_compound_command_new_from_token_fn)(t_lst *tokens, struct s_ast *ast);
typedef void (*t_compound_command_print_rec_fn)(void *command, int depth);
typedef void (*t_compound_command_print_del_fn)(void *command);
typedef void (*t_compound_command_exec_fn)(void *command);

t_compound_command_new_from_token_fn *compound_command_from_token_fns(void);
t_compound_command_type	ast_compound_command_get_type_from_tokens(t_lst *tokens);

void				ast_compound_command_exec(t_ast_compound_command *this);

#endif
