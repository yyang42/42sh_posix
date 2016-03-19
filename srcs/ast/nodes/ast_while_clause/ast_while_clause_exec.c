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
#include "ast/nodes/ast_while_clause.h"

void				ast_while_clause_exec(t_ast_while_clause *this)
{
	int				saved_exit_code;

	saved_exit_code = 0;
	while (true)
	{
		ast_compound_list_exec(this->cond_compound);
		if (shenv_singleton()->last_exit_code != 0)
			break ;
		ast_compound_list_exec(this->do_group);
		saved_exit_code = shenv_singleton()->last_exit_code;
	}
	shenv_singleton()->last_exit_code = saved_exit_code;
}
