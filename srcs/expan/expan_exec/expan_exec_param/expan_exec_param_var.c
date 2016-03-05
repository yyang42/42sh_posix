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

#include "shenv/shenv.h"
#include "twl_stdlib.h"
#include "twl_ctype.h"

bool			expan_exec_param_var(t_expan_token *expan_token)
{
	t_expan_param		*expan_param;
	t_shenv		*env;
	t_shvar	*var;
	char				*temp;

	expan_param = expan_token->expan_data;
	env = shenv_singleton();
	if (!expan_param->parameter)
	{
		twl_dprintf(2, "42sh: Bad substitution\n");
		return (false);
	}
	if (twl_str_is_num(expan_param->parameter))
	{
		temp = shenv_get_pos_param_at(env, twl_atoi(expan_param->parameter) - 1);
		if (temp)
			expan_token->res = twl_strdup(temp);
	}
	else
	{
		var = shenv_get(env, expan_param->parameter);
		if (var && var->shvar_value)
		{
			expan_token->res = twl_strdup(var->shvar_value);
		}
	}
	if (!expan_token->res)
	{
		expan_token->res = twl_strdup("");
	}
	return (true);
}
