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

#ifndef AREXP_CONDITION_H
# define AREXP_CONDITION_H

# include "basics.h"
# include "token/token.h"
# include "arexp/arexp_defines.h"
# include "arexp/nodes/arexp_logical_or.h"

typedef struct					s_arexp_condition
{
	t_arexp_logical_or			*logical_or;
	struct s_arexp_expression	*expression_if;
	struct s_arexp_condition	*condition_else;
}								t_arexp_condition;

t_arexp_condition				*arexp_condition_new(void);
void							arexp_condition_del(t_arexp_condition
																	*condition);

t_arexp_condition				*arexp_condition_new_from_tokens(t_lst *tokens);

void							arexp_condition_print_rec(t_arexp_condition
															*this, int depth);

long long						arexp_condition_eval(t_arexp_condition *this);

#endif
