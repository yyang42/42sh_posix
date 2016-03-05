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


char				*params_star(bool between_quotes)
{
	t_shenv		*env;
	char				*ret;
	t_shvar	*ifs;
	char				*sep;

	env = environment_singleton();
	ifs = environment_get(env, "IFS");
	if (ifs == NULL || between_quotes == false || ifs->shvar_value_is_set == 0)
		sep = twl_strdup(" ");
	else if (ifs->shvar_value_is_set == 1 && *(ifs->shvar_value) == 0)
		sep = twl_strdup("");
	else
		sep = twl_strdup(ifs->shvar_value);
	if (twl_lst_len(env->pos_params) > 0)
		ret = environment_concat_pos_param_char(env, sep);
	else
		ret = twl_strdup("");
	free(sep);
	return (ret);
}

char				*test_params_star(t_shenv *env, bool between_quotes)
{
	char				*ret;
	char				*sep;
	t_shvar	*ifs;

	ifs = environment_get(env, "IFS");
	if (ifs == NULL || between_quotes == false || ifs->shvar_value_is_set == 0)
		sep = twl_strdup(" ");
	else if (ifs->shvar_value_is_set == 1 && *(ifs->shvar_value) == 0)
		sep = twl_strdup("");
	else
		sep = twl_strdup(ifs->shvar_value);
	if (twl_lst_len(env->pos_params) > 0)
		ret = environment_concat_pos_param_char(env, sep);
	else
		ret = twl_strdup("");
	free(sep);
	return (ret);
}

bool			expan_exec_param_star(t_expan_token *expan_token)
{
	expan_token->res = params_star(expan_token->is_double_quoted);
	return (true);
}
