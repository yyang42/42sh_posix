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

#include "edit/line.h"

t_line			*line_copy(t_line *this)
{
	t_line		*copy;

	copy = twl_malloc_x0(sizeof(t_line));
	copy->copy = twl_strdup(this->line);
	copy->line = twl_strnew(this->total);
	twl_strcat(copy->line, this->line);
	copy->size = this->size;
	copy->total = this->total;
	return (copy);
}
