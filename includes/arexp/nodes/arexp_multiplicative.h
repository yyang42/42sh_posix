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

#ifndef AREXP_MULTIPLICATIVE_H
# define AREXP_MULTIPLICATIVE_H

# include "basics.h"
# include "token/token.h"
# include "arexp/arexp_defines.h"
# include "arexp/nodes/arexp_unary.h"

typedef struct			s_arexp_multiplicative__
{
	t_arexp_unary		*unary;
	t_token				*multiplicative_sign;
}						t_arexp_multiplicative__;

typedef struct			s_arexp_multiplicative
{
	t_lst				*unary;
}						t_arexp_multiplicative;

t_arexp_multiplicative	*arexp_multiplicative_new(void);
void					arexp_multiplicative_del(t_arexp_multiplicative
														*arexp_multiplicative);

t_arexp_multiplicative	*arexp_multiplicative_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp);

void					arexp_multiplicative_print_rec(t_arexp_multiplicative
															*this, int depth);

long long				arexp_multiplicative_eval(t_arexp_multiplicative *this);

#endif
