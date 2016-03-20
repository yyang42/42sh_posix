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
//#include "expan/expan_mgr.h"
//#include "expan/expan_exec.h"
#include "pattern_matching/substr.h"

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

//static bool			match_found(char *needle_text, char *pattern_text)
//{
//	bool			matched;
//	t_substr		*tmp;
//	char			*actual;
//
//	tmp  = substr_new();
//	actual = substr_sharpsharp(tmp, needle_text, pattern_text);
//	matched = (twl_strlen(actual) == 0);
//	free(actual);
//	substr_del(tmp);
//	return (matched);
//}
//
//static bool			find_needle_in_pattern_fn(void *pattern_, void *needle_)
//{
//	t_token			*pattern;
//	t_token			*needle;
//
//	pattern = pattern_;
//	needle = needle_;
//	expan_init(pattern, &pattern->text, pattern->text_unexpanded, TOKEN_ORIGIN_WORD); // TODO why TOKEN_ORIGIN_WORD
//	expan_init(needle, &needle->text, needle->text_unexpanded, TOKEN_ORIGIN_WORD); // TODO why TOKEN_ORIGIN_WORD
//	return (match_found(needle->text, pattern->text));
//}
//
//static bool			is_matching_pattern(t_lst *pattern_tokens, t_token *needle)
//{
//	return ((bool)twl_lst_find(pattern_tokens, find_needle_in_pattern_fn, needle));
//}

void				ast_case_clause_exec(t_ast_case_clause *this)
{
//	t_ast_case_item *case_item;
	t_lst			*case_items_iterator;

	case_items_iterator = twl_lst_copy(this->case_list, NULL);
	shenv_singleton()->last_exit_code = 0;
//	while ((case_item = twl_lst_pop_front(case_items_iterator)))
//	{
//		if (is_matching_pattern(case_item->pattern_tokens, this->needle_token))
//		{
//			ast_compound_list_exec(case_item->compound_list);
//			break ;
//		}
//	}
	twl_lst_del(case_items_iterator, NULL);
}
