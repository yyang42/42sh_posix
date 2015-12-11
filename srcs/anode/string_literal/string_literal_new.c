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

#include "anode/string_literal.h"

t_string_literal			*string_literal_new(char *text)
{
	t_string_literal		*this;

	this = twl_malloc_x0(sizeof(t_string_literal));
	this->type = ANODE_STRING_LITERAL;
	this->text = twl_strdup(text);
	return (this);
}
