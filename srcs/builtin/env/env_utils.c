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

#include "builtin/env.h"
#include "twl_stdio.h"
#include <stdio.h>

void			add_env_var(void *data_, void *context_)
{
	t_environment	*context;
	char			*data;

	data = data_;
	context = context_;
	if (twl_strchr(data, '='))
		environment_setenv(context, data);
}
