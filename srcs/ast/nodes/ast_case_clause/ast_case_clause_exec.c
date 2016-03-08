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

#include "ast/nodes/ast_if_then.h"
#include "ast/nodes/ast_case_clause.h"

/*
	In order from the beginning to the end of the case statement,
	each pattern that labels a compound-list shall be subjected to
		- tilde expansion,
		- parameter expansion,
		- command substitution,
		- and arithmetic expansion,
	and the result of these expansions shall be compared against
	the expansion of word, according to the rules described in
	Pattern Matching Notation (which also describes the effect of
	quoting parts of the pattern).
*/

void				ast_case_clause_exec(t_ast_case_clause *this)
{
	twl_printf("case clause not implemented");
	(void)this;
	// while (true)
	// {
	// 	ast_compound_list_exec(this->cond_compound);
	// 	if (shenv_singleton()->last_exit_code == 0)
	// 		break ;
	// 	ast_compound_list_exec(this->do_group);
	// }
}
