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

#include "ast/ast.h"
#include "token/token_mgr.h"
#include "twl_printf.h"

void				ast_set_error_msg_syntax_error_near(t_ast *ast, t_token *token, char *msg)
{
	char			*error_msg;

	ast_set_error_msg_format(ast, token, "Syntax error near '%s'", token->text);
	if (msg)
	{
		twl_asprintf(&error_msg, "%s : %s", ast->error_msg, msg);
		free(ast->error_msg);
		ast->error_msg = error_msg;
	}
}
