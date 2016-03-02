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

#ifndef AREXP_RELATIONAL_H
# define AREXP_RELATIONAL_H

# include "basics.h"
# include "token/token.h"
# include "arexp/arexp_defines.h"
# include "arexp/nodes/arexp_shift.h"

typedef struct		s_arexp_relational__
{
	t_arexp_shift	*shift;
	t_token			*relational_sign;
}					t_arexp_relational__;

typedef struct		s_arexp_relational
{
	t_lst			*shift;
}					t_arexp_relational;

t_arexp_relational	*arexp_relational_new(void);
void				arexp_relational_del(t_arexp_relational *relational);

t_arexp_relational	*arexp_relational_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp);

void				arexp_relational_print_rec(t_arexp_relational *this,
																	int depth);

long long			arexp_relational_eval(t_arexp_relational *this);

#endif
