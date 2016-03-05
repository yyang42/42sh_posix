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
#include "expan/expan_exec.h"


char				*params_exclamation(void)
{
	t_shenv	*env;
	char			*ret;

	env = shenv_singleton();
	ret = twl_itoa(env->info.most_recent_background_command_pid);
	return (ret);
}

char				*test_params_exclamation(t_shenv *env)
{
	char				*ret;

	ret = twl_itoa(env->info.most_recent_background_command_pid);
	return (ret);
}

bool				expan_exec_param_exclamation(t_expan_token *expan_token)
{
	expan_token->res = params_exclamation();
	return (true);
}
