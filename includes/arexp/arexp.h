/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.h                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AREXP_H
# define AREXP_H

# include "basics.h"
# include "token/token.h"
# include "arexp/nodes/arexp_expression.h"

typedef struct			s_arexp
{
	t_lst				*tokens;
	t_arexp_expression	*expression;
	char				*error_msg;
}						t_arexp;

t_arexp					*arexp_new(char *expr);
void					arexp_del(t_arexp *this);

bool					arexp_has_error(t_arexp *this);

void					arexp_set_error_msg(t_arexp *this, char *msg, t_token *token);

void					arexp_print_rec(t_arexp *this);

#endif
