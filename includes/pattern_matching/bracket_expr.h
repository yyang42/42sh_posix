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

#ifndef BRACKET_EXPR_H
# define BRACKET_EXPR_H

# include "basics.h"
# include "twl_dict.h"
# include "twl_ctype.h"

typedef struct		s_brackexpr_find_
{
	char			*expr;
	char			ret[128];
	int				ind_e;
	int				ind_r;
	bool			rev;
}					t_brackexpr_find_;

typedef struct		s_bracket_expr
{
	t_dict			*dict;
}					t_bracket_expr;

t_bracket_expr		*bracket_expr_new(void);
void				bracket_expr_del(t_bracket_expr *this);

t_bracket_expr		*bracket_expr_singleton(void);

void				bracket_expr_add(t_bracket_expr *this, char *key,
																	char *val);
char				*bracket_expr_get(t_bracket_expr *this, char *key);

void				bracket_expr_find_(t_bracket_expr *this, char *expr);
void				bracket_expr_find_hyphen_(t_bracket_expr *this,
														t_brackexpr_find_ *bef);
void				bracket_expr_find_bracket_(t_bracket_expr *this,
														t_brackexpr_find_ *bef);


#endif
