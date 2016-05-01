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

#include "ast/nodes/ast_for_clause.h"
#include "ast/nodes/ast_compound_list.h"
#include "ast/nodes/ast_if_then.h"

void				ast_for_clause_print_function(t_ast_for_clause *this,
																	int depth)
{
	char			*joined_wordlist;

	twl_printf("for %s", this->name);
	if (twl_lst_len(this->wordlist))
	{
		joined_wordlist = token_mgr_strjoin(this->wordlist, " ");
		twl_printf(" in %s", joined_wordlist);
		free(joined_wordlist);
	}
	else
		twl_putstr(" in \"$@\"");
	twl_printf(";\n%*c%s", depth * 4, ' ', "do");
	if (this->do_group)
	{
		ast_compound_list_print_function_seplast(this->do_group, depth + 1);
	}
	twl_printf("\n%*c%s", depth * 4, ' ', "done");
}
