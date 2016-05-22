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

#include "edit/escaped_sequence.h"

t_escaped_sequence		*escaped_sequence_new(char *sequence,
												void (*fn)(t_edit *))
{
	t_escaped_sequence	*this;

	this = twl_malloc_x0(sizeof(t_escaped_sequence));
	this->sequence = sequence;
	this->apply_fn = fn;
	return (this);
}
