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
#include "special_params.h"

void			expan_exec_param_var(t_expan_token *expan_token)
{
	t_expan_param		*expan_param;
	t_environment		*env;
	t_environment_var	*var;

	expan_param = expan_token->expan_data;
	env = environment_singleton();
	var = environment_get(env, expan_param->parameter);
	if (var && var->value_is_set == 1 && var->value)
	{
		expan_token->res = twl_strdup(var->value);
	}
	else
	{
		expan_token->res = twl_strdup("");
	}
}
