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
#include "twl_gnl.h"
#include <fcntl.h>

/*
** TODO: Gestion d'erreurs shenv_singl_error (rebase)
*/

static void	child_part(t_expansion *this, t_expan_token *token, int fd[2])
{
	char	*cmd;

	if (dup2(fd[1], 1) == -1)
	{
		shenv_singl_error(EXIT_FAILURE, "dup2 error\n");
		exit(-1);
	}
	close(fd[0]);
	cmd = twl_strndup(token->text + 2, twl_strlen(token->text + 3));
    ast_utils_exec_string(cmd, 1);
	free(cmd);
	exit(-1);
	(void)this;
}

static void	remove_end_newline_fn(void *data, void *context)
{
	char	*str;
	bool	*check;
	int		index;

	str = data;
	check = context;
	if (*check)
		return ;
	index = 0;
	while (str[index])
		index += 1;
	while (--index >= 0)
	{
		if (str[index] == '\n')
			str[index] = 0;
		else
		{
			*check = true;
			return ;
		}
	}
}

static void	push_before_split_fn(void *data, void *context)
{
	expansion_push_before_split(context, data,
								!((t_expansion *)context)->quoted);
}

static void parent_part(t_expansion *this, t_expan_token *token, int fd[2])
{
	t_lst	*lst;
	char    buf[128];
	int     size;
	bool	check;

	close(fd[1]);
	lst = twl_lst_new();
	while ((size = read(fd[0], buf, 127)) > 0)
	{
		buf[size] = 0;
		twl_lst_push_back(lst, expan_quote(buf, this->quoted));
	}
	check = false;
	twl_lst_iterb(lst, remove_end_newline_fn, &check);
	twl_lst_iter(lst, push_before_split_fn, this);
	twl_lst_del(lst, free);
	close(fd[0]);
	wait(&size); // TODO: message d'erreur toussa...
	(void)token;
}

void		expansion_cmdsbt_dollar(t_expansion *this, t_expan_token *token)
{
	int		fd[2];
	int		pid;

	if (pipe(fd) == -1)
	{
		shenv_singl_error(EXIT_FAILURE, "pipe error\n");
		exit(-1);
	}
	if ((pid = fork()) == -1)
	{
		shenv_singl_error(EXIT_FAILURE, "pipe error\n");
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
