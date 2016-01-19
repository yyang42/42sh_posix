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

#ifndef AST_PIPE_SEQ_H
# define AST_PIPE_SEQ_H

# include "basics.h"
# include "execute.h"

# include "token/token_mgr.h"
# include "ast/ast_defines.h"
# include "ast/ast_utils.h"

# include "ast/nodes/ast_pipe_item.h"

typedef struct		s_ast_andor_item
{
	t_lst			*ast_pipe_items;
	t_token			*separator;
}					t_ast_andor_item;

t_ast_andor_item	*ast_andor_item_new(void);
void				ast_andor_item_del(t_ast_andor_item *ast_andor_item);

t_ast_andor_item	*ast_andor_item_new_from_tokens(t_lst *tokens, struct s_ast *ast);
void				*ast_andor_item_new_from_tokens_void(t_lst *tokens, struct s_ast *ast);
void				ast_andor_item_print_rec(t_ast_andor_item *ast_andor_item, int depth);

bool				ast_andor_item_is_delimiter(t_token *tokens);

int					ast_andor_item_exec(t_ast_andor_item *ast_andor_item);

void				ast_andor_item_set_separator(t_ast_andor_item *this, t_token *token);
void				ast_andor_item_set_separator_void(void *this, t_token *token);

#endif
