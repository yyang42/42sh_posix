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

#include "edit/simple_char.h"

t_simple_char			*simple_char_new(unsigned char simple,
							void (*fn)(t_edit *))
{
	t_simple_char		*this;

	this = twl_malloc_x0(sizeof(t_simple_char));
	this->simple = simple;
	this->apply_fn = fn;
	return (this);
}
