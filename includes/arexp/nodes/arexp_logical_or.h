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

#ifndef AREXP_LOGICAL_OR_H
# define AREXP_LOGICAL_OR_H

# include "basics.h"
# include "twl_lst.h"
# include "arexp/arexp_defines.h"
# include "arexp/nodes/arexp_logical_and.h"

typedef struct			s_arexp_logical_or
{
	t_lst				*logical_and;
}						t_arexp_logical_or;

t_arexp_logical_or		*arexp_logical_or_new(void);
void					arexp_logical_or_del(t_arexp_logical_or *logical_or);

t_arexp_logical_or		*arexp_logical_or_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp);

void					arexp_logical_or_print_rec(t_arexp_logical_or *this,
																	int depth);

long long				arexp_logical_or_eval(t_arexp_logical_or *this);

#endif
