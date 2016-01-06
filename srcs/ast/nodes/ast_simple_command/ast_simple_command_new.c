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
#include "builtin.h"

t_ast_simple_command			*ast_simple_command_new(void)
{
	t_ast_simple_command		*ast_simple_command;

	ast_simple_command = twl_malloc_x0(sizeof(t_ast_simple_command));
	ast_simple_command->command_tokens = NULL;
	ast_simple_command->redir_items = twl_lst_new();
	ast_simple_command->assignment_items = twl_lst_new();
	ast_simple_command->redir_fds = twl_lst_new();
	ast_simple_command->builtin_func = twl_dict_new();
	twl_dict_add(ast_simple_command->builtin_func, "echo", &echo);
	twl_dict_add(ast_simple_command->builtin_func, "cd", &cd);
	twl_dict_add(ast_simple_command->builtin_func, "env", &env);
	twl_dict_add(ast_simple_command->builtin_func, "export", &export);
	twl_dict_add(ast_simple_command->builtin_func, "set", &set);
	twl_dict_add(ast_simple_command->builtin_func, "unset", &unset);
	twl_dict_add(ast_simple_command->builtin_func, "alias", &alias);
	twl_dict_add(ast_simple_command->builtin_func, "umask", &umask_builtin);
	return (ast_simple_command);
}
