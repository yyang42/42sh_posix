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

char			*line_get(t_line *this)
{
	char		buffer[16];

	twl_memset(buffer, 0, sizeof(buffer));
	while (read(0, buffer, sizeof(buffer) - 1) != -1)
	{
		LOG_DEBUG(">%s<", buffer);
		twl_memset(buffer, 0, sizeof(buffer));
	}
	return (NULL);
	(void)this;
}
