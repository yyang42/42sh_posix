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

t_shvar				*shvar_new(char *key, char *value, bool shvar_exported)
{
	t_shvar	*this;

	if (key == NULL || *key == '\0')
	{
		errno = EINVAL;
		return (NULL);
	}
	this = twl_malloc_x0(sizeof(t_shvar));
	this->shvar_key = twl_strdup(key);
	this->shvar_value = NULL;
	if (value)
		shvar_set_value(this, value);
	this->shvar_assign_value = NULL;
	this->shvar_exported = shvar_exported;
	this->shvar_read_only = false;
	return (this);
}
