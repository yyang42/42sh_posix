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
#include "ast/nodes/ast_case_item.h"
#include "expan/expan_mgr.h"
#include "expan/expan_exec.h"

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

static bool			is_matching_pattern(t_token *pattern, t_token *needle)
{
	/* TODO: REPLACE DUMMY IMPLEMENTATION */
	// *should_exec = expan_init(&token->text, token->text_unexpanded, TOKEN_ORIGIN_WORD);
	twl_printf("pattern->text %s\n", pattern->text);
	twl_printf("needle->text %s\n", needle->text);
	expan_init(&pattern->text, pattern->text_unexpanded, TOKEN_ORIGIN_WORD); // HUM
	expan_init(&needle->text, needle->text_unexpanded, TOKEN_ORIGIN_WORD); // HUM
	twl_printf("pattern->text %s\n", pattern->text);
	twl_printf("needle->text %s\n\n", needle->text);
	return (twl_strequ(pattern->text, needle->text));
}

void				ast_case_clause_exec(t_ast_case_clause *this)
{
	t_ast_case_item *case_item;
	t_lst			*case_items_iterator;

	case_items_iterator = twl_lst_copy(this->case_list, NULL);
	shenv_singleton()->last_exit_code = 0;
	while ((case_item = twl_lst_pop_front(case_items_iterator)))
	{
		if (is_matching_pattern(case_item->pattern_token, this->needle_token))
		{
			ast_compound_list_exec(case_item->compound_list);
			break ;
		}
	}
	twl_lst_del(case_items_iterator, NULL);
}
