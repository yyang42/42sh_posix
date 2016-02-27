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

typedef struct			s_arexp_exclusive_or
{
	t_lst				*arexp_and;
}						t_arexp_exclusive_or;

t_arexp_exclusive_or	*arexp_exclusive_or_new(void);
void					arexp_exclusive_or_del(t_arexp_exclusive_or *arexp_exclusive_or);

t_arexp_exclusive_or	*arexp_exclusive_or_new_from_tokens(t_lst *tokens, struct s_arexp *arexp);

#endif
