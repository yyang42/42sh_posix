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

#include "ast/nodes/ast_simple_command.h"
#include "ast/nodes/ast_assignment.h"
#include "ast/nodes/ast_redir.h"
#include "environment.h"

// "tilde-prefix" consists of an unquoted <tilde> character at the beginning of a word,
//followed by all of the characters preceding the first unquoted <slash> in the word,
// or all the characters in the word if there is no <slash>

/*
In an assignment (see XBD Variable Assignment),
multiple tilde-prefixes can be used: at the beginning of the word (that is, following the <equals-sign> of the assignment),
following any unquoted <colon>, or both. A tilde-prefix in an assignment is terminated by the first unquoted <colon> or <slash>.
*/
void	ast_simple_command_expan_tilde_assign(t_token *token)
{
	char	*save_string;

	save_string = NULL;
	if (token->text)
		save_string = twl_strdup(token->text);

	// t_token *token;
	// char	*words;
	// char	*home;
	// t_environment	*env;
	//
	// token = cmd->command_tokens;
	// words = twl_strsplit(token->text, " ")
	// env = environment_singleton();
	// if (!isDoubleQuoted(token->text) && !isSingleQuoted(token->text)){
	// 	twl_strdel(&token->text);
	// 	home = environment_getenv_value(env, "HOME")
	// 	if (home)
	// 		token->text = twl_strdup(home);
	// 	else
	// 		token->text = twl_strdup("");
	// }
}
