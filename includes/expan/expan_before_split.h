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

#ifndef EXPAN_BEFORE_SPLIT_H
# define EXPAN_BEFORE_SPLIT_H

# include "basics.h"

typedef struct			s_expan_before_split
{
	char				*text;
	bool				split;
}						t_expan_before_split;

extern bool				g_before_split_dquoted;

t_expan_before_split	*expan_before_split_new(char *text, bool split);
void					expan_before_split_del(t_expan_before_split *this);

char					*expan_before_split_unquote(t_expan_before_split *this);

#endif
