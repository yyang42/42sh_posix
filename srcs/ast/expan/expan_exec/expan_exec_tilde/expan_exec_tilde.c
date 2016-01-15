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
#include "ast/expan/ast_expan_tilde.h"
#include "special_params.h"
#include "environment.h"

char			*expan_exec_tilde_get_home()
{
	t_environment *env;

	env = environment_singleton();
	return (environment_getenv_value(env, "HOME"));
}

void			expan_exec_tilde(t_expan_token *expan_token)
{
	t_expan_tilde	*expan_tilde;
	char			*home;

	expan_tilde = expan_token->expan_data;
	twl_strdel(&expan_token->res);
	home = expan_exec_tilde_get_home();
	twl_printf(expan_tilde->suffix);
	if (!expan_tilde->suffix && !expan_tilde->suffix && home)
	{
		expan_token->res = twl_strdup(home);
	}
	if (expan_tilde->suffix)
	{
		//TODO Check si le suffix existe, si c'est le cas remplacer par le vrai chemin
		expan_token->res = twl_strjoin(expan_tilde->token, expan_tilde->suffix);
	}
	else
	{
		expan_token->res = twl_strdup("");
	}
}
