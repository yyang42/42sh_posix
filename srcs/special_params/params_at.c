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
#include "prog.h"
#include "environment.h"
#include "twl_lst.h"

char				*params_at(void)
{
	t_environment	*env;
	char			*ret;

	env = environment_singleton();
	if (twl_lst_len(env->pos_params) > 0)
		ret = environment_concat_pos_param_char(env, " ");
	else
		ret = twl_strdup("");
	return (ret);
}

char				*test_params_at(t_environment *env)
{
	char			*ret;

	if (twl_lst_len(env->pos_params) > 0)
		ret = environment_concat_pos_param_char(env, " ");
	else
		ret = twl_strdup("");
	return (ret);
}
