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

#include "builtin/builtin.h"

void				builtin_kill_exec(t_lst *tokens, t_shenv *env)
{
	// twl_printf("builtin kill not impl\n");
	shenv_print_error(env, token_mgr_first(tokens)->line,
		"kill", "ABCD: invalid signal specification");
	// twl_dprintf(2, "%s: line %d: kill: ABCD: invalid signal specification\n",
	// 	env->shenv_name,
	// 	token_mgr_first(tokens)->line);
	// token_mgr_print(tokens);
}
