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

#include <stdlib.h>

#include "environment.h"
#include <stdio.h>

extern char			**environ;

static t_environment_var *environment_var_new(char *str)
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
	this->type = ENVIRONMENT;
	return (this);
}

void				environment_getenv(t_environment *this)
{
	int	i;

	i = 0;
	while (environ[i] != NULL)
	{
		(void)this;
		twl_lst_push(this->env_vars, environment_var_new(environ[i]));
		i++;
	}
}
