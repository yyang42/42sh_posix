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

	ast_separator = ast_separator_new();
	if (ast_newline_list_is_own_type(tokens))
	{
		ast_separator->type = AST_SEPERATOR_NEWLINE_LIST;
		ast_separator->u.newline_list = ast_newline_list_new_from_tokens(tokens);
	}
	return (ast_separator);
	(void)tokens;
}
