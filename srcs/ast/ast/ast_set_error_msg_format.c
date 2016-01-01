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
#include "token_mgr.h"
#include "twl_printf.h"

void				ast_set_error_msg_format_do(t_ast *ast, t_token *token, char *msg)
{
	twl_asprintf(&ast->error_msg, "SyntaxError %d:%d : %s",
				token->line, token->col, msg);
}

void				ast_set_error_msg_format(t_ast *ast, t_token *token, const char *fmt, ...)
{
	t_pf	*pf;
	size_t	len;
	char			*msg;

	pf = pf_create((char *)fmt);
	va_start(pf->arglist, (char *)fmt);
	pf_prepare_xprintf__(pf);
	va_end(pf->arglist);
	msg = twl_strdup(pf->output);
	// ast_set_error_msg_format()
	ast_set_error_msg_format_do(ast, token, msg);
	len = pf->output_len;
	pf_free(pf);
	// return (msg);
}
