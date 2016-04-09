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

#include "ast/nodes/ast_case_clause.h"
#include "expan/expansion.h"
#include "shenv/shenv.h"

void			ast_case_clause_expan_needle(t_ast_case_clause *this)
{
	t_expansion	*expansion;
	char		*text;

	expansion = expansion_new_from_token(this->needle_token);
	text = expansion_get_string_needle_case(expansion);
	if (expansion->error)
	{
		twl_dprintf(2, "%s\n", expansion->error);
		expansion_del(expansion);
		shenv_singleton()->shenv_shall_quit_curr_ast = true;
		shenv_singleton()->last_exit_code = 1;
		return ;
	}
	this->needle_expanded = token_copy(this->needle_token);
	token_set_text(this->needle_expanded, text);
	free(text);
	expansion_del(expansion);
}
