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

t_environment_var	*environment_var_new(char *key, char *value,
	t_environment_var_type type, bool value_is_set)
{
	t_environment_var	*this;

	if (key == NULL || *key == '\0')
	{
		errno = EINVAL;
		return (NULL);
	}
	value = value ? value : "";
	this = twl_malloc_x0(sizeof(t_environment_var));
	this->value = twl_strdup(value);
	this->key = twl_strdup(key);
	this->read_only = NOT_READ_ONLY;
	this->type = type;
	this->value_is_set = value_is_set;
	return (this);
}
