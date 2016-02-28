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

#ifndef AREXP_AND_H
# define AREXP_AND_H

# include "basics.h"
# include "token/token.h"
# include "arexp/arexp_defines.h"
# include "arexp/nodes/arexp_equality.h"

typedef struct	s_arexp_and
{
	t_lst		*equality;
}				t_arexp_and;

t_arexp_and		*arexp_and_new(void);
void			arexp_and_del(t_arexp_and *and);

t_arexp_and		*arexp_and_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp);

void						arexp_and_print_rec(t_arexp_and *this, int depth);

#endif
