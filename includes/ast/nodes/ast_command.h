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

#ifndef AST_COMMAND_H
# define AST_COMMAND_H

# include "basics.h"

# include "token/token_mgr.h"
# include "ast/ast_utils.h"
# include "ast/ast_defines.h"

# include "ast/nodes/ast_simple_command.h"
# include "ast/nodes/ast_compound_command.h"
# include "ast/nodes/ast_function_def.h"

typedef enum		e_command_type
{
	COMMAND_SIMPLE_COMMAND,
	COMMAND_COMPOUND_COMMAND,
	COMMAND_FUNCTION_DEF
}					t_command_type;

typedef struct		s_ast_command
{
	t_command_type	command_type;
	void			*command;
}					t_ast_command;

t_ast_command		*ast_command_new(void);
void				ast_command_del(t_ast_command *ast_command);

t_ast_command		*ast_command_new_from_tokens(t_lst *tokens,
		struct s_ast *ast);
t_ast_command		*ast_command_new_from_tokens(t_lst *tokens,
		struct s_ast *ast);
void				ast_command_print_rec(t_ast_command *ast_command,
		int depth);
void				ast_command_print_function(t_ast_command *ast_command,
		int depth);

t_command_type		ast_command_utils_get_command_type(t_lst *tokens);

void				ast_command_exec(t_ast_command *this);
int					ast_command_expan(t_ast_command *this);

#endif
