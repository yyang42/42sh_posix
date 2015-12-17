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

#include "simple_command.h"
<<<<<<< 5cfe5110949bd6ea648812288938a171cf733ed5:srcs/simple_command/get_binary_path.c
#include "environment.h"
=======
#include "builtin.h"
>>>>>>> Links with builtin:srcs/simple_command/simple_command_new.c

char	*get_binary_path(char *cmd)
{
<<<<<<< 5cfe5110949bd6ea648812288938a171cf733ed5:srcs/simple_command/get_binary_path.c
	t_environment	*env;
	char			**paths;

	env = environment_singleton();
	paths = environment_get_paths(env);
	(void)cmd;
	return (NULL);
=======
	(void)dict;
	twl_dict_add(dict, "echo", &echo);
	twl_dict_add(dict, "cd", &cd);
	twl_dict_add(dict, "env", &env);
	twl_dict_add(dict, "export", &export);
	twl_dict_add(dict, "set", &set);
	twl_dict_add(dict, "unset", &unset);
}

t_simple_command				*simple_command_new(void)
{
	t_simple_command			*simple_command;

	simple_command = twl_malloc_x0(sizeof(t_simple_command));
	simple_command->builtin_func = twl_dict_new();
	fill_builtin_dict(simple_command->builtin_func);
	return (simple_command);
>>>>>>> Links with builtin:srcs/simple_command/simple_command_new.c
}
