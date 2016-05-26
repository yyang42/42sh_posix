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
#include "ast/nodes/ast_function_def.h"

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
									struct s_ast_function_def *function_def)
{
	t_lst			*pos_params_original;
	t_lst			*tokens_str_lst;
	t_shenv			*env;

	env = shenv_singleton();
	env->shenv_is_function_or_script = true;
	tokens_str_lst = token_mgr_to_lst_deepcopy(tokens);
	free(twl_lst_pop_front(tokens_str_lst));
	pos_params_original = env->shenv_pos_params;
	env->shenv_pos_params = tokens_str_lst;
	env->function_depth++;
	exit_if_function_max_depth_reached(env, tokens);
	ast_compound_command_exec(function_def->compound_command);
	twl_lst_del(tokens_str_lst, free);
	env->shenv_pos_params = pos_params_original;
	env->shenv_return_triggered = false;
	env->shenv_is_function_or_script = false;
}
