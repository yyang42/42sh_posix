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

#include "ast/nodes/ast_assignment.h"
#include "data.h"
#include "openclose/openclose_matcher.h"
#include "token/token_mgr.h"
#include "token/token_utils.h"
#include "utils.h"

char				*token_mgr_extract_assignment_join(t_lst *list_of_assign)
{
	t_lst					*copy;
	t_ast_assignment		*assign;
	t_lst					*master_segs;

	copy = twl_lst_copy(list_of_assign, NULL);
	master_segs = twl_lst_new();
	while ((assign = twl_lst_pop_front(copy)))
	{
		twl_lst_push_back(master_segs, twl_strdup(assign->token->text));
	}
	return (twl_lst_strjoin(master_segs, "_"));
}
