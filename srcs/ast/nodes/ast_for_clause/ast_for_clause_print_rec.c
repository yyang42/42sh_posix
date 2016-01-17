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

void				ast_for_clause_print_rec(t_ast_for_clause *this,
	int depth)
{
	ast_print_indent(depth);
	twl_printf("ast_for_clause (name=%s", this->name);

	if (twl_lst_len(this->wordlist))
	{
		char *joined_wordlist = token_mgr_strjoin(this->wordlist, " ");
		twl_printf(", wordlist=`%s`", joined_wordlist);
	}
	twl_printf(")\n");
	depth++;
	if (this->do_group)
	{
		ast_print_indent(depth);
		twl_printf("do_group\n");
		ast_compound_list_print_rec(this->do_group, depth + 1);
	}
}
