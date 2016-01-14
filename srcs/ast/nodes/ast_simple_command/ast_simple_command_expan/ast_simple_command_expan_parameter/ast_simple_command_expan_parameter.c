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
#include "environment.h"


void	ast_simple_command_expan_unenclose_parameter(t_token *token, int i){
	(void)token;
	(void)i;
}

void	ast_simple_command_expan_enclose_parameter(t_token *token, int i){
	if (token->text[i + 1] == '*')
		ast_simple_command_expan_star(token, i);
	else if (token->text[i + 1] == '#')
		ast_simple_command_expan_sharp(token, i);
	else if (token->text[i + 1] == '-')
		ast_simple_command_expan_hyphen(token, i);
	else if (token->text[i + 1] == '0')
		ast_simple_command_expan_zero(token, i);
	else if (token->text[i + 1] == '?')
		ast_simple_command_expan_question(token, i);
	else if (token->text[i + 1] == '@')
		ast_simple_command_expan_at(token, i);
	else if (token->text[i + 1] == '!')
		ast_simple_command_expan_exclamation(token, i);
	else if (token->text[i + 1] == '$')
		ast_simple_command_expan_dollar(token, i);
}

//#2.2.3 Double-Quotes
void	ast_simple_command_expan_parameter(t_token *token)
{
	int		i;
	bool	isDoubleQuoted;
	bool	isSingleQuoted;

	i = 0;
	isDoubleQuoted = false;
	isSingleQuoted = false;
	if (token->text)
	{
		while (token->text[i] != 0)
		{
			if (token->text[i] == '$' && !isSingleQuoted)
			{
				if (token->text[i + 1] == '{')
					ast_simple_command_expan_enclose_parameter(token, i);
				else
					ast_simple_command_expan_unenclose_parameter(token, i);
			}
			else if (token->text[i] == '\'')
				isSingleQuoted = !isSingleQuoted;
			else if (token->text[i] == '"')
				isDoubleQuoted = !isDoubleQuoted;
			i++;
		}
	}
}
