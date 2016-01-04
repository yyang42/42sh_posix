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

#ifndef AST_CMD_SEQ_H
# define AST_CMD_SEQ_H

# include "basics.h"

# include "token/token_mgr.h"

# include "ast/ast_defines.h"
# include "ast/ast_utils.h"

# include "ast/nodes/ast_command.h"

typedef struct		s_ast_pipe_item
{
	t_ast_command	*ast_command;
	t_lst			*tokens;
	t_token			*separator;
}					t_ast_pipe_item;

t_ast_pipe_item		*ast_pipe_item_new(void);
void				ast_pipe_item_del(t_ast_pipe_item *ast_pipe_item);

t_ast_pipe_item		*ast_pipe_item_new_from_tokens(t_lst *tokens, t_token *sep, struct s_ast *ast);
void				ast_pipe_item_print_rec(t_ast_pipe_item *ast_pipe_item, int depth);

bool				ast_pipe_item_is_delimiter(t_token *token);

int					ast_pipe_item_exec(t_ast_pipe_item *ast_pipe_item);

#endif
