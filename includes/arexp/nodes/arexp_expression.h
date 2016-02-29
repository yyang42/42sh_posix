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

#ifndef AREXP_EXPRESSION_H
# define AREXP_EXPRESSION_H

# include "basics.h"
# include "arexp/nodes/arexp_assignment.h"
# include "arexp/arexp_defines.h"

typedef struct		s_arexp_expression
{
	t_lst			*assignment;
}					t_arexp_expression;

t_arexp_expression	*arexp_expression_new(void);
void				arexp_expression_del(t_arexp_expression *expression);

t_arexp_expression	*arexp_expression_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp);

void					arexp_expression_print_rec(t_arexp_expression *this,
																	int depth);

long long				arexp_expression_eval(t_arexp_expression *this);

#endif
