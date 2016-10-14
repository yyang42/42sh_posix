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

#include "edit/history.h"

void				history_push_multiline(t_history *this, char *commands)
{
	char			**array;
	char			**start;

	array = twl_strsplit(commands, '\n');
	start = array;
	while (*array)
	{
		history_push(this, line_new_from_string(*array));
		free(*array);
		array += 1;
	}
	free(start);
}
