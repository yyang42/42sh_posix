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


static char		*ft_treat_percent(char *str, char *word)
{
	int		len_str;;
	int		len_word;
	char	*end_sub;

	len_str = twl_strlen(str);
	len_word = twl_strlen(word);
	if (len_str < len_word)
		return (twl_strdup(str));
	else
	{
		end_sub = twl_strsub(str, len_str - len_word, len_word);
		if (!twl_strcmp(end_sub, word))
			return (twl_strsub(str, 0, len_str - len_word));
	}
	return (twl_strdup(str));
}

//TODO: implementer le pattern matching pour finir
bool			expan_exec_params_percent_percent(t_expan_token *expan_token)
{
	t_expan_param		*data;
	t_shenv		*env;
	t_shvar	*shvar;

	data = expan_token->expan_data;
	env = shenv_singleton();
	if (data->parameter && twl_strcmp(data->parameter, ""))
	{
		shvar = shenv_shvars_get(env, data->parameter);
		if (shvar && shvar->shvar_value)
		{
			if (shvar->shvar_value)
				expan_token->res = ft_treat_percent(shvar->shvar_value, data->word);
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