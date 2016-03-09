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

#include "expan/expan_tokenizer.h"
#include "expan/expan_exec.h"
#include "expan/expan_param.h"
#include "twl_dict.h"

static void		add_to_dict(t_dict *dict, t_expan_param_type type, bool (*f)(t_expan_token *))
{
	char	*tmp;

	tmp = twl_itoa(type);
	twl_dict_add(dict, tmp, f);
	free(tmp);
}

void *expan_param_type_to_func_dict(t_expan_param_type type)
{
	static t_dict *dict = NULL;
	char			*str;
	void			*ret;

	if (dict == NULL)
	{
		dict = twl_dict_new();
		add_to_dict(dict, S_STAR, expan_exec_param_star);
		add_to_dict(dict, S_ZERO, expan_exec_param_zero);
		add_to_dict(dict, S_QUESTION, expan_exec_param_question);
		add_to_dict(dict, S_SHARP, expan_exec_param_sharp);
		add_to_dict(dict, S_HYPHEN, expan_exec_param_hyphen);
		add_to_dict(dict, S_EXCLAMATION, expan_exec_param_exclamation);
		add_to_dict(dict, S_DOLLAR, expan_exec_param_dollar);
		add_to_dict(dict, S_AT, expan_exec_param_at);
		add_to_dict(dict, EXPAN_VAR, expan_exec_param_var);
		add_to_dict(dict, COLON_HYPHEN, expan_exec_params_colon_hyphen);
		add_to_dict(dict, COLON_EQUAL, expan_exec_params_colon_equal);
		add_to_dict(dict, COLON_QUESTION, expan_exec_params_colon_question);
		add_to_dict(dict, QUESTION, expan_exec_params_question2);
		add_to_dict(dict, HYPHEN, expan_exec_params_hyphen2);
		add_to_dict(dict, EQUAL, expan_exec_params_equal);
		add_to_dict(dict, COLON_PLUS, expan_exec_params_colon_plus);
		add_to_dict(dict, PLUS, expan_exec_params_plus);
		add_to_dict(dict, SHARP, expan_exec_params_sharp2);
		add_to_dict(dict, SHARP_SHARP, expan_exec_params_sharp_sharp);
		add_to_dict(dict, PERCENT, expan_exec_params_percent);
		add_to_dict(dict, PERCENT_PERCENT,
			expan_exec_params_percent_percent);
	}
	str = twl_itoa(type);
	ret = twl_dict_get(dict, str);
	free(str);
	return (ret);
}
