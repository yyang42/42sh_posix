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

#include "shenv/shenv.h"

char		**shenv_get_paths(t_shenv *this)
{
	char			*str;

	str = shenv_getenv_value(this, "PATH");
	if (str == NULL || *str == '\0')
	{
		errno = EINVAL;
		return (NULL);
	}
	return (twl_strsplit(str, ':'));
}
