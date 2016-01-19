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

bool		expan_exec_pattern_matching(t_expan_token *token)
{
	t_environment	*env;
	t_patmatch 		*patmatch;
	t_lst			*res;

	env = environment_singleton();
	if (!environment_flag_exist(env, "f"))
	{
		patmatch = patmatch_new();
		res = patmatch_match(patmatch, token->res);
		//TODO Get final str and replace token->res :p
		twl_lst_del(res, &free);
		patmatch_del(patmatch);
	}
	return (true);
}
