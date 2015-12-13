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

char				*params_exclamation(void)
{
	t_environment	*env;
	char			*ret;

	env = environment_singleton();
	ret = twl_itoa(env->info.most_recent_background_command_pid);
	return (ret);
}

char				*test_params_exclamation(t_environment *env)
{
	char				*ret;

	ret = twl_itoa(env->info.most_recent_background_command_pid);
	return (ret);
}
