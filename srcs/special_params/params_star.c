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

char				*params_star()
{
	t_environment	*env;
	char			*ret;
	char			*ifs;
	char			*sep;

	env = environment_singleton();
	ifs = environment_getenv_value(env, "IFS");
	if (ifs == NULL)
		sep = twl_strdup(" ");
	else if (*ifs == 0)
		sep = twl_strdup("");
	else
		sep = twl_strdup(ifs);
	if (twl_lst_len(env->pos_params) > 0)
		ret = environment_concat_pos_param_char(env, sep);
	else
		ret = twl_strdup("");
	free(sep);
	return (ret);
}

char				*test_params_star(t_environment *env)
{
	char			*ret;
	char			*sep;
	char			*ifs;

	ifs = environment_getenv_value(env, "IFS");
	if (ifs == NULL)
		sep = twl_strdup(" ");
	else if (*ifs == 0)
		sep = twl_strdup("");
	else
		sep = twl_strdup(ifs);
	if (twl_lst_len(env->pos_params) > 0)
		ret = environment_concat_pos_param_char(env, sep);
	else
		ret = twl_strdup("");
	free(sep);
	return (ret);
}
