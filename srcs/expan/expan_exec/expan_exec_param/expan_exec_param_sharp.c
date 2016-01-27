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


char				*params_sharp(void)
{
	t_environment	*env;
	char			*ret;

	env = environment_singleton();
	ret = twl_itoa(twl_lst_len(env->pos_params));
	return (ret);
}

char				*test_params_sharp(t_environment *env)
{
	char				*ret;

	ret = twl_itoa(twl_lst_len(env->pos_params));
	return (ret);
}


bool				expan_exec_param_sharp(t_expan_token *expan_token)
{
	expan_token->res = params_sharp();
	return (true);
}
