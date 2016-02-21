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

	arexp_assignment = arexp_assignment_new();
	return (arexp_assignment);
	(void)tokens;
	(void)arexp;
}
