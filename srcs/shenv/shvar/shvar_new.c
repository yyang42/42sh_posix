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

t_shvar				*shvar_new(char *key, char *value, t_shvar_type shvar_type, bool value_is_set)
{
	t_shvar	*this;

	if (key == NULL || *key == '\0')
	{
		errno = EINVAL;
		return (NULL);
	}
	value = value ? value : "";
	this = twl_malloc_x0(sizeof(t_shvar));
	this->shvar_value = twl_strdup(value);
	this->shvar_key = twl_strdup(key);
	this->shvar_read_only = NOT_READ_ONLY;
	this->shvar_type = shvar_type;
	this->shvar_value_is_set = value_is_set;
	return (this);
}
