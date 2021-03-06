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
#include "twl_logger.h"

static void			open_fd(int io_number, char *path, int flags, int mode)
{
	int				tmp_fd;

	LOG_INFO("exec: open fd: %d %s", io_number, path);
	tmp_fd = open(path, flags, mode);
	if (tmp_fd == -1)
	{
		shenv_singl_error(EXIT_FAILURE, "exec: %s", twl_strerror(errno));
		return ;
	}
	if (dup2(tmp_fd, io_number) == -1)
	{
		shenv_singl_error(EXIT_FAILURE, "%d: %s",
				io_number, twl_strerror(errno));
		LOG_INFO("exec: dup2(%d, %d)", tmp_fd, io_number);
	}
	if (close(tmp_fd) == -1)
	{
		LOG_ERROR("exec: close tmp_fd(%d): ", twl_strerror(errno));
		shenv_singl_error(EXIT_FAILURE, "exec: %s", twl_strerror(errno));
	}
}

static void			copy_fd(int target_fd, char *param)
{
	int				source_fd;
	int				errno;

	if (!twl_str_is_pos_num(param))
	{
		shenv_singl_error(EXIT_FAILURE, "exec: %s: Bad file descriptor", param);
		return ;
	}
	source_fd = twl_atoi(param);
	LOG_INFO("exec: copy: dup2(%d, %d)", source_fd, target_fd);
	if (dup2(source_fd, target_fd) == -1)
	{
		shenv_singl_error(EXIT_FAILURE, "%d or %d: %s", source_fd, target_fd,
				twl_strerror(errno));
	}
}

void				builtin_exec_redir_exec(int io_number, char *operator,
		char *param)
{
	if (twl_strequ(operator, "<&") && twl_strequ(param, "-"))
	{
		LOG_INFO("exec: close fd: %d", io_number);
		if (close(io_number) == -1)
		{
			LOG_INFO("exec: close error: %s", twl_strerror(errno));
		}
	}
	else if (twl_strequ(operator, ">"))
		open_fd(io_number, param, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (twl_strequ(operator, "<"))
		open_fd(io_number, param, O_RDONLY, 0644);
	else if (twl_strequ(operator, "<>"))
		open_fd(io_number, param, O_CREAT | O_RDWR, 0644);
	else if (twl_strequ(operator, ">>"))
		open_fd(io_number, param, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (twl_strequ(operator, "<&") || twl_strequ(operator, ">&"))
		copy_fd(io_number, param);
	else
		shenv_singl_error(EXIT_FAILURE, "exec: invalid redir operator",
				operator);
}
