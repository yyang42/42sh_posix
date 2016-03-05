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


char				*params_dollar(void)
{
	t_shenv	*env;

	env = shenv_singleton();
	return (shenv_concat_flags(env));
}

char				*test_params_dollar(t_shenv *env)
{
	return (shenv_concat_flags(env));
}

bool				expan_exec_param_dollar(t_expan_token *expan_token)
{
	expan_token->res = params_dollar();
	return (true);
}
