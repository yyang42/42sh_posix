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

#ifndef AREXP_EQUALITY_H
# define AREXP_EQUALITY_H

# include "basics.h"
# include "token/token.h"
# include "arexp/arexp_defines.h"
# include "arexp/nodes/arexp_relational.h"

typedef struct			s_arexp_equality__
{
	t_arexp_relational	*relational;
	t_token				*equality_sign;
}						t_arexp_equality__;

typedef struct			s_arexp_equality
{
	t_lst				*relational;
}						t_arexp_equality;

t_arexp_equality		*arexp_equality_new(void);
void					arexp_equality_del(
		t_arexp_equality *arexp_equality);

t_arexp_equality		*arexp_equality_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp);

#endif
