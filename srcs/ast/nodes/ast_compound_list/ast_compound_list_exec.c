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

#include <ast/nodes/ast_compound_list.h>

static void			fork_exec(t_ast_list_item *ast_list_item)
{
	int				pid;

	pid = fork();
	if (pid == -1)
	{
		twl_dprintf(2, "cannot fork: %s", strerror(errno));
	}
	else if (pid == 0)
	{
		ast_list_item_exec(ast_list_item);
		exit(0);
	}
	else
	{
		// printf("pid %d\n", pid);
		// environment_singleton()->jobs
		// int				res;
		// wait(&res);
		// if (WIFEXITED(res))
		// 	environment_singleton()->info.last_exit_status = WEXITSTATUS(res);
	}
}

static void		iter_fn(void *ast_list_item_)
{
	int					expan_ret;
	t_ast_list_item 	*ast_list_item;

	ast_list_item = ast_list_item_;
	expan_ret = ast_list_item_expan(ast_list_item);
	if (expan_ret)
	{

		if (ast_list_item->separator && twl_strequ(ast_list_item->separator->text, "&"))
		{
			fork_exec(ast_list_item);
		}
		else
		{
			ast_list_item_exec(ast_list_item);
		}
	}
}

void				ast_compound_list_exec(t_ast_compound_list *ast_compound_list)
{
	twl_lst_iter0(ast_compound_list->ast_list_items, &iter_fn);
}
