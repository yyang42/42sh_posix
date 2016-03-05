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


static void		set_env_and_token(t_shenv *env, t_expan_token *expan_tok,
	t_expan_param *data)
{
	environment_setenv_value(env, data->parameter, data->word, 1);
	expan_tok->res = twl_strdup(data->word);
}

bool			expan_exec_params_colon_equal(t_expan_token *expan_token)
{
	t_expan_param		*data;
	t_shenv		*env;
	t_envvar	*envvar;

	data = expan_token->expan_data;
	env = environment_singleton();
	if (data->parameter && twl_strcmp(data->parameter, ""))
	{
		envvar = environment_get(env, data->parameter);
		if (envvar )
		{
			if (envvar->envvar_value != NULL && envvar->envvar_value_is_set == 1)
				expan_token->res = twl_strdup(envvar->envvar_value);
			else
				set_env_and_token(env, expan_token, data);
		}
		else
			set_env_and_token(env, expan_token, data);
	}
	else
		expan_token->res = twl_strdup("");
	return (true);
}
