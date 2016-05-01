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

#include "ast/nodes/ast_case_item.h"
#include "ast/nodes/ast_compound_list.h"

void				ast_case_item_print_function(t_ast_case_item *this,
													int depth)
{
	char			*joined_patterns;

	joined_patterns = token_mgr_strjoin(this->pattern_tokens, " | ");
	twl_printf("\n%*c%s)", depth * 4, ' ', joined_patterns);
	ast_compound_list_print_function(this->compound_list, depth + 1);
	twl_printf("\n%*c;;", depth * 4, ' ');
	free(joined_patterns);
}
