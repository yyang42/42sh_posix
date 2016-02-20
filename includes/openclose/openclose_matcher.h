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

#ifndef OPENCLOSE_MATCHER_H
# define OPENCLOSE_MATCHER_H

# include "basics.h"

# include "openclose/openclose.h"

typedef struct		s_openclose_matcher
{
	t_lst			*oc_pairs;
	int				skip_quoted;
}					t_openclose_matcher;

t_openclose_matcher	*openclose_matcher_new(void);
void				openclose_matcher_del(t_openclose_matcher *this);

void				openclose_matcher_add(t_openclose_matcher *matcher,
												char *open, char *close);

char				*openclose_matcher_find_matching(t_openclose_matcher *this,
																char *s);
void				openclose_matcher_print(t_openclose_matcher *matcher);

void				openclose_matcher_set_skip_quoted(
							t_openclose_matcher *matcher, bool skip_quoted);

int					openclose_matcher_token_find_matching(
								t_openclose_matcher *matcher, t_lst *tokens);
bool				openclose_matcher_is_open(
								t_openclose_matcher *matcher, char *str);

t_openclose_matcher *openclose_matcher_singleton_parser(void);
t_openclose_matcher *openclose_matcher_arexp_singleton_parser(void);

#endif
