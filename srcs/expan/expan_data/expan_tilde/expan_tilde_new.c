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

#include "expan/expan_tilde.h"

t_expan_tilde *expan_tilde_new(void)
{
	t_expan_tilde *expan_tilde;

	expan_tilde = twl_malloc_x0(sizeof(t_expan_tilde));
	expan_tilde->token = NULL;
	expan_tilde->suffix = NULL;
	return (expan_tilde);
}
