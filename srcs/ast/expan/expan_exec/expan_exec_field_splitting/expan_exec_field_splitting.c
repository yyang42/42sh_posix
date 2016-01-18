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
#include "patmatch.h"

void		expan_exec_field_splitting(t_expan_token *token)
{
	t_environment		*env;
	t_environment_var	*ifs;

	(void)token;
	env = environment_singleton();
	ifs = environment_get(env, "IFS");
	if (ifs && ifs->value_is_set == 1)
	{

	}
}
