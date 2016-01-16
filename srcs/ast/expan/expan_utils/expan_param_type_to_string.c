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
#include "ast/expan/ast_expan_tilde.h"
#include "ast/expan/ast_expan_param.h"
#include "ast/expan/ast_expan_type.h"
#include "twl_dict.h"

void *expan_param_type_to_print_func(t_expan_type type)
{
	static t_dict *dict = NULL;
	char			*str;
	void			*ret;

	if (dict == NULL)
	{
		dict = twl_dict_new();
		twl_dict_add(dict, twl_itoa(NONE), NULL);
		twl_dict_add(dict, twl_itoa(TILDE), expan_tilde_print);
		twl_dict_add(dict, twl_itoa(PARAMETER), expan_param_print);
		// twl_dict_add(dict, twl_itoa(COMMAND_SUBSTITUTION), expan_exec_param_sharp);
		// twl_dict_add(dict, twl_itoa(ARITHMETIC), expan_exec_param_hyphen);
		// twl_dict_add(dict, twl_itoa(PATHNAME), expan_exec_param_hyphen);
		// twl_dict_add(dict, twl_itoa(QUOTE_REMOVAL), expan_exec_param_hyphen);
	}
	str = twl_itoa(type);
	ret = twl_dict_get(dict, str);
	twl_strdel(&str);
	return (ret);
}
