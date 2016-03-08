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

#include <errno.h>
#include "shenv/shvar.h"

t_shvar				*shvar_copy(t_shvar	*src)
{
	t_shvar			*copy;

	copy = shvar_new(src->shvar_key,
		src->shvar_value,
		src->shvar_exported);
	copy->shvar_read_only = src->shvar_read_only;
	if (src->shvar_assign_value)
		copy->shvar_assign_value = twl_strdup(src->shvar_assign_value);
	return (copy);
}
