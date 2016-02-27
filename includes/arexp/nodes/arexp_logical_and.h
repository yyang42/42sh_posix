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

#ifndef AREXP_LOGICAL_AND_H
# define AREXP_LOGICAL_AND_H

# include "basics.h"
# include "token/token.h"
# include "arexp/arexp_defines.h"

typedef struct			s_arexp_logical_and
{
	t_lst				*arexp_inclusive_or;
}						t_arexp_logical_and;

t_arexp_logical_and		*arexp_logical_and_new(void);
void					arexp_logical_and_del(t_arexp_logical_and *arexp_logical_and);

t_arexp_logical_and		*arepx_logical_and_new_from_tokens(t_lst *tokens, struct s_arexp *arexp);

#endif
