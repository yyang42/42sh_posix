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

t_expan_param_type	string_1_to_expan_type(char *str)
{
	static t_dict	*dict_single = NULL;
	char			*ret;

	if (dict_single == NULL)
	{
		dict_single = twl_dict_new();
		twl_dict_add(dict_single, "-", twl_itoa(HYPHEN));
		twl_dict_add(dict_single, "=", twl_itoa(EQUAL));
		twl_dict_add(dict_single, "?", twl_itoa(QUESTION));
		twl_dict_add(dict_single, "+", twl_itoa(PLUS));
		twl_dict_add(dict_single, "%", twl_itoa(PERCENT));
		twl_dict_add(dict_single, "#", twl_itoa(SHARP));
	}
	ret = twl_dict_get(dict_single, str);
	if (ret)
		return ((t_expan_param_type)twl_atoi(ret));
	else
		return (UNDEFINED_PARAM);
}

t_expan_param_type	string_2_to_expan_type(char *str)
{
	static t_dict	*dict_double = NULL;
	char			*ret;

	if (dict_double == NULL)
	{
		dict_double = twl_dict_new();
		twl_dict_add(dict_double, ":-", twl_itoa(COLON_HYPHEN));
		twl_dict_add(dict_double, ":=", twl_itoa(COLON_EQUAL));
		twl_dict_add(dict_double, ":?", twl_itoa(COLON_QUESTION));
		twl_dict_add(dict_double, ":+", twl_itoa(COLON_PLUS));
		twl_dict_add(dict_double, "%%", twl_itoa(PERCENT_PERCENT));
		twl_dict_add(dict_double, "##", twl_itoa(SHARP_SHARP));
	}
	ret = twl_dict_get(dict_double, str);
	if (ret)
		return ((t_expan_param_type)twl_atoi(ret));
	else
		return (UNDEFINED_PARAM);
}
