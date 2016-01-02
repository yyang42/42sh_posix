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

#include "openclose/openclose_matcher.h"

t_openclose_matcher			*openclose_matcher_new(void)
{
	t_openclose_matcher		*this;

	this = twl_malloc_x0(sizeof(t_openclose_matcher));
	this->oc_pairs = twl_lst_new();
	this->skip_quoted = false;
	return (this);
}
