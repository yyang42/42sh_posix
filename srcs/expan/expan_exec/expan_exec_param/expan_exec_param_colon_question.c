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


static void		print_error_msg(t_expan_param *data)
{
	char *word;

	word = expan_exec_param_word_expan(data->word);
	if (twl_strcmp(word, ""))
		twl_dprintf(2, "42sh: %s: %s\n", data->parameter, word);
	else
		twl_dprintf(2, "42sh: %s: parameter null or not set\n",
			data->parameter);
}

bool			expan_exec_params_colon_question(t_expan_token *expan_token)
{
	t_expan_param		*data;
	t_envvar	*envvar;
	t_shenv		*env;

	data = expan_token->expan_data;
	env = environment_singleton();
	if (data->parameter && twl_strcmp(data->parameter, ""))
	{
		envvar = environment_get(env, data->parameter);
		if (envvar && envvar->envvar_value_is_set)
		{
			if (envvar->envvar_value != NULL && twl_strcmp(envvar->envvar_value, "") != 0)
			{
				expan_token->res = twl_strdup(envvar->envvar_value);
				return (true);
			}
			else
			{
				print_error_msg(data);
				return (false);
			}
		}
		else
		{
			print_error_msg(data);
			return (false);
		}

	}
	else
		print_error_msg(data);
	expan_token->res = twl_strdup("");
	return (true);
}
