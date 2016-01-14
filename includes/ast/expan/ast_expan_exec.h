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

#ifndef AST_EXPAN_EXEC_H
# define AST_EXPAN_EXEC_H

# include "ast/expan/ast_expan_tokenizer.h"
# include "ast/expan/ast_expan_token.h"
# include "ast/expan/ast_expan_param.h"
# include "basics.h"

void			expan_exec(t_lst *expan_tokens);
void			expan_exec_param(t_expan_token *expan_token);
void			expan_exec_param_star(t_expan_token *expan_token,
	t_expan_param *expan_param);
void			expan_exec_param_zero(t_expan_token *expan_token,
	t_expan_param *expan_param);

#endif
