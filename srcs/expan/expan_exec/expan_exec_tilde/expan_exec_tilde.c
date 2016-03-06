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
#include "expan/expan_tilde.h"

#include "shenv/shenv.h"
#include "pwd.h"

static char		*expan_exec_tilde_get_home()
{
	t_shenv *env;

	env = shenv_singleton();
	return (shenv_shvars_get_value(env, "HOME"));
}

void			expan_tilde_do(char **res, char *token, char *suffix)
{
	char			*home;
	struct passwd	*pwd;

	twl_strdel(res);
	home = expan_exec_tilde_get_home();
	if ((!suffix || !*suffix) && home)
	{
		*res = twl_strdup(home);
	}
	else if (suffix)
	{
		pwd = getpwnam(suffix);
		if (pwd && pwd->pw_dir)
			*res = twl_strdup(pwd->pw_dir);
		else
			*res = twl_strjoin(token, suffix);
	}
	else
	{
		*res = twl_strdup("");
	}
}

bool			expan_exec_tilde(t_expan_token *expan_token)
{
	t_expan_tilde	*expan_tilde;

	expan_tilde = expan_token->expan_data;
	expan_tilde_do(&expan_token->res, expan_tilde->token, expan_tilde->suffix);
	return (true);
}
