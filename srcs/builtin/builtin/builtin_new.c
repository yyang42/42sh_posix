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

#include "builtin/builtin.h"

t_builtin			*builtin_new(char *name, t_builtin_fn *builtin_fn)
{
	t_builtin		*this;

	this = twl_malloc_x0(sizeof(t_builtin));
	this->builtin_name = twl_strdup(name);
	this->builtin_fn = builtin_fn;
	return (this);
}
