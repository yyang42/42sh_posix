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

int			ast_redir_fd_utils_get_duplication_fd(char *str)
{
	int fd;

	if (twl_str_is_pos_num(str))
	{
		fd = twl_atoi(str);
		if (ast_redir_fd_utils_is_valid_duplicate_fd(fd))
			return (fd);
		return (-1);
	}
	else
	{
		twl_dprintf(2, "42sh: %s: ambiguous redirect", str);
		return (-1);
	}
}
