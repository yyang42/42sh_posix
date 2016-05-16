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

#include "ast/ast.h"

void				ast_del(t_ast *this)
{
	if (this->tokens_ref_tracker)
		token_mgr_del(this->tokens_ref_tracker);
	if (this->compound_list)
		ast_compound_list_del(this->compound_list);
	if (this->error_msg)
		free(this->error_msg);
	twl_lst_del(this->ast_open_stack, free);
	free(this);
}
