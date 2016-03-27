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


char				*params_at(void)
{
	t_shenv	*env;
	char			*ret;

	env = shenv_singleton();
	if (twl_lst_len(env->pos_params) > 0)
		ret = shenv_concat_pos_param_char(env, " ");
	else
		ret = twl_strdup("");
	return (ret);
}

char				*test_params_at(t_shenv *env)
{
	char			*ret;

	if (twl_lst_len(env->pos_params) > 0)
		ret = shenv_concat_pos_param_char(env, " ");
	else
		ret = twl_strdup("");
	return (ret);
}

bool			expan_exec_param_at(t_expan_token *expan_token)
{
	expan_token->res = params_at();
	return (true);
}