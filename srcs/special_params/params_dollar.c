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

#include "basics.h"
#include "prog.h"
#include "environment.h"
#include "twl_lst.h"

char				*params_dollar()
{
	t_environment	*env;

	env = environment_singleton();
	return (environment_concat_flags(env));
}

char				*test_params_dollar(t_environment *env)
{
	return (environment_concat_flags(env));
}
