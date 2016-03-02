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

#ifndef AREXP_SHIFT_H
# define AREXP_SHIFT_H

# include "basics.h"
# include "token/token.h"
# include "arexp/arexp_defines.h"
# include "arexp/nodes/arexp_additive.h"

typedef struct			s_arexp_shift__
{
	t_arexp_additive	*additive;
	t_token				*shift_sign;
}						t_arexp_shift__;

typedef struct			s_arexp_shift
{
	t_lst				*additive;
}						t_arexp_shift;

t_arexp_shift			*arexp_shift_new(void);
void					arexp_shift_del(t_arexp_shift *arexp_shift);

t_arexp_shift			*arexp_shift_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp);

void					arexp_shift_print_rec(t_arexp_shift *this, int depth);

long long				arexp_shift_eval(t_arexp_shift *this);

#endif
