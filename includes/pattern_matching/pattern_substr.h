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

typedef struct		s_pattern_substr
{
	t_lst			*split;
	char			*pattern;
}					t_pattern_substr;

t_pattern_substr	*pattern_substr_new(char *pattern);
void				pattern_substr_del(t_pattern_substr *this);

#endif
