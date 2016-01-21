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

#ifndef PATTERN_SUBSTR_H
# define PATTERN_SUBSTR_H

# include "basics.h"
#include <stdio.h>

typedef struct				s_patss_bracket
{
	char					*brack;
	int						ind_p;
	int						ind_b;
	char					flag[4];
}							t_patss_bracket;

typedef struct				s_pattern_substr_data
{
	char					*piece;
	bool					fixed;
}							t_pattern_substr_data;

typedef struct				s_pattern_substr
{
	t_lst					*split;
	char					*pattern;
	int						len;
	int						ind_p;
	t_pattern_substr_data	*to_push;
	int						ind_tp;
}							t_pattern_substr;

t_pattern_substr			*pattern_substr_new(char *pattern);
void						pattern_substr_del(t_pattern_substr *this);

void						pattern_substr_build_(t_pattern_substr *this);
void						pattern_substr_build_data_(t_pattern_substr *this);
void						pattern_substr_build_push_(t_pattern_substr *this);
void						pattern_substr_build_double_quote_(t_pattern_substr
																		*this);
void						pattern_substr_build_simple_quote_(t_pattern_substr
																		*this);
void						pattern_substr_build_escaped_(t_pattern_substr
																		*this);
void						pattern_substr_build_special_(t_pattern_substr
																		*this);
void						pattern_substr_build_normal_char_(t_pattern_substr
																		*this);
void						pattern_substr_build_bracket_(t_pattern_substr
																		*this);
t_pattern_substr_data		*pattern_substr_get_data(t_pattern_substr *this,
																		int no);

#endif
