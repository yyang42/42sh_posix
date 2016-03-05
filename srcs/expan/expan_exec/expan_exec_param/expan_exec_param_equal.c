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
	shenv_setenv_value(env, data->parameter, data->word, 1);
	expan_tok->res = twl_strdup(data->word);
}

bool			expan_exec_params_equal(t_expan_token *expan_token)
{
	t_expan_param		*data;
	t_shenv		*env;
	t_shvar	*shvar;

	data = expan_token->expan_data;
	env = shenv_singleton();
	if (data->parameter && twl_strcmp(data->parameter, ""))
	{
		shvar = shenv_get(env, data->parameter);
		if (shvar)
		{
			if (shvar->shvar_value != NULL && shvar->shvar_value_is_set == 1)
				expan_token->res = twl_strdup(shvar->shvar_value);
			else
				expan_token->res = twl_strdup("");
		}
		else
			set_env_and_token(env, expan_token, data);
	}
	else
		expan_token->res = twl_strdup("");
	return (true);
}
