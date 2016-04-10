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

#include "expan/expansion.h"
#include "ast/ast.h"
#include "twl_get_next_line.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

/*
** TODO: Gestion d'erreurs shenv_singl_error (rebase)
*/

static void	child_part(t_expansion *this, t_expan_token *token, int fd[2])
{
	char	*cmd;

	if (dup2(fd[1], 1) == -1)
	{
		twl_dprintf(2, "42sh: dup2 error\n");
		exit(-1);
	}
	close(fd[0]);
	cmd = twl_strndup(token->text + 1, twl_strlen(token->text + 2));
    ast_exec_string(cmd);
	close(fd[1]);
	free(cmd);
	exit(-1);
	(void)this;
}

static void	parent_part(t_expansion *this, t_expan_token *token, int fd[2])
{
	char	buf[128];
	int		size;

	close(fd[1]);
	while ((size = read(fd[0], buf, 127)) > 0)
	{
		buf[size] = 0;
		expansion_push_before_split(this, buf, !this->quoted);
	}
	close(fd[0]);
	(void)token;
}

void		expansion_cmdsbt_bquote(t_expansion *this, t_expan_token *token)
{
	int		fd[2];
	int		pid;

	if (pipe(fd) == -1)
	{
		twl_dprintf(2, "42sh: pipe error\n");
		exit(-1);
	}
	if ((pid = fork()) == -1)
	{
		twl_dprintf(2, "42sh: pipe error\n");
		exit(-1);
	}
	if (pid == 0)
	{
		child_part(this, token, fd);
	}
	else
	{
		parent_part(this, token, fd);
	}
}
