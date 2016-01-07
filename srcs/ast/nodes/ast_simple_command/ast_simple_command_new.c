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

t_dict							*get_builtin_func_dict(void)
{
	t_dict *dict;

	dict = twl_dict_new();
	twl_dict_add(dict, "echo", &echo);
	twl_dict_add(dict, "cd", &cd);
	twl_dict_add(dict, "env", &env);
	twl_dict_add(dict, "export", &export);
	twl_dict_add(dict, "setenv", &setenv_builtin);
	twl_dict_add(dict, "set", &set);
	twl_dict_add(dict, "unset", &unset);
	twl_dict_add(dict, "alias", &alias);
	twl_dict_add(dict, "umask", &umask_builtin);
	return (dict);
}

t_ast_simple_command			*ast_simple_command_new(void)
{
	t_ast_simple_command		*ast_simple_command;

	ast_simple_command = twl_malloc_x0(sizeof(t_ast_simple_command));
	ast_simple_command->command_tokens = NULL;
	ast_simple_command->redir_items = twl_lst_new();
	ast_simple_command->assignment_items = twl_lst_new();
	ast_simple_command->redir_fds = twl_lst_new();
	ast_simple_command->builtin_func = get_builtin_func_dict();
	return (ast_simple_command);
}
