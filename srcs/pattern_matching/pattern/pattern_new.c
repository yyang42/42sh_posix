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

#include "twl_xstdlib.h"

#include "pattern_matching/pattern.h"

t_pattern			*pattern_new(char *pattern)
{
	t_pattern		*this;

	this = twl_malloc_x0(sizeof(t_pattern));
	this->pattern = twl_strdup(pattern);
	this->split = twl_lst_new();
	this->depth = -1;
	this->index = 0;
	this->to_push_ = NULL;
	this->itp_ = 0;
	pattern_build_(this);
	return (this);
}
