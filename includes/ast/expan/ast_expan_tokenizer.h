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

#ifndef AST_EXPAN_TOKENIZER_H
# define AST_EXPAN_TOKENIZER_H

# include "basics.h"
# include "ast/ast.h"
# include "token/token.h"
# include "ast/expan/ast_expan_type.h"
# include "ast/expan/ast_expan_token.h"

typedef struct			s_expan_tokenizer
{
	int				i;
	int				last;
	t_expan_type	type;
	bool			is_between_dq;
	bool			is_between_sq;
	t_token_origin	origin;
}						t_expan_tokenizer;

t_expan_tokenizer				*expan_tokenizer_new(void);
void							expan_tokenizer_del(t_expan_tokenizer *tokenizer);
void							expan_token_mgr_add(t_lst *tokens, t_expan_token *token);
char							*expan_tokenizer_concat(t_lst *lst);
void							expan_tokenizer(t_ast_simple_command *cmd,
	char *str, t_lst *expan_tokens, t_token_origin origin);
void							expan_tokenizer_none(t_lst *expan_tokens,
	char *str, int len);
int								expan_tokenizer_param(t_expan_tokenizer *tokenizer,
	t_lst *expan_tokens, char *str,  int i);
int								expan_tokenizer_param_special(t_expan_token *expan_token,
	char *str, int i);

#endif
