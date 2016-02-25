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

#include "token/token_mgr.h"
#include "data.h"
#include "arexp/nodes/arexp_assignment.h"

t_arexp_assignment		*arexp_assignment_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp)
{
	t_arexp_assignment	*arexp_assignment;
	t_token				**assign;

	arexp_assignment = arexp_assignment_new();
	while (42)
	{
		if (!token_mgr_arexp_is_assign(tokens))
			break ;
		assign = twl_malloc_x0(sizeof(t_token *) * 2);
		assign[0] = twl_lst_pop(tokens);
		assign[1] = twl_lst_pop(tokens);
		twl_lst_push_front(arexp_assignment->lst_assign, assign);
	}
	// TODO: condition toussa
	return (arexp_assignment);
	(void)arexp;
}
