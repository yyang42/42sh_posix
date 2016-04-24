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

#include "ast/nodes/ast_redir_fd.h"
#include <errno.h>
#include "shenv/shenv.h"

void				ast_redir_fd_utils_dup_fds(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
	{
		shenv_singl_error(1, "%d: %s", fd1, strerror(errno));
		LOG_INFO("dup2(%d, %d): %s", fd1, fd2, strerror(errno));
		shenv_singleton()->last_exit_code = EXIT_FAILURE;
	}
}
