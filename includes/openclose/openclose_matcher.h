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

# define OC_MATCHER_FLAG_SKIP_QUOTED (1 << 0)
# define OC_MATCHER_JUMP_SINGLE_QUOTE (1 << 1)

typedef struct		s_openclose_matcher
{
	t_lst			*oc_pairs;
	char			*err_msg;
	int				flags;
}					t_openclose_matcher;

t_openclose_matcher	*openclose_matcher_new(int flags);
void				openclose_matcher_del(t_openclose_matcher *this);

void				openclose_matcher_add(t_openclose_matcher *matcher,
												char *open, char *close);

char				*openclose_matcher_find_matching(t_openclose_matcher *this,
																char *s);
void				openclose_matcher_print(t_openclose_matcher *matcher);
void				openclose_matcher_debug_print(t_openclose_matcher *matcher);

char				*openclose_matcher_token_find_matching_opened(
								t_openclose_matcher *matcher, t_lst *tokens);
int					openclose_matcher_token_find_matching(
								t_openclose_matcher *matcher, t_lst *tokens);
bool				openclose_matcher_is_open(
								t_openclose_matcher *matcher, char *str);
char				*openclose_matcher_find_matching_base(
						t_openclose_matcher *matcher, char *s, t_lst *stack);

t_lst				*openclose_matcher_find_matching_stack(
										t_openclose_matcher *matcher, char *s);

t_openclose_matcher *openclose_matcher_singleton_parser(void);
t_openclose_matcher *openclose_matcher_arexp_singleton_parser(void);

#endif
