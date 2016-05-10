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

#include "shenv/shflag.h"

void				shflag_set_state_by_sign(t_shflag *shflag, char sign)
{
	if (sign == '+')
		shflag->shf_enabled = false;
	else if (sign == '-')
		shflag->shf_enabled = true;
	else
		LOG_ERROR("invalid sign: %c", sign);
}
