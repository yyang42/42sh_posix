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

# include "token_mgr.h"
# include "ast/ast_utils.h"

typedef struct		s_ast_and_or_seq
{
	t_lst			*tokens;
}					t_ast_and_or_seq;

t_ast_and_or_seq			*ast_and_or_seq_new(void);
void				ast_and_or_seq_del(t_ast_and_or_seq *ast_and_or_seq);

t_ast_and_or_seq		*ast_and_or_seq_new_from_tokens(t_lst *tokens);
void				ast_and_or_seq_print_rec(t_ast_and_or_seq *ast_and_or_seq, int depth);

bool				ast_and_or_seq_is_own_type(t_lst *tokens);

#endif
