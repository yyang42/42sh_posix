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

# include "token_mgr.h"
# include "ast/ast_utils.h"

typedef struct		s_ast_pipe_item
{
	t_lst			*tokens;
}					t_ast_pipe_item;

t_ast_pipe_item			*ast_pipe_item_new(void);
void				ast_pipe_item_del(t_ast_pipe_item *ast_pipe_item);

t_ast_pipe_item		*ast_pipe_item_new_from_tokens(t_lst *tokens);
void				ast_pipe_item_print_rec(t_ast_pipe_item *ast_pipe_item, int depth);

bool				ast_pipe_item_is_delimiter(t_token *token);

#endif
