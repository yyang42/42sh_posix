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

#include "pattern_matching/patmatch.h"

t_patmatch		*patmatch_new(void)
{
	t_patmatch		*this;

	this = twl_malloc_x0(sizeof(t_patmatch));
	this->brack_expr = bracket_expr_singleton();
	this->pattern = NULL;
	this->match = NULL;
	return (this);
}
