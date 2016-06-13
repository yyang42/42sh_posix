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

#include "expan/expansion.h"
#include <time.h>

void			expansion_prompt_date_hhmmss12(t_expansion *this)
{
	time_t		timer;
	struct tm	*tm_info;
	char		time_buffer[16];

	time(&timer);
	tm_info = localtime(&timer);
	strftime(time_buffer, 16, "%I:%M:%S", tm_info);
	expansion_push_before_split(this, time_buffer, false);
}
