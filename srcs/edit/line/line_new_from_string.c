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
#include "utils.h"

t_line			*line_new_from_string(char *str)
{
	t_line		*this;
	size_t		len;
	size_t		tot;

	len = twl_strlen(str);
	tot = utils_upper_power_of_two(len);
	this = line_new();
	this->copy = twl_strdup(str);
	this->line = twl_strnew(tot);
	twl_strcpy(this->line, str);
	this->total = tot;
	this->size = len;
	return (this);
}
