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
#include "builtin/builtin.h"

void			dup_fds(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		perror("dup2");
}

char			*get_binary_path(char *cmd, t_shenv *env)
{
	char			**paths;
	char			*path;
	int				i;

	if (cmd && (cmd[0] == '/' || twl_strncmp(cmd, "./", 2) == 0))
		return (!file_exists(cmd) ? NULL : cmd);
	paths = environment_get_paths(env);
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		path = twl_joinpath(paths[i], cmd);
		if (file_exists(path))
		{
			twl_arr_del(paths, free);
			return (path);
		}
		free(path);
	}
	twl_arr_del(paths, free);
	return (NULL);
}

static bool		find_bultin(void *builtin_, void *cmd_)
{
	char	*builtin;
	char	*cmd;

	builtin = builtin_;
	cmd = cmd_;
	if (twl_strcmp(builtin, cmd) == 0)
		return (true);
	return (false);
}

t_dict			*get_builtin_func_dict(void)
{
	t_dict *dict;

	dict = twl_dict_new();
	twl_dict_add(dict, ".", &builtin_dot_exec);
	twl_dict_add(dict, "alias", &builtin_alias_exec);
	twl_dict_add(dict, "cd", &builtin_cd_exec);
	twl_dict_add(dict, "echo", &builtin_echo_exec);
	twl_dict_add(dict, "env", &builtin_env_exec);
	twl_dict_add(dict, "eval", &builtin_eval_exec);
	twl_dict_add(dict, "exit", &builtin_exit_exec);
	twl_dict_add(dict, "export", &builtin_export_exec);
	twl_dict_add(dict, "false", &builtin_false_exec);
	twl_dict_add(dict, "jobs", &builtin_jobs_exec);
	twl_dict_add(dict, "readonly", &builtin_readonly_exec);
	twl_dict_add(dict, "set", &builtin_set_exec);
	twl_dict_add(dict, "setenv", &builtin_setenv_exec);
	twl_dict_add(dict, "shift", &builtin_shift_exec);
	twl_dict_add(dict, "times", &builtin_times_exec);
	twl_dict_add(dict, "true", &builtin_true_exec);
	twl_dict_add(dict, "umask", &builtin_umask_exec);
	twl_dict_add(dict, "unset", &builtin_unset_exec);
	twl_dict_add(dict, "unsetenv", &builtin_unsetenv_exec);
	return (dict);
}

bool			is_builtin(char *cmd)
{
	static const char	*builtins[33] = {"echo", "cd", "env", "unsetenv"
	, "setenv", "alias", "unalias", "false", "true", "umask", "newgrp", "fc"
	, "command", "kill", "getopts", "read", "break", "colon", "continue"
	, "return", "shift", "set", "unset", "export", "setenv", "times"
	, "eval", ".", "readonly", "exit", "jobs", NULL};

	if (twl_arr_find(builtins, find_bultin, cmd))
		return (true);
	return (false);
}
