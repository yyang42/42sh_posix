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

#ifndef AREXP_ASSIGNMENT_H
# define AREXP_ASSIGNMENT_H

# include "basics.h"
# include "twl_lst.h"
# include "arexp/arexp_defines.h"
# include "arexp/nodes/arexp_condition.h"

typedef struct			s_arexp_assignment
{
	t_lst				*assign;
	t_arexp_condition	*condition;
}						t_arexp_assignment;

t_arexp_assignment		*arexp_assignment_new(void);
void					arexp_assignment_del(t_arexp_assignment *assignment);

t_arexp_assignment		*arexp_assignment_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp);

void					arexp_assignment_print_rec(t_arexp_assignment *this, int depth);

#endif
