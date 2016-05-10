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

#include "builtin/cmds/builtin_set.h"

#define ESCAPE_QUOTE_CHARS " \n\t!\"#$&\'()*;<>?[\\]^`{|}~"

static void			print_with_single_quote(char *key, char *value)
{
	char			*escaped;

	escaped = twl_str_replace(value, "'", "'\\''");
	twl_printf("%s='%s'\n", key, escaped);
	free(escaped);
}

static void			print_shvar(void *data)
{
	t_shvar			*var;

	var = data;
	if (var->shvar_value)
	{
		if (twl_strchr_any(var->shvar_value, ESCAPE_QUOTE_CHARS))
		{
			print_with_single_quote(var->shvar_key, var->shvar_value);
		}
		else
		{
			twl_printf("%s=%s\n", var->shvar_key, var->shvar_value);
		}
	}
}

void				builtin_set_exec_print(t_shenv *this)
{
	twl_lst_iter0(this->shenv_shvars, print_shvar);
}
