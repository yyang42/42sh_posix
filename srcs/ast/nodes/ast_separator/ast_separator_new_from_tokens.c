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

#include "ast/nodes/ast_separator.h"

t_ast_separator	*ast_separator_new_from_tokens(t_lst *tokens)
{
	t_ast_separator		*ast_separator;
	t_token			*first_token;

	ast_separator = ast_separator_new();
	first_token = twl_lst_first(tokens);
	if (twl_strequ(first_token->text, "\n"))
	{
		ast_separator->type = AST_SEPERATOR_NEWLINE_LIST;
		ast_separator->u.newline_list = ast_newline_list_new_from_tokens(tokens);
	}
	return (ast_separator);
	(void)tokens;
}
