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

#include "ast/nodes/ast_redir.h"
#include "ast/nodes/ast_assignment.h"
#include "ast/nodes/ast_simple_command.h"

bool				ast_redir_fd_utils_is_valid_duplicate_fd(int fd)
{
	if (fd > getdtablesize())
	{
		shenv_singl_error(EXIT_FAILURE, "%d: Bad file descriptor", fd);
		return (false);
	}
	return (true);
}
