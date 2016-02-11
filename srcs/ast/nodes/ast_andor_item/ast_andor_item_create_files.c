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

#include <ast/nodes/ast_andor_item.h>

static void			iter_redir_rec_fn(void *ast_redir_, void *nothing_)
{
	t_ast_redir	*ast_redir;
	int			len;
	int			fd;

	ast_redir = ast_redir_;
	len = twl_strlen(ast_redir->operator);
	if (ast_redir->operator[len - 1] == '>')
	{
		if (!twl_strcmp(ast_redir->operator, ">>"))
		{
			fd = open(ast_redir->param, O_RDONLY);
			if (fd < 0)
				create_file(ast_redir->param);
			else
				close(fd);
		}
		else
			create_file(ast_redir->param);
	}
	(void)nothing_;
}

static void			ast_simple_command_create_file(t_ast_simple_command *this)
{
	twl_lst_iter(this->redir_items, iter_redir_rec_fn, NULL);
}

static void			ast_command_create_file(t_ast_command *this)
{
	if (this->command_type != COMMAND_COMPOUND_COMMAND)
		ast_simple_command_create_file(this->command);
}

static void			iter_pipe_fn(void *ast_pipe_item_, void *nothing_)
{
	t_ast_pipe_item	*ast_pipe_item;

	(void)nothing_;
	ast_pipe_item = ast_pipe_item_;
	ast_command_create_file(ast_pipe_item->ast_command);
}

int					ast_andor_item_create_files(t_ast_andor_item *andor_item)
{
	twl_lst_iter(andor_item->ast_pipe_items, iter_pipe_fn, NULL);
	return (0);
}
