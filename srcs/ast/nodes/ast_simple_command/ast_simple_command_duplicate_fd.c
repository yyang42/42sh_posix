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

bool		is_valid_duplicate_fd(int fd)
{
	if (fd > getdtablesize())
	{
		twl_dprintf(2, "42sh: %d: Bad file descriptor", fd);
		return false;
	}
	return true;
}

int			get_duplication_fd(char *str)
{
	int fd;

	if (twl_str_is_pos_num(str))
	{
		fd = twl_atoi(str);
		if (is_valid_duplicate_fd(fd))
			return (-1);
		return (fd);
	}
	else
	{
		twl_dprintf(2, "42sh: %s: ambiguous redirect", str);
		return (-1);
	}
}
