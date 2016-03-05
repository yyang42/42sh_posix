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
#include "expan/expan_param.h"


bool			expan_exec_params_hyphen2(t_expan_token *expan_token)
{
	t_expan_param		*data;
	t_envvar	*envvar;
	t_shenv		*env;

	data = expan_token->expan_data;
	env = environment_singleton();
	if (data->parameter && twl_strcmp(data->parameter, ""))
	{
		envvar = environment_get(env, data->parameter);
		if (envvar)
		{
			if (envvar->envvar_value && envvar->envvar_value_is_set == 1)
				expan_token->res = twl_strdup(envvar->envvar_value);
			else
				expan_token->res = twl_strdup("");
		}
		else
			expan_token->res = twl_strdup(data->word);
	}
	else
		expan_token->res = twl_strdup("");
	return (true);
}
