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

static void			iter_wordlist_fn(void *word_token_, void *this_)
{
	t_ast_for_clause	*this;
	t_token				*word_token;

	this = this_;
	word_token = word_token_;
	shenv_shvars_set(shenv_singleton(), this->name, word_token->text, NULL);
	ast_compound_list_exec(this->do_group);
}

void				ast_for_clause_exec(t_ast_for_clause *this)
{
	twl_lst_iter(this->wordlist, iter_wordlist_fn, this);
}
