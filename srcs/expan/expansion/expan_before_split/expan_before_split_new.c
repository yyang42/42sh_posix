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

#include "expan/expan_before_split.h"

t_expan_before_split		*expan_before_split_new(char *text, bool split)
{
	t_expan_before_split	*this;

	this = twl_malloc_x0(sizeof(t_expan_before_split));
	this->text = twl_strdup((text != NULL) ? text : "");
	this->split = split;
	return (this);
}
