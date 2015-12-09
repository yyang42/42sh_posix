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

#ifndef PATMATCH_H
# define PATMATCH_H

# include "basics.h"
# include "twl_dict.h"
# include "twl_ctype.h"

typedef struct		s_class_expr
{
	char			*match;
	size_t			size;
}					t_class_expr;

typedef struct		s_pattern_str
{
	bool			fixed;
	char			*string;
}					t_pattern_str;

typedef struct		s_patmatch
{
	char			*pattern;
	t_dict			*class_expr;
	t_lst			*pattern_str;
}					t_patmatch;

t_patmatch			*patmatch_new(void);
void				patmatch_del(t_patmatch *this);

void				patmatch_build_class_expr_(t_patmatch *this);
void				patmatch_del_class_expr_(t_patmatch *this);

void				patmatch_build_pattern_str_(t_patmatch *this,
																char *pattern);
void				patmatch_del_pattern_str_(t_patmatch *this);

char				*patmatch_match(t_patmatch *this, char *pattern);

#endif
