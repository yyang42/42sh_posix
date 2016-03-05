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


static char		*ft_treat_sharp(char *str, char *word)
{
	int len_str;
	int len_word;

	len_word = twl_strlen(word);
	if (!twl_strncmp(str, word, len_word))
	{
		len_str = twl_strlen(str);
		return (twl_strsub(str, len_word, len_str - len_word));
	}
	else
		return (twl_strdup(str));
}

//TODO: implementer le pattern matching pour finir
bool			expan_exec_params_sharp_sharp(t_expan_token *expan_token)
{
	t_expan_param		*data;
	t_environment		*env;
	t_environment_var	*env_var;

	data = expan_token->expan_data;
	env = environment_singleton();
	if (data->parameter && twl_strcmp(data->parameter, ""))
	{
		env_var = environment_get(env, data->parameter);
		if (env_var && env_var->evar_value_is_set)
		{
			if (env_var->evar_value != NULL && twl_strcmp(env_var->evar_value, "") != 0)
				expan_token->res = ft_treat_sharp(env_var->evar_value, data->word);
			else
				expan_token->res = twl_strdup("");
		}
		else
			expan_token->res = twl_strdup("");
	}
	else
		expan_token->res = twl_strdup("");
	return (true);
}
