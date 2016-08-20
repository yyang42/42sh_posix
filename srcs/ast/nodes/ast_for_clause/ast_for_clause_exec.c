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
#include "ast/nodes/ast_for_clause.h"
#include "expan/expansion.h"
#include "pattern_matching/brace/brace.h"

static void			iter_wordlist_fn(void *word_token, void *this_)
{
	t_ast_for_clause	*this;

	this = this_;
	if (!shenv_should_continue_exec(shenv_singleton()))
		return ;
	ast_for_clause_exec_handle_xtrace(this);
	shenv_shvars_set(shenv_singleton(), this->name, word_token, NULL);
	ast_compound_list_exec(this->do_group);
	shenv_continue_counter_decr_if_one(shenv_singleton());
}

static void			iter_expan_fn(void *data, void *expanded)
{
	t_expansion		*expansion;
	t_lst			*link;

	expansion = expansion_new_from_token(data);
	link = expansion_get_fields_for_clause(expansion);
	twl_lst_extend(expanded, link);
	twl_lst_del(link, NULL);
	expansion_del(expansion);
}

static t_lst		*expan_wordlist(t_lst *wordlist)
{
	t_lst			*expanded;
	t_lst			*brace;

	expanded = twl_lst_new();
	brace = brace_expand_tokens(wordlist);
	twl_lst_iter(brace, iter_expan_fn, expanded);
	token_mgr_del(brace);
	return (expanded);
}

void				ast_for_clause_exec(t_ast_for_clause *this)
{
	t_lst			*wordlist;
	void			(*del)(void *);

	shenv_loop_level_incr(shenv_singleton());
	if (twl_lst_len(this->wordlist))
	{
		wordlist = expan_wordlist(this->wordlist);
		del = free;
	}
	else
	{
		wordlist = twl_lst_copy(shenv_singleton()->shenv_pos_params, NULL);
		del = NULL;
	}
	twl_lst_iter(wordlist, iter_wordlist_fn, this);
	twl_lst_del(wordlist, del);
	shenv_loop_level_decr(shenv_singleton());
	shenv_break_counter_decr(shenv_singleton());
	shenv_continue_counter_decr(shenv_singleton());
}
