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

#include "environment.h"

t_envvar	*envvar_new(char *key, char *value,
	t_envvar_type envvar_type, bool value_is_set)
{
	t_envvar	*this;

	if (key == NULL || *key == '\0')
	{
		errno = EINVAL;
		return (NULL);
	}
	value = value ? value : "";
	this = twl_malloc_x0(sizeof(t_envvar));
	this->envvar_value = twl_strdup(value);
	this->envvar_key = twl_strdup(key);
	this->envvar_read_only = NOT_READ_ONLY;
	this->envvar_type = envvar_type;
	this->envvar_value_is_set = value_is_set;
	return (this);
}
