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

#include "builtin/builtin_set.h"
#include "environment.h"
#include "twl_opt_elem.h"

void				environment_add_shell_func(t_environment *env,
							char *key, struct s_ast_compound_command *data)
{
	if (key)
	{
		twl_dict_set(env->shell_func, key, data, NULL);
	}
}
