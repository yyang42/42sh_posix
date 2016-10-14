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

#include "builtin/cmds/builtin_dot.h"
#include "ast/ast.h"
#include "ast/nodes/ast_compound_list.h"
#include "prog.h"

static char			*get_file(char *raw_path, t_shenv *this)
{
	char			*resolved_path;
	char			buf[DOT_BUFSIZE];
	int				fd;
	char			*binary_path;

	resolved_path = NULL;
	if (!twl_strncmp(raw_path, "./", 2))
	{
		getcwd(buf, DOT_BUFSIZE);
		resolved_path = twl_joinpath(buf, raw_path + 2);
		fd = open(resolved_path, O_RDONLY);
		if (fd < 0)
			return (NULL);
		close(fd);
	}
	else if ((binary_path = shenv_find_binary_path(this, raw_path)))
	{
		resolved_path = twl_strdup(binary_path);
	}
	return (resolved_path);
}

void				builtin_dot_exec_do(char *raw_path)
{
	char			*resolved_path;
	t_shenv			*env;
	int				flags_save;

	env = shenv_singleton();
	resolved_path = get_file(raw_path, shenv_singleton());
	if (!resolved_path)
	{
		shenv_singl_error(EXIT_FAILURE, "%s: No such file or directory",
				raw_path);
		if (!shenv_is_interactive(shenv_singleton()))
			shenv_utils_exit(EXIT_FAILURE);
		return ;
	}
	env->shenv_is_function_or_script = true;
	flags_save = env->shenv_prog_flags;
	env->shenv_prog_flags |= SHENV_FLAG_EXIT_ON_AST_ERROR;
	prog_utils_run_file(resolved_path);
	env->shenv_is_function_or_script = false;
	shenv_singleton()->shenv_return_triggered = false;
	env->shenv_prog_flags = flags_save;
	free(resolved_path);
}
