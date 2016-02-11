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



bool			expan_exec_params_colon_plus(t_expan_token *expan_token)
{
	t_expan_param		*data;
	t_environment_var	*env_var;
	t_environment		*env;

	data = expan_token->expan_data;
	env = environment_singleton();
	if (data->parameter && twl_strcmp(data->parameter, ""))
	{
		env_var = environment_get(env, data->parameter);
		if (env_var)
		{
			if (env_var->value != NULL && env_var->value_is_set == 1)
				expan_token->res = expan_exec_param_word_expan(data->word);
			else
				expan_token->res = twl_strdup("");
		}
		else
			expan_token->res = twl_strdup("");
	}
	else
		expan_token->res = twl_strdup("");
	return (true);
}
