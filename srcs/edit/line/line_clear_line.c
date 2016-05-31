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

void			line_clear_line(t_line *this)
{
	LOG_DEBUG("Coucou0");
	twl_strncpy(this->line, this->copy, this->total);
	LOG_DEBUG("Coucou1");
	this->size = twl_strlen(this->line);
	LOG_DEBUG("Coucou2");
}
