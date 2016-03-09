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

#include "ast/nodes/ast_simple_command.h"
#include "ast/nodes/ast_compound_command.h"

static void			exit_if_function_max_depth_reached(t_shenv *env,
	t_lst *tokens)
{
	if (env->function_depth > DEFAULT_FUNCTION_MAX_RECURSION_DEPTH)
	{
		twl_dprintf(2, "%s: maximum nested function level reached\n", token_mgr_first(tokens)->text);
		exit(1);
	}
}

void				ast_simple_command_exec_function(t_lst *tokens,
									struct s_ast_compound_command *compound_cmd)
{
	t_lst			*pos_params_original;
	t_lst			*tokens_str_lst;
	t_shenv			*env;

	env = shenv_singleton();
	tokens_str_lst = token_mgr_to_lst(tokens);
	twl_lst_pop_front(tokens_str_lst);
	pos_params_original = env->pos_params;
	env->pos_params = tokens_str_lst;
	env->function_depth++;
	exit_if_function_max_depth_reached(env, tokens);
	ast_compound_command_exec(compound_cmd);
	twl_lst_del(tokens_str_lst, NULL);
	env->pos_params = pos_params_original;
}
