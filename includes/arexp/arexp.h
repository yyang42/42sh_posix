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

# define AREXP_MAX_DEPTH 2000

typedef struct			s_arexp
{
	size_t				depth;
	t_lst				*tokens;
	t_arexp_expression	*expression;
	char				*error_msg;
	bool				empty;
}						t_arexp;

t_arexp					*arexp_new(char *expr);
void					arexp_del(t_arexp *this);

t_arexp					*arexp_singleton(t_arexp *cpy, bool clear);

bool					arexp_has_error(t_arexp *this);

void					arexp_set_error_msg(t_arexp *this, char *msg,
																t_token *token);

void					arexp_print_rec(t_arexp *this);

long long				arexp_eval(t_arexp *this);

long long				arexp_atoll_from_string(t_arexp *this, char *input);
long long				arexp_atoll(t_arexp *this, t_token *token);
long long				arexp_atoll_base(t_arexp *this, char *input, int base,
																t_token *token);

#endif
