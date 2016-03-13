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

static char			*get_file2(char **av, t_shenv *this)
{
	char			*file;
	char			buf[DOT_BUFSIZE];
	int				fd;

	file = NULL;
	if (!twl_strncmp(av[1], "./", 2))
	{
		getcwd(buf, DOT_BUFSIZE);
		file = twl_joinpath(buf, &av[1][2]);
		fd = open(file, O_RDWR);
		if (fd < 0)
			return (NULL);
		close(fd);
	}
	else if (ast_simple_command_utils_get_binary_path(av[1], this))
		file = twl_strdup(ast_simple_command_utils_get_binary_path(av[1], this));
	return (file);
}

static char			*get_file(char *str, t_lst *tokens, t_shenv *this)
{
	char			*file;
	char			**av;

	av = twl_strsplit(str, ' ');
	if (twl_arr_len(av) < 2)
	{
		twl_dprintf(2, "%s\n", ".: not enough arguments");
		twl_arr_del(av, free);
		return (NULL);
	}
	file = get_file2(av, this);
	if (!file || file[0] == '\0')
	{
		shenv_print_error_printf(shenv_singleton(),
			token_mgr_first(tokens)->line,
			"bad_file", SHENV_ERROR_FILE_NOT_FOUND);
		twl_arr_del(av, free);
		return (NULL);
	}
	twl_arr_del(av, free);
	return (file);
}

void				builtin_dot_exec(t_lst *tokens, t_shenv *this)
{
	int				ret;
	char			*file;
	t_ast			*ast;
	char			*str;

	str = token_mgr_strjoin(tokens, " "); // TODO: refactor
	if (!(file = get_file(str, tokens, this)))
		return ; // (0)
	ast = ast_new(twl_file_to_str(file));
	if (ast->error_msg)
	{
		twl_dprintf(2, "%s\n", ast->error_msg);
		ast_del(ast);
		return ; // (1)
	}
	ret = ast_exec(ast);
	free(file);
	ast_del(ast);
	(void)ret;
	return ; // (ret)
}
