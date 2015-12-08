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

t_environment_var *environment_var_new(char *str, t_environment_var_type type)
{

	char				**split;
	t_environment_var	*this;

	this = twl_malloc_x0(sizeof(t_environment_var));
	split = twl_strsplit(str, '=');
	this->key = split[0];
	if (split[1] == NULL)
		this->value = twl_strdup("");
	else
		this->value = split[1];
	this->read_only = 0;
	this->type = type;
	return (this);
}
