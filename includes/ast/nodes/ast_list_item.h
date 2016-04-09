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

#ifndef AST_AND_OR_SEQ_H
# define AST_AND_OR_SEQ_H

# include "basics.h"

# include "token/token_mgr.h"

# include "ast/ast_defines.h"
# include "ast/ast_utils.h"

# include "ast/nodes/ast_andor_item.h"
# include "job_control/job.h"

typedef struct		s_ast_list_item
{
	t_lst			*ast_andor_items;
	t_token			*separator;
	t_lst			*list_item_tokens;
}					t_ast_list_item;

t_ast_list_item		*ast_list_item_new(void);
void				ast_list_item_del(t_ast_list_item *ast_list_item);

t_ast_list_item		*ast_list_item_new_from_tokens(t_lst *tokens, struct s_ast *ast);
void				*ast_list_item_new_from_tokens_void(t_lst *tokens, struct s_ast *ast);

void				ast_list_item_print_rec(t_ast_list_item *ast_list_item, int depth);

bool				ast_list_item_is_delimiter(t_token *token);

void				ast_list_item_exec(t_ast_list_item *ast_list_item);
void				ast_list_item_exec_async(t_ast_list_item *this);
t_job				*ast_list_item_exec_async_parent_create_job(t_lst *tokens, pid_t pid);
int					ast_list_item_expan(t_ast_list_item *ast_list_item);

void				ast_list_item_set_separator(t_ast_list_item *this, t_token *token);
void				ast_list_item_set_separator_void(void *this, t_token *token);

#endif
