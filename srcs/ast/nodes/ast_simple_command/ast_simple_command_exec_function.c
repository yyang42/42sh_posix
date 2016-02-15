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

void				ast_simple_command_exec_function(t_ast_simple_command *this,
										t_environment *env, char **cmd_arr,
									struct s_ast_compound_command *compound_cmd)
{
	t_lst			*pos_params_original;

	pos_params_original = env->pos_params;
	env->pos_params = twl_arr_to_lst(cmd_arr);
	ast_compound_command_exec(compound_cmd);
	twl_lst_del(env->pos_params, free);
	env->pos_params = pos_params_original;
	(void)this;
}
