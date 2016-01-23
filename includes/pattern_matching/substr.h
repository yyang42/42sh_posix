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

#ifndef SUBSTR_H
# define SUBSTR_H

# include "basics.h"
# include "pattern_matching/bracket_expr.h"
# include "pattern_matching/pattern_substr.h"

typedef struct			s_substr
{
	t_pattern_substr	*patss;
	t_bracket_expr		*brack_expr;
	char				*str;
	char				*match;
	int					ind_m;
	int					ind_p;
}						t_substr;

t_substr				*substr_new(void);
void					substr_del(t_substr *this);

char					*substr_sharp(t_substr *this, char *str, char *pattern);
bool					substr_sharp_supervisor(t_substr *this);

char					*substr_sharpsharp(t_substr *this, char *str,
																char *pattern);
bool					substr_sharpsharp_supervisor(t_substr *this);

char					*substr_percent(t_substr *this, char *str,
																char *pattern);
char					*substr_percentpercent(t_substr *this, char *str,
																char *pattern);

#endif
