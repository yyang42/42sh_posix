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

typedef struct			s_arexp_expression
{
	t_lst				*arexp_assignment;
}						t_arexp_expression;

t_arexp_expression		*arexp_expression_new(void);
void					arexp_expression_del(t_arexp_expression *arexp_expression);

t_arexp_expression		*arexp_expression_new_from_tokens(t_lst *tokens);

#endif
