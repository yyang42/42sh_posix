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
# include "ast/expan/ast_expan.h"

void							expan_tokenizer(t_ast_simple_command *cmd,
	t_token *token, t_lst *expan_tokens);

#endif
