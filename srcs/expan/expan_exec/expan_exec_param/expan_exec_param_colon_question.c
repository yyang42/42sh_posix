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
	t_shvar	*shvar;
	t_shenv		*env;

	data = expan_token->expan_data;
	env = shenv_singleton();
	if (data->parameter && twl_strcmp(data->parameter, ""))
	{
		shvar = shenv_shvars_get(env, data->parameter);
		if (shvar && shvar->shvar_value)
		{
			if (shvar->shvar_value != NULL && shvar->shvar_value)
			{
				expan_token->res = twl_strdup(shvar->shvar_value);
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
