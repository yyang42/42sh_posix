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

#include "token/token.h"

t_token				*token_new(char *text, int line, int col)
{
	t_token		*this;

	this = twl_malloc_x0(sizeof(t_token));
	this->type = token_type_from_str(text);
	this->text = twl_strdup(text);
	this->line = line;
	this->col = col;
	return (this);
}
