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

#ifndef AREXP_UNARY_H
# define AREXP_UNARY_H

# include "basics.h"
# include "token/token.h"
# include "arexp/arexp_defines.h"

typedef union					u_primary__
{
	long long					constant;
	t_token						*variable;
	struct s_arexp_expression	*arexp_expression;
}								t_primary__;

typedef enum					e_primary_enum__
{
	AREXP_PRIMARY_NOTHING,
	AREXP_PRIMARY_CONSTANT,
	AREXP_PRIMARY_VARIABLE,
	AREXP_PRIMARY_EXPRESSION
}								t_primary_enum__;

typedef struct					s_arexp_unary
{
	t_lst						*unary_operator;
	t_primary_enum__			primary_enum;
	t_primary__					primary;
}								t_arexp_unary;

t_arexp_unary					*arexp_unary_new(void);
void							arexp_unary_del(t_arexp_unary *arexp_unary);

t_arexp_unary					*arexp_unary_new_from_tokens(t_lst *tokens);

void							arexp_unary_print_rec(t_arexp_unary *this,
																	int depth);

long long						arexp_unary_eval(t_arexp_unary *this);

#endif
