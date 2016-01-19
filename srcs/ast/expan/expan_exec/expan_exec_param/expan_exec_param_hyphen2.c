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
#include "ast/expan/ast_expan_exec.h"
#include "ast/expan/ast_expan_param.h"
#include "special_params.h"

bool			expan_exec_params_hyphen2(t_expan_token *expan_token)
{
	t_expan_param		*data;
	t_environment_var	*env_var;
	t_environment		*env;

	data = expan_token->expan_data;
	env = environment_singleton();
	if (data->parameter && twl_strcmp(data->parameter, ""))
	{
		env_var = environment_get(env, data->parameter);
		if (env_var && env_var->value_is_set)
		{
			if (env_var->value != NULL && twl_strcmp(env_var->value, "") != 0)
				expan_token->res = twl_strdup(env_var->value);
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
