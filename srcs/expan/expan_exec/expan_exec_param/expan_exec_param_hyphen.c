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


char				*params_hyphen(void)
{
	t_shenv	*env;

	env = environment_singleton();
	return (twl_itoa(env->info.cur_shell_pid));
}

char				*test_params_hyphen(t_shenv *env)
{
	return (twl_itoa(env->info.cur_shell_pid));
}


bool				expan_exec_param_hyphen(t_expan_token *expan_token)
{
	expan_token->res = params_hyphen();
	return (true);
}
