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

#ifndef PATTERN_H
# define PATTERN_H

# include "basics.h"

typedef struct		s_pattern_data
{
	char			*split;
	bool			fixed;
}					t_pattern_data;

typedef struct		s_pattern_bracket_
{
	char			*save;
	int				index;
	int				flag;
}					t_pattern_bracket_;

typedef struct		s_pattern_harmonize_
{
	t_lst			*to_push;
	t_pattern_data	*data;
	int				index;
	int				start;
	int				flag;
}					t_pattern_harmonize_;

typedef struct		s_pattern
{
	t_lst			*split;
	t_lst			*harm_;
	char			*pattern;
	int				depth;
	size_t			index;
	t_pattern_data	*to_push_;
	size_t			itp_;
}					t_pattern;

t_pattern			*pattern_new(char *pattern);
void				pattern_del(t_pattern *this);

/*
** Private method to build the pattern
*/

void				pattern_build_(t_pattern *this);
void				pattern_build_data_(t_pattern *this);
void				pattern_build_push_(t_pattern *this);
void				pattern_build_escaped_(t_pattern *this);
void				pattern_build_special_(t_pattern *this);
void				pattern_build_bracket_(t_pattern *this);
void				pattern_build_simple_quote_(t_pattern *this);
void				pattern_build_double_quote_(t_pattern *this);
void				pattern_build_normal_char_(t_pattern *this);
void				pattern_build_finish_(t_pattern *this);
void				pattern_build_harmonize_(t_pattern *this);

/*
** Public method to simplify my life <3
*/

char				pattern_get_begin_file(t_pattern *this);
char				*pattern_to_string(t_pattern *this);
int					pattern_get_depth(t_pattern *this);
t_lst				*pattern_get_pattern(t_pattern *this, int depth);
int					pattern_is_directory(t_pattern *this, int depth);
bool				pattern_is_all_fixed(t_pattern *this);

#endif
