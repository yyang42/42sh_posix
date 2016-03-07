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


char				*params_question(void)
{
	t_shenv	*env;
	char			*ret;

	env = shenv_singleton();
	ret = twl_itoa(env->last_exit_code);
	return (ret);
}

char				*test_params_question(t_shenv *env)
{
	char				*ret;

	ret = twl_itoa(env->last_exit_code);
	return (ret);
}


bool				expan_exec_param_question(t_expan_token *expan_token)
{
	expan_token->res = params_question();
	return (true);
}
