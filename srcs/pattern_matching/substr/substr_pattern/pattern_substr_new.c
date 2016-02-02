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

#include "pattern_matching/pattern_substr.h"

t_pattern_substr		*pattern_substr_new(char *pattern)
{
	t_pattern_substr	*this;

	this = twl_malloc_x0(sizeof(t_pattern_substr));
	this->pattern = twl_strdup(pattern);
	this->len = twl_strlen(this->pattern);
	this->ind_p = 0;
	this->to_push = NULL;
	this->split = twl_lst_new();
	pattern_substr_build_(this);
	return (this);
}
