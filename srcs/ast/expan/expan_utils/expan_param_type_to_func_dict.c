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

#include "ast/expan/ast_expan_tokenizer.h"
#include "ast/expan/ast_expan_exec.h"
#include "ast/expan/ast_expan_param.h"
#include "twl_dict.h"

void *expan_param_type_to_func_dict(t_expan_param_type type)
{
	static t_dict *dict = NULL;
	char			*str;
	void			*ret;

	if (dict == NULL)
	{
		dict = twl_dict_new();
		twl_dict_add(dict, twl_itoa(S_STAR), expan_exec_param_star);
		twl_dict_add(dict, twl_itoa(S_ZERO), expan_exec_param_zero);
		twl_dict_add(dict, twl_itoa(S_QUESTION), expan_exec_param_question);
		twl_dict_add(dict, twl_itoa(S_SHARP), expan_exec_param_sharp);
		twl_dict_add(dict, twl_itoa(S_HYPHEN), expan_exec_param_hyphen);
		twl_dict_add(dict, twl_itoa(S_EXCLAMATION), expan_exec_param_exclamation);
		twl_dict_add(dict, twl_itoa(S_DOLLAR), expan_exec_param_dollar);
		twl_dict_add(dict, twl_itoa(S_AT), expan_exec_param_at);
		twl_dict_add(dict, twl_itoa(EXPAN_VAR), expan_exec_param_var);
		twl_dict_add(dict, twl_itoa(COLON_HYPHEN), expan_exec_params_colon_hyphen);
		twl_dict_add(dict, twl_itoa(COLON_EQUAL), expan_exec_params_colon_equal);
	}
	str = twl_itoa(type);
	ret = twl_dict_get(dict, str);
	twl_strdel(&str);
	return (ret);
}
