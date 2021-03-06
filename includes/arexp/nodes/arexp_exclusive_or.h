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

#ifndef AREXP_EXCLUSIVE_OR_H
# define AREXP_EXCLUSIVE_OR_H

# include "basics.h"
# include "token/token.h"
# include "arexp/arexp_defines.h"
# include "arexp/nodes/arexp_and.h"

typedef struct			s_arexp_exclusive_or
{
	t_lst				*and;
}						t_arexp_exclusive_or;

t_arexp_exclusive_or	*arexp_exclusive_or_new(void);
void					arexp_exclusive_or_del(t_arexp_exclusive_or
																*exclusive_or);

t_arexp_exclusive_or	*arexp_exclusive_or_new_from_tokens(t_lst *tokens);

void					arexp_exclusive_or_print_rec(t_arexp_exclusive_or *this,
																	int depth);

long long				arexp_exclusive_or_eval(t_arexp_exclusive_or *this);

#endif
