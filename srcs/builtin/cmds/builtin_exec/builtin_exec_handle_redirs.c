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

#include "builtin/cmds/builtin_exec.h"
#include "file.h"
#include "logger.h"

static void			open_fd(int io_number, char *path, int flags, int mode)
{
	int				tmp_fd;

	LOGGER_INFO("exec: open fd: %d %s", io_number, path);
	tmp_fd = open(path, flags, mode);
	if (tmp_fd == -1)
	{
		shenv_singl_error(1, "exec: %s", strerror(errno));
		return ;
	}
	if (dup2(tmp_fd, io_number) == -1)
	{
		shenv_singl_error(1, "exec: %s: %d", strerror(errno), io_number);
		LOGGER_ERROR("exec: dup2(%d, %d)", tmp_fd, io_number, strerror(errno));
	}
	if (close(tmp_fd) == -1)
		LOGGER_ERROR("exec: close tmp_fd(%d): ", strerror(errno));
}

static void			iter_redir_fn(void *tokens)
{
	// t_ast_redir		*ast_redir;
	int				io_number;
	char			*operator;
	char			*param;

	// ast_redir = ast_redir_new_from_tokens(one_redir_tokens, ast);
	// token_mgr_print(tokens);
	if (twl_lst_len(tokens) == 3)
	{
		io_number = twl_atoi(token_mgr_get(tokens, 0)->text);
		operator = token_mgr_get(tokens, 1)->text;
		param = token_mgr_get(tokens, 2)->text;
		if (twl_strequ(operator, "<&") && twl_strequ(param, "-"))
		{
			LOGGER_INFO("exec: close fd: %d", io_number);

			if (close(io_number) == -1)
			{
				LOGGER_INFO("exec: close error: %s", strerror(errno));
			}
		}
		else if (twl_strequ(operator, ">"))
		{
			open_fd(io_number, param, O_CREAT | O_WRONLY, 0644);
		}
		else
		{
			LOGGER_ERROR("exec: redir case not handled: %d %s %s", io_number, operator, param);
		}
		(void)operator;
	}
	else
	{
		LOGGER_ERROR("exec: redirs len other than 3 not handled")
	}
}

void				builtin_exec_handle_redirs(t_lst *redir_tokens_groups)
{
	twl_lst_iter0(redir_tokens_groups, iter_redir_fn);
}
