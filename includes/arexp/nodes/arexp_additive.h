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

#ifndef AREXP_additive_H
# define AREXP_additive_H

# include "basics.h"
# include "token/token.h"
# include "arexp/arexp_defines.h"
# include "arexp/nodes/arexp_multiplicative.h"

typedef struct				s_arexp_additive__
{
	t_arexp_multiplicative	*multiplicative;
	t_token					*additive_sign;
}							t_arexp_additive__;

typedef struct				s_arexp_additive
{
	t_lst					*multiplicative;
}							t_arexp_additive;

t_arexp_additive			*arexp_additive_new(void);
void						arexp_additive_del(t_arexp_additive
															*arexp_additive);

t_arexp_additive			*arexp_additive_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp);

#endif
