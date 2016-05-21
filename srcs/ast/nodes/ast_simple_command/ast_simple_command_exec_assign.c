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
#include "ast/nodes/ast_assignment.h"

static void			print_assign_xtrace(t_ast_assignment *assign)
{
	shenv_print_ps4(shenv_singleton());
	twl_dprintf(2, "%s=%s\n", assign->key, assign->value);
}

static void			iter_assign_fn(void *assign_, void *cmd_)
{
	t_ast_assignment		*assign;
	t_ast_simple_command 	*cmd;
	t_shvar					*shvar;

	assign = assign_;
	cmd = cmd_;
	shenv_set_cur_token(shenv_singleton(), assign->token);
	if (shenv_shflag_enabled(shenv_singleton(), "xtrace"))
		print_assign_xtrace(assign);
	shvar = shvar_mgr_find_or_create(shenv_singleton()->shenv_shvars, assign->key);
	if (shvar_check_is_readonly_and_print(shvar))
		return ;
	if (twl_lst_len(cmd->cmd_tokens_deep_copy) == 0
		|| ast_simple_command_is_special_builtin(cmd))
	{
		shvar_set_value(shvar, assign->value);
	}
	else
	{
		shvar->shvar_assign_value = twl_strdup(assign->value);
	}
	if (shenv_shflag_enabled(shenv_singleton(), "allexport"))
	{
		shvar->shvar_exported = true;
	}
}

void				ast_simple_command_exec_assign(t_ast_simple_command *cmd)
{
	twl_lst_iter(cmd->assignment_items, iter_assign_fn, cmd);
}
