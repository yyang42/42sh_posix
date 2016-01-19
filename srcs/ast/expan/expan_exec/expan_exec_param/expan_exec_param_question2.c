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

static void		print_error_msg(t_expan_param *data)
{
	char	*word_expan;

	word_expan = expan_exec_param_word_expan(data->word);
	if (twl_strcmp(word_expan, ""))
		twl_dprintf(2, "42sh: %s: %s\n", data->parameter, word_expan);
	else
		twl_dprintf(2, "42sh: %s: parameter null or not set\n",
			data->parameter);
}

static void		set_env_value_to_null(t_environment *env, t_expan_param *data)
{
	environment_setenv_value(env, data->parameter, "", 0);
	print_error_msg(data);
}
bool			expan_exec_params_question2(t_expan_token *expan_token)
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
			{
				expan_token->res = twl_strdup(env_var->value);
				return (true);
			}
			else
				set_env_value_to_null(env, data);
		}
		else
			print_error_msg(data);
	}
	else
		print_error_msg(data);
	expan_token->res = twl_strdup("");
	return (true);
}
