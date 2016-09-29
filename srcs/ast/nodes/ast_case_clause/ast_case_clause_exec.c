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
#include "pattern_matching/substr.h"
#include "expan/expansion.h"
#include "token/token.h"

/*
** In order from the beginning to the end of the case statement,
** each pattern that labels a compound-list shall be subjected to
**  - tilde expansion,
**  - parameter expansion,
**  - command substitution,
**  - and arithmetic expansion,
** and the result of these expansions shall be compared against
** the expansion of word, according to the rules described in
** Pattern Matching Notation (which also describes the effect of
** quoting parts of the pattern).
*/

static bool			match_found(char *needle_text, char *pattern_text)
{
	bool			matched;
	t_substr		*tmp;
	char			*actual;

	tmp = substr_new();
	actual = substr_sharpsharp(tmp, needle_text, pattern_text);
	matched = (twl_strlen(actual) == 0);
	free(actual);
	substr_del(tmp);
	return (matched);
}

static t_token		*expand_pattern(t_token *pattern)
{
	t_expansion	*expansion;
	char		*text;
	t_token		*ret;

	expansion = expansion_new_from_token(pattern);
	text = expansion_get_string_pattern_case(expansion);
	if (expansion->error)
	{
		twl_dprintf(2, "%s\n", expansion->error);
		expansion_del(expansion);
		shenv_singleton()->shenv_shall_quit_curr_ast = true;
		shenv_singleton()->last_exit_code = 1;
		return (NULL);
	}
	ret = token_copy(pattern);
	token_set_text(ret, text);
	free(text);
	expansion_del(expansion);
	return (ret);
}

static bool			find_needle_in_pattern_fn(void *pattern, void *needle_)
{
	t_token			*needle;
	t_token			*pattern_expanded;
	bool			ret;

	if (shenv_singleton()->last_exit_code != 0)
		return (false);
	needle = needle_;
	pattern_expanded = expand_pattern(pattern);
	if (shenv_singleton()->shenv_shall_quit_curr_ast)
		return (false);
	ret = match_found(needle->text, pattern_expanded->text);
	token_del(pattern_expanded);
	return (ret);
}

static bool			is_matching_pattern(t_lst *pattern_tokens, t_token *needle)
{
	return ((bool)twl_lst_find(pattern_tokens,
								find_needle_in_pattern_fn,
								needle));
}

void				ast_case_clause_exec(t_ast_case_clause *this)
{
	t_ast_case_item *case_item;
	t_lst			*case_items_iterator;

	ast_case_clause_expan_needle(this);
	if (shenv_singleton()->shenv_shall_quit_curr_ast)
		return ;
	case_items_iterator = twl_lst_copy(this->case_list, NULL);
	shenv_singleton()->last_exit_code = EXIT_SUCCESS;
	while ((case_item = twl_lst_pop_front(case_items_iterator)))
	{
		if (is_matching_pattern(case_item->pattern_tokens,
								this->needle_expanded))
		{
			ast_compound_list_exec(case_item->compound_list);
			break ;
		}
	}
	twl_lst_del(case_items_iterator, NULL);
	token_del(this->needle_expanded);
	this->needle_expanded = NULL;
}
